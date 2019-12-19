import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.io.IOException;
import java.lang.Math;
import com.leapmotion.leap.*;
import com.leapmotion.leap.Frame;
import javax.swing.*;

class GameRobot extends Robot { // 游戏机器人(GameRobot)接收LeapMotion发来的帧信号，处理之，进行对应的游戏操作
    Robot robot = new Robot();  // 机器人类，用于发出按键和鼠标信号
    boolean mouseControl = false; // 是否为鼠标操作模式
    int[] keys = new int [9]; //keys[0]:手掌左移, 1:手掌右移, 2:手掌前移, 3:手掌后移, 4:手掌上移, 5:手掌下移, 6:握拳, 7:伸食指, 8:伸拇指食指
    float ratiox = 0.33f, ratioy = 0.33f; // 两个方向上手掌速度与鼠标速度比率(ratio)
    float restx = 0.5f, resty = 0.33f, restz = 0.33f; // 三个方向上移动手掌到触发按键需要移动的距离比率（静息参数rest）


    public GameRobot() throws AWTException {

    }

    public void setKey(int idx, int key) {
        // 一些特殊值：4: 鼠标左键, 5: Shift+左键，6: Shift+右键
        keys[idx] = key;
    }
    public void releaseAllKeys() {
        robot.mouseRelease(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK);
        final int[] possibleKeys = {KeyEvent.VK_W, KeyEvent.VK_A, KeyEvent.VK_S, KeyEvent.VK_D,
                KeyEvent.VK_M, KeyEvent.VK_SHIFT, KeyEvent.VK_J, KeyEvent.VK_I, KeyEvent.VK_L,
                KeyEvent.VK_UP, KeyEvent.VK_DOWN, KeyEvent.VK_LEFT, KeyEvent.VK_RIGHT};
        for (int i: possibleKeys) robot.keyRelease(i);
    }
    public void Press(int key) {
        if (key != 0) robot.keyPress(key);
    }
    public void Release(int key) {
        if (key != 0) robot.keyRelease(key);
    }
    public int getRatioX() {return (int)(100 * ratiox);}
    public int getRatioY() {return (int)(100 * ratioy);}
    public int getRestX() {return (int)(100 * restx);}
    public int getRestY() {return (int)(100 * resty);}
    public int getRestZ() {return (int)(100 * restz);}
    public void setRatioX(int val) {ratiox = (float)val / 100;}
    public void setRatioY(int val) {ratioy = (float)val / 100;}
    public void setRestX(int val) {restx = (float)val / 100;}
    public void setRestY(int val) {resty = (float)val / 100;}
    public void setRestZ(int val) {restz = (float)val / 100;}

    private void mouseMove(float vx, float vy) {
        // vx > 0 表示向+x移动，即右移
        // vx < 0 表示向-x移动，即左移
        // vy > 0 表示向+y移动，即上移
        // vy < 0 表示向-y移动，即下移
        Point p = MouseInfo.getPointerInfo().getLocation();
        double curx = p.getX(), cury = p.getY(); // 鼠标当前坐标
        int dx = (int)(vx / 4), dy = (int)(-vy / 4); // 位移像素值（需要仔细调整相关常量）（因为鼠标坐标和手势坐标的y轴是反的，遂取反）
        int endx = (int)curx + dx, endy = (int)cury + dy; // 鼠标目标位置
        robot.mouseMove(endx, endy);
    }

    public void onFrame(Frame frame)
    {
        if (frame.hands().isEmpty()) return;
        //System.out.println("get");
        Hand hand = frame.hands().get(0); // 只需要用到一只手，所以只处理一只手

        // 每收到一帧，都先释放非持续性的按键
        robot.keyRelease(KeyEvent.VK_J); robot.keyRelease(KeyEvent.VK_I); robot.keyRelease(KeyEvent.VK_L);
        robot.mouseRelease(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK);

        // 鼠标：由手掌位置控制
        Vector velocity = hand.palmVelocity();
        float vx = velocity.getX(), vy = velocity.getY();
        final float vthresh = 30; // 常量
        if (mouseControl) {
            float dirx = Math.abs(vx) > vthresh ? vx * ratiox : 0;
            float diry = Math.abs(vy) > vthresh ? vy * ratioy : 0;
            mouseMove(dirx, diry);
        }

        // 方向键：由手掌位置控制
        Vector pos = hand.palmPosition(); // 手掌中心的坐标
        float posx = pos.getX(), posy = pos.getY() - 150, posz = pos.getZ() + 30; // 坐标的三个分量
        // y坐标需要修正，因为手掌的位置总在LeapMotion控制器的上面；z坐标需要修正，因为手掌中心相对手的几何中心总是偏后
        // +x向右，-x向左
        // +y是向上，-y是向下
        // +z是朝用户移动，-z是远离用户
        final float palmPosThresh = 150; // 常量
        //0:手掌左移, 1:手掌右移, 2:手掌前移, 3:手掌后移, 4:手掌上移, 5:手掌下移
        if (!mouseControl) {
            if (posx >  palmPosThresh * restx) Press(keys[1]); else Release(keys[1]);
            if (posx < -palmPosThresh * restx) Press(keys[0]); else Release(keys[0]);
            if (posy >  palmPosThresh * resty) Press(keys[4]); else Release(keys[4]);
            if (posy < -palmPosThresh * resty) Press(keys[5]); else Release(keys[5]);
        }
        if (posz >  palmPosThresh * restz) Press(keys[3]); else Release(keys[3]);
        if (posz < -palmPosThresh * restz) Press(keys[2]); else Release(keys[2]);

        // 非方向键：由手掌动作控制
        int fingers = frame.fingers().extended().count(); // 伸直的手指个数
        float pinchDist = hand.pinchDistance();
        final float pinchDistThresh = 20;
        // keys[6]:握拳, 7:伸食指, 8:伸拇指食指
        if (fingers == 0) { // 握拳
            // 一些特殊值：4: 鼠标左键, 5: Shift+左键，6: Shift+右键
            if (keys[6] == 5 || keys[6] == 6) Press(KeyEvent.VK_SHIFT);
            if (keys[6] != 4 && keys[6] != 5 && keys[6] != 6) Press(keys[6]);
            if (keys[6] == 4 || keys[6] == 5) {robot.mousePress(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON1_MASK);} //鼠标左键
            if (keys[6] == 6) {robot.mousePress(InputEvent.BUTTON3_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK);} //鼠标右键
            robot.mouseRelease(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK); robot.keyRelease(KeyEvent.VK_SHIFT);
            if (keys[6] != 4 && keys[6] != 5 && keys[6] != 6) Release(keys[6]);
        }
        else if (fingers == 1) { // 伸出食指
            if (keys[7] == 5 || keys[7] == 6) Press(KeyEvent.VK_SHIFT);
            if (keys[7] != 4 && keys[7] != 5 && keys[7] != 6) Press(keys[7]);
            if (keys[7] == 4 || keys[7] == 5) {robot.mousePress(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON1_MASK);} //鼠标左键
            if (keys[7] == 6) {robot.mousePress(InputEvent.BUTTON3_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK);} //鼠标右键
            robot.mouseRelease(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK); robot.keyRelease(KeyEvent.VK_SHIFT);
            if (keys[7] != 4 && keys[7] != 5 && keys[7] != 6) Release(keys[7]);
        }
        else if (fingers < 5 && pinchDist > pinchDistThresh) { // 伸出大拇指和食指并张开
            if (keys[8] == 5 || keys[8] == 6) Press(KeyEvent.VK_SHIFT);
            if (keys[8] != 4 && keys[8] != 5 && keys[8] != 6) Press(keys[8]);
            if (keys[8] == 4 || keys[8] == 5) {robot.mousePress(InputEvent.BUTTON1_MASK); } //鼠标左键
            if (keys[8] == 6) {robot.mousePress(InputEvent.BUTTON3_MASK); } //鼠标右键
            robot.mouseRelease(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK); robot.keyRelease(KeyEvent.VK_SHIFT);
            if (keys[8] != 4 && keys[8] != 5 && keys[8] != 6) Release(keys[8]);
        }

        // 每收到一帧，结束后也释放非持续性的按键
        robot.keyRelease(KeyEvent.VK_J); robot.keyRelease(KeyEvent.VK_I); robot.keyRelease(KeyEvent.VK_L);
        robot.mouseRelease(InputEvent.BUTTON1_MASK); robot.mouseRelease(InputEvent.BUTTON3_MASK);

        // 打印真实数据。用于监控程序状态及校正上面各常量值（包括坐标修正值）
        System.out.println("palm position: x = " + posx + ", y = " + posy + ", z = " + posz);
        System.out.println("palm velocity: x = " + vx + ", y = " + vy);
        System.out.println("pinch distance: " + pinchDist);
    }
}

class SampleListener extends Listener {
    GameRobot robot;

    public SampleListener(GameRobot r) {
        robot = r;
    }

    public void onInit(Controller controller) {
        System.out.println("Initialized");
    }

    public void onConnect(Controller controller) {
        System.out.println("Connected");
    }

    public void onDisconnect(Controller controller) {
        //Note: not dispatched when running in a debugger.
        System.out.println("Disconnected");
    }

    public void onExit(Controller controller) {
        System.out.println("Exited");
    }

    public void onFrame(Controller controller) {
        // Get the most recent frame and report some basic information
        Frame frame = controller.frame();
        robot.onFrame(frame);
    }
}

class Sample {
    public static void main(String[] args) throws AWTException {
        // 创建一个游戏机器人
        GameRobot robot = new GameRobot();

        // Create a sample listener and controller
        SampleListener listener = new SampleListener(robot);
        Controller controller = new Controller();

        // 创建窗体
        GameWAVE.create(robot);

        // Have the sample listener receive events from the controller
        controller.addListener(listener);

        // 设定游戏机器人的最小动作间隔为1ms
        robot.setAutoDelay(1);

        System.out.println("Press Enter to quit...");
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Remove the sample listener when done
        controller.removeListener(listener);
    }
}

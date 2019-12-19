import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.*;

class GameWAVE {
    private JComboBox 握拳comboBox;
    private JRadioButton 鼠标RadioButton;
    private JRadioButton wASDRadioButton;
    private JRadioButton 方向键RadioButton;
    private JComboBox 伸拇指食指comboBox;
    private JComboBox 伸食指comboBox;
    private JComboBox 手掌向前向上comboBox;
    private JComboBox 手掌向后向下comboBox;
    private JPanel rootPanel;
    private JLabel 手掌向前向上Label;
    private JLabel 手掌向后向下Label;
    private JSpinner spinner1;
    private JSpinner spinner2;
    private JSpinner zSpinner;
    private JLabel zLabel;
    private static GameRobot robot;
    private boolean mouseControl;

    public GameWAVE() {
        鼠标RadioButton.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                // 一旦更改设置，首先释放所有按键
                robot.releaseAllKeys();
                if (e.getStateChange() == ItemEvent.DESELECTED) { // “鼠标” radio button 被取消选中
                    mouseControl = false;

                    // 显示z方向的灵敏度参数，显示的值改为鼠标类对应的值
                    zSpinner.setVisible(true); zLabel.setVisible(true);
                    spinner1.setValue(robot.getRestX()); spinner2.setValue(robot.getRestY()); zSpinner.setValue(robot.getRestZ());

                    // 则需清空下面附带的两个组合框并更改两个标签的内容
                    手掌向前向上comboBox.setSelectedIndex(1); 手掌向后向下comboBox.setSelectedIndex(1);
                    手掌向前向上comboBox.setSelectedIndex(0); 手掌向后向下comboBox.setSelectedIndex(0);
                    手掌向前向上Label.setText("手掌向上："); 手掌向后向下Label.setText("手掌向下：");

                    // 控制逻辑
                    robot.mouseControl = false;
                }
                else if (e.getStateChange() == ItemEvent.SELECTED) {  // “鼠标” radio button 被选中
                    mouseControl = true;

                    // 也是清空下面附带的两个组合框并更改两个标签的内容
                    手掌向前向上comboBox.setSelectedIndex(1); 手掌向后向下comboBox.setSelectedIndex(1);
                    手掌向前向上comboBox.setSelectedIndex(0); 手掌向后向下comboBox.setSelectedIndex(0); // 会顺带着也设置手掌向前和向后为无动作
                    手掌向前向上Label.setText("手掌向前："); 手掌向后向下Label.setText("手掌向后：");

                    // 隐藏z方向的灵敏度参数，因为鼠标控制下这个方向没有意义
                    zSpinner.setVisible(false); zLabel.setVisible(false);
                    spinner1.setValue(robot.getRatioX()); spinner2.setValue(robot.getRatioY());

                    // 控制逻辑
                    robot.mouseControl = true;
                }
            }
        });
        鼠标RadioButton.setSelected(true); wASDRadioButton.setSelected(true); // 默认刚启动时选中 “W/A/S/D” radio button，以设置合适的窗口大小
        wASDRadioButton.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                robot.releaseAllKeys();
                if (e.getStateChange() == ItemEvent.SELECTED) {  // “W/A/S/D” radio button 被选中
                    // 控制逻辑
                    robot.setKey(0, KeyEvent.VK_A);
                    robot.setKey(1, KeyEvent.VK_D);
                    robot.setKey(2, KeyEvent.VK_W);
                    robot.setKey(3, KeyEvent.VK_S);
                }
            }
        });
        方向键RadioButton.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                robot.releaseAllKeys();
                if (e.getStateChange() == ItemEvent.SELECTED) {  // “方向键” radio button 被选中
                    // 控制逻辑
                    robot.setKey(0, KeyEvent.VK_LEFT);
                    robot.setKey(1, KeyEvent.VK_RIGHT);
                    robot.setKey(2, KeyEvent.VK_UP);
                    robot.setKey(3, KeyEvent.VK_DOWN);
                }
            }
        });


        final int[] persistKeys = {0, KeyEvent.VK_M, KeyEvent.VK_SHIFT}; // 0用来表示无动作
        手掌向前向上comboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                robot.releaseAllKeys();
                int curIndex = 手掌向前向上comboBox.getSelectedIndex(); // 0: 无动作, 1: M, 2: Shift
                if (mouseControl) robot.setKey(2, persistKeys[curIndex]); // 鼠标模式下，该框对应的是手掌向前的动作
                else robot.setKey(4, persistKeys[curIndex]); // 键盘模式下，对应手掌向上的动作
            }
        });
        手掌向后向下comboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                robot.releaseAllKeys();
                int curIndex = 手掌向后向下comboBox.getSelectedIndex(); // 0: 无动作, 1: M, 2: Shift
                if (mouseControl) robot.setKey(3, persistKeys[curIndex]); // 鼠标模式下，该框对应的是手掌向后的动作
                else robot.setKey(5, persistKeys[curIndex]); // 键盘模式下，对应手掌向下的动作
            }
        });

        final int[] actionKeys = {0, KeyEvent.VK_I, KeyEvent.VK_J, KeyEvent.VK_L, 4, 5, 6};
        // 0用来表示无动作, 4表示鼠标左键，5表示Shift+左键，6表示Shift+右键 （4,5和6在本程序中不作为键盘编号使用）
        握拳comboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                robot.releaseAllKeys();
                int curIndex = 握拳comboBox.getSelectedIndex(); // 0: 无动作, 1: I, 2: J, 3: L, 4: 鼠标左键, 5: Shift+左键，6: Shift+右键
                robot.setKey(6, actionKeys[curIndex]);
            }
        });
        伸食指comboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                robot.releaseAllKeys();
                int curIndex = 伸食指comboBox.getSelectedIndex(); // 0: 无动作, 1: I, 2: J, 3: L, 4: 鼠标左键, 5: Shift+左键，6: Shift+右键
                robot.setKey(7, actionKeys[curIndex]);
            }
        });
        伸拇指食指comboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                robot.releaseAllKeys();
                int curIndex = 伸拇指食指comboBox.getSelectedIndex(); // 0: 无动作, 1: I, 2: J, 3: L, 4: 鼠标左键, 5: Shift+左键，6: Shift+右键
                robot.setKey(8, actionKeys[curIndex]);
            }
        });

        spinner1.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                int val = Integer.parseInt(spinner1.getValue().toString());
                if (mouseControl) robot.setRatioX(val);
                else robot.setRestX(val);
            }
        });
        spinner2.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                int val = Integer.parseInt(spinner1.getValue().toString());
                if (mouseControl) robot.setRatioY(val);
                else robot.setRestY(val);
            }
        });
        zSpinner.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                int val = Integer.parseInt(spinner1.getValue().toString());
                robot.setRestZ(val);
            }
        });
    }

    public static void create(GameRobot r) {
        robot = r;
        JFrame frame = new JFrame("MiniGameWAVE");
        frame.setContentPane(new GameWAVE().rootPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}

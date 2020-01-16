import socket
import struct
import json
import time


class tcp_client:
    ip_port = ('127.0.0.1', 8998)
    buffsize = 1024

    def __init__(self):  # 构造函数：建立socket连接
        self.tcp_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.tcp_sock.connect(self.ip_port)

    def __del__(self):  # 析构函数：关闭socket连接
        self.tcp_sock.close()

    def sendrecv(self, string):  # 发送字符串给服务器，然后接收服务器发回的数据并解码
        self.tcp_sock.sendall(string.encode('utf-8'))
        r = self.tcp_sock.recv(self.buffsize).decode('utf-8')
        return r

    def download(self, filename, savename=None):  # 从服务器下载文件名为filename的文件，本地存为文件名savename
        if savename is None:
            savename = filename
        # 发送下载文件请求
        self.tcp_sock.sendall(('0 ' + filename).encode('utf-8'))

        # 接收报头，得到文件大小
        head_len_struct = self.tcp_sock.recv(40)  # 报头长度的结构体
        if not head_len_struct:
            return
        print('[TCP]开始接收文件', filename + (', 保存名为 ' + savename if savename != filename else ''))
        head_len = struct.unpack('i', head_len_struct)[0]  # 报头长度
        head_raw = self.tcp_sock.recv(head_len)  # 报头的json编码
        head = json.loads(head_raw.decode('utf-8'))  # 报头
        filesize = head['filesize']  # 文件大小

        # 接收文件内容
        recv_len = 0
        start_time = time.time()
        fp = open(savename, 'wb')
        while recv_len < filesize:
            recv_cur = self.tcp_sock.recv(min(filesize - recv_len, self.buffsize))
            fp.write(recv_cur)
            recv_len += len(recv_cur)
        fp.close()

        # 输出结束信息
        end_time = time.time()
        print('[TCP]接收长度:', recv_len, ', 文件大小:', filesize, ', 总共用时' + str(end_time - start_time) + '秒')

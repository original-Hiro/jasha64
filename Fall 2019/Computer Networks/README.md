#### 复旦大学2019-2020学年秋季学期

#### Fall 2019, Fudan University

## Computer Networks 计算机网络 (COMP130136.01-02) Course Project

The target of this project is to design an application layer protocol. We had to choose a topic among the given four (see "project.pptx"; the folder "socket_demo" contains the demo code in "project.pptx"), and I chose eReader.

Considering it's a network course, we're not asked to design the frontend independently; as a result, my GUI consists of the two windows from https://github.com/xflywind/PyReadon and https://github.com/finomy/little-txt-reader. Backend (Socket programming), connection between the two windows and connection between UI and backend are my work.

To run this eReader, run the server (NetEBookReader_server/tcp_server.py) before running the client (NetEBookReader/__main\_\_.py). For the layout of this eReader, refer to "report.pdf".
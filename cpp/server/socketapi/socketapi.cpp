#include <iostream>
#include "socketapi.h"
using namespace std;

int main()
{
    cout << "Start socket api server." << endl;
    // 建立套接字，失败返回为 -1
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in addr = { 0 };
    // 指定地址族
    addr.sin_family = AF_INET; 
    // IP初始化
    addr.sin_addr.s_addr = INADDR_ANY;
    // 服务监听端口号初始化
    addr.sin_port = htons(8080);
    cout << "Server Listen 8080." << endl;

    int rc;
    // 分配IP和端口
    rc = bind(sock, (sockaddr*)&addr, sizeof(addr));

    // 设置socket监听
    rc = listen(sock, 0);

    // 设置客户端信息
    sockaddr_in clientAddr;
    int clientAddrSize = sizeof(clientAddr);
    int clientSock;
    // 接受客户端发送的请求
    while (-1 != (clientSock = accept(sock,(sockaddr*)&clientAddr, (socklen_t*)&clientAddrSize)))
    {
        // 接收请求
        string requestStr;
        // 用于存储数据
        int bufSize = 4096;
        requestStr.resize(bufSize); 
        // 接收数据
        recv(clientSock, &requestStr[0], bufSize, 0);

        //取得第一行
        string firstLine = requestStr.substr(0, requestStr.find("\r\n"));
        //取得URL
        // substr，复制函数，参数为起始位置（默认0），复制的字符数目
        firstLine = firstLine.substr(firstLine.find(" ") + 1);
        // find返回找到的第一个匹配字符串的位置，而不管其后是否还有相匹配的字符串
        string url = firstLine.substr(0, firstLine.find(" "));

        //发送响应头
        string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html; charset=gbk\r\n"
            "Connection: close\r\n"
            "\r\n";
        
            // 发送
        send(clientSock, response.c_str(), response.length(), 0);
        // router逻辑处理
        Router(clientSock, url);
        // 关闭客户端套接字
        close(clientSock);
    }
    close(sock);//关闭服务器套接字
    return 0;
}
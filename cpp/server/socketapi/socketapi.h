#if defined(_MSC_VER) || defined(__MINGW32__) || defined(WIN32)
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include <string>
#include <iostream>
#define close closesocket


class WinSockInit
{
    WSADATA _wsa;
public:
    WinSockInit()
    {  //分配套接字版本信息2.0，WSADATA变量地址
        WSAStartup(MAKEWORD(2, 0), &_wsa); 

    }
    ~WinSockInit()
    {
        WSACleanup();//功能是终止Winsock 2 DLL (Ws2_32.dll) 的使用
    }
}; 

#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

using namespace std;
void Router(int clientSock, string const & url);
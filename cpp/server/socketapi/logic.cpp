#include <iostream>
#include "socketapi.h"

// Router 定义路由处理相关逻辑
void Router(int clientSock, string const & url)
{
    string hint;
    if (url == "/")
    {
        cout << url << "\nRecieve msg\n";
        hint = "This is ooz-home.";
        send(clientSock, hint.c_str(), hint.length(), 0);
    }
    else if (url == "/login")
    {
        cout << url << "\nRecieve msg\n";
        hint = "This is ooz-login.";
        send(clientSock, hint.c_str(), hint.length(), 0);
    }
    else
    {
        cout << url << "\nRecieve msg\n";
        hint = "Not Found!";
        send(clientSock, hint.c_str(), hint.length(), 0);
    }
}
#include "Sphinx_socket.h"

sphinx::error::SphinxStatus 
sphinx::Socket::SphinxSocket::CreateSocket()
{
    sphinx::error::SphinxStatus status;

    socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socketFd < 0)
        status = sphinx::error::SphinxErrorSocketCreateFailed();
    else
        status = sphinx::error::SphinxOK();

    return status;
}

sphinx::error::SphinxStatus 
sphinx::Socket::SphinxSocket::BindSocket()
{
    sockaddr_in hostAddr {};

    hostAddr.sin_family = AF_INET;
    hostAddr.sin_port = htons(SPHINX_PORT);
    hostAddr.sin_addr.s_addr = 0;

    if(bind(socketFd, reinterpret_cast<sockaddr*>(&hostAddr), sizeof(hostAddr)) < 0);
        return sphinx::error::SphinxErrorSocketBindFailed();
}

sphinx::error::SphinxStatus
sphinx::Socket::SphinxSocket::ListenSocket()
{
    if(listen(socketFd, 5) < 0)
        return sphinx::error::SphinxErrorSocketListenFailed();
}

sphinx::error::SphinxStatus 
sphinx::Socket::SphinxSocket::Open()
{
    sphinx::error::SphinxStatus status;

    status = CreateSocket();
    status << "Failed to create Socket!!\n";
    if(!IS_SPHINX_CLASS_OK(status))
        return status;

    status = BindSocket();
    status << "Failed to bind Socket!!\n";
    if(!IS_SPHINX_CLASS_OK(status))
        return status;
}

sphinx::error::SphinxStatus
sphinx::Socket::SphinxSocket::Close()
{

}
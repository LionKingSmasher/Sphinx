#ifndef __SPHINX_SOCKET_H__
#define __SPHINX_SOCKET_H__

#include "Sphinx_error.h"

#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SPHINX_LOCAL_IP 0
#define SPHINX_PORT     8282

namespace sphinx
{


namespace Socket
{


class SphinxSocket
{
private:
    int socketFd; // socket
    int clientFd;
public:
private:
    sphinx::error::SphinxStatus 
    CreateSocket();

    sphinx::error::SphinxStatus 
    BindSocket();

    sphinx::error::SphinxStatus
    ListenSocket();

public:
    sphinx::error::SphinxStatus 
    Open();

    sphinx::error::SphinxStatus 
    Close();
};


}


}

#endif
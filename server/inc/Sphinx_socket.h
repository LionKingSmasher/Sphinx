#ifndef __SPHINX_SOCKET_H__
#define __SPHINX_SOCKET_H__

#include "Sphinx_error.h"

#include <vector>

#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SPHINX_LOCAL_IP 0
#define SPHINX_PORT     8282

namespace sphinx
{


namespace Socket
{

struct SphinxFDServerNClient
{
    int socketFd;
    int clientFd;
};

class SphinxSocket
{
private:
    SphinxFDServerNClient fd;
    std::vector<SphinxFDServerNClient> fdVector;
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

    virtual
    sphinx::error::SphinxStatus
    Run() = 0;

    sphinx::error::SphinxStatus 
    Close();
};


}


}

#endif
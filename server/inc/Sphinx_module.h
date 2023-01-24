#ifndef __Sphinx_MODULE_H__
#define __Sphinx_MODULE_H__

#include "Sphinx_socket.h"
#include "Sphinx_error.h"

#include <dlfcn.h>

#include <string>
#include <unordered_map>

typedef int (*Sphinx_MODULE_MAIN)(int, char**);
typedef void* DLHANDLE;

namespace sphinx
{

namespace module
{

class SphinxModuleServer : public Socket::SphinxSocket
{
    // Private Instance
    std::unordered_map<DLHANDLE, Sphinx_MODULE_MAIN> dlMap;
public:
    // Public Instatnce
private:
    // Private Method
    std::string 
    GetSymError(DLHANDLE dlHandle);
public:
    // Public Method

    ~SphinxModuleServer();

    sphinx::error::SphinxStatus
    Run()
    override;

    sphinx::error::SphinxStatus
    Start();

    sphinx::error::SphinxStatus
    Stop();

    sphinx::error::SphinxStatus
    Commit(std::string&& moduleName);
};


}

}

#endif
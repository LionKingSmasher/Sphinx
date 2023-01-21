#ifndef __Sphinx_MODULE_H__
#define __Sphinx_MODULE_H__

#include "Sphinx_error.h"

#include <dlfcn.h>

#include <string>
#include <unordered_map>

typedef int (*Sphinx_MODULE_MAIN)(int, char**);
typedef void* DLHANDLE;

namespace Sphinx
{

namespace module
{

class SphinxModuleServer
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

    Sphinx::error::SphinxStatus
    Start();

    Sphinx::error::SphinxStatus
    Stop();

    Sphinx::error::SphinxStatus
    Commit(std::string&& moduleName);
};


}

}

#endif
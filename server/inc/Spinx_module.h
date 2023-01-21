#ifndef __SPINX_MODULE_H__
#define __SPINX_MODULE_H__

#include "Spinx_error.h"

#include <dlfcn.h>

#include <string>
#include <unordered_map>

typedef int (*SPINX_MODULE_MAIN)(int, char**);
typedef void* DLHANDLE;

namespace spinx
{

namespace module
{

class SpinxModuleServer
{
    // Private Instance
    std::unordered_map<DLHANDLE, SPINX_MODULE_MAIN> dlMap;
public:
    // Public Instatnce
private:
    // Private Method
    std::string 
    GetSymError(DLHANDLE dlHandle);
public:
    // Public Method

    ~SpinxModuleServer();

    spinx::error::SpinxStatus
    Start();

    spinx::error::SpinxStatus
    Stop();

    spinx::error::SpinxStatus
    Commit(std::string&& moduleName);
};


}

}

#endif
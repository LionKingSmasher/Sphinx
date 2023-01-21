#ifndef __SPINX_MODULE_H__
#define __SPINX_MODULE_H__

#include "Spinx_error.h"

#include <dlfcn.h>

#include <string>

typedef int (*SPINX_MODULE_MAIN)(int, char**);
typedef void* DLHANDLE;

namespace spinx
{

namespace module
{

class SpinxModuleServer
{
    // Private Instance
    DLHANDLE dlHandle;
    SPINX_MODULE_MAIN moduleFn;
public:
    // Public Instatnce
private:
    // Private Method
    std::string GetSymError(void);
public:
    // Public Method
    spinx::error::SpinxStatus
    Commit();
};


}

}

#endif
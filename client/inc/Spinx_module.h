#ifndef __SPINX_MODULE_H__
#define __SPINX_MODULE_H__

#include "Spinx_error.h"

#include <dlfcn.h>

#include <string>
#include <coroutine>

typedef int (*SPINX_MODULE_MAIN)(int, char**);
typedef void* DLHANDLE;

namespace spinx
{

namespace module
{

class SpinxModule
{
    DLHANDLE dlHandle;
    SPINX_MODULE_MAIN moduleFn;
public:

private:
    std::string GetSymError(void);
};


}

}

#endif
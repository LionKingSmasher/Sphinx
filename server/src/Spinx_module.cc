#include "Spinx_module.h"

std::string 
spinx::module::SpinxModuleServer::PrintSymError(DLHANDLE dlHandle)
{   
    return std::string(dlerror());
}

spinx::module::SpinxModuleServer::~SpinxModuleServer()
{
    for(auto it = dlMap.begin(); it != dlMap.end(); it++)
    {
        if(dlclose(it->first) != 0)
            GetSymError(it->first);
    }
}

spinx::error::SpinxStatus
spinx::module::SpinxModuleServer::Commit(std::string&& moduleName)
{
    DLHANDLE dlHandle = nullptr;
    SPINX_MODULE_MAIN moduleMain = nullptr;

    dlHandle = dlopen(moduleName.c_str(), RTLD_LAZY);

    if(dlHandle == nullptr)
        return spinx::error::SpinxErrorNullPtr("Failed to get dynamic library handle!");
    
    moduleMain = reinterpret_cast<SPINX_MODULE_MAIN>(dlsym(dlHandle, "SpinxModuleMain"));
    
    return spinx::error::SpinxOK();
}
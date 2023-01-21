#include "Spinx_module.h"

std::string 
spinx::module::SpinxModuleServer::GetSymError(void)
{
    if(dlHandle != nullptr) 
        return "";
    
    return std::string(dlerror());
}

spinx::error::SpinxStatus
spinx::module::SpinxModuleServer::Commit()
{
    return spinx::error::SpinxOK();
}
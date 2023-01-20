#include "Spinx_module.h"

std::string spinx::module::SpinxModule::GetSymError(void)
{
    if(dlHandle != nullptr) 
        return "";
    
    return std::string(dlerror());
}
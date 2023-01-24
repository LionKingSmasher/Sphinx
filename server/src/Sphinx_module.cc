#include "Sphinx_module.h"

std::string 
sphinx::module::SphinxModuleServer::GetSymError(DLHANDLE dlHandle)
{   
    return std::string(dlerror());
}

sphinx::module::SphinxModuleServer::~SphinxModuleServer()
{
    for(auto it = dlMap.begin(); it != dlMap.end(); it++)
    {
        if(dlclose(it->first) != 0)
            GetSymError(it->first);
    }
}

sphinx::error::SphinxStatus
sphinx::module::SphinxModuleServer::Start()
{
    
}


sphinx::error::SphinxStatus
sphinx::module::SphinxModuleServer::Commit(std::string&& moduleName)
{
    DLHANDLE dlHandle = nullptr;
    Sphinx_MODULE_MAIN moduleMain = nullptr;

    dlHandle = dlopen(moduleName.c_str(), RTLD_LAZY);

    if(dlHandle == nullptr)
        return sphinx::error::SphinxErrorNullPtr();
    
    moduleMain = reinterpret_cast<Sphinx_MODULE_MAIN>(dlsym(dlHandle, "SphinxModuleMain"));
    
    return sphinx::error::SphinxOK();
}
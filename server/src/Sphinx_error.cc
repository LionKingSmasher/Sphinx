#include "Sphinx_error.h"

std::ostream& SpinxNullStream()
{
    static std::ofstream os;
    if(!os.is_open())
        os.open("/dev/null", std::ofstream::out | std::ofstream::app);
    return os;
}

[[nodiscard]]
sphinx::error::SphinxStatus 
sphinx::error::SphinxOK(void)
{
    return SphinxStatus(sphinx::error::SphinxErrorCode::SPHINX_OK);
}

[[nodiscard]]
sphinx::error::SphinxStatus
sphinx::error::SphinxError(void)
{
    return SphinxStatus(sphinx::error::SphinxErrorCode::SPHINX_ERROR);
}

[[nodiscard]]
sphinx::error::SphinxStatus
sphinx::error::SphinxErrorNullPtr(void)
{
    return SphinxStatus(sphinx::error::SphinxErrorCode::SPHINX_ERROR_NULL_PTR);
}

[[nodiscard]]
sphinx::error::SphinxStatus
sphinx::error::SphinxErrorSocketCreateFailed(void)
{
    return SphinxStatus(sphinx::error::SphinxErrorCode::SPHINX_ERROR_SOCKET_CREATE_FAILED);
}

[[nodiscard]]
sphinx::error::SphinxStatus
sphinx::error::SphinxErrorSocketBindFailed(void)
{
    return SphinxStatus(sphinx::error::SphinxErrorCode::SPHINX_ERROR_SOCKET_BIND_FAILED);
}

[[nodiscard]]
sphinx::error::SphinxStatus
sphinx::error::SphinxErrorSocketListenFailed()
{
    return SphinxStatus(sphinx::error::SphinxErrorCode::SPHINX_ERROR_SOCKET_LISTEN_FAILED);
}

std::ostream&
sphinx::error::SphinxStatus::operator<<(std::string&& str)
{
    static std::ostream& os = std::cout;
    static std::ostream& null = SphinxNullStream();
    if(IS_SPHINX_OK(sphinxErrorCode))
        return null;
    else
        return os << "!--- ";
}
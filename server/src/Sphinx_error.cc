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

std::ostream&
sphinx::error::SphinxStatus::operator<<(std::string&& str)
{
    std::ostream& os = std::cout;
    std::ostream& null = SphinxNullStream();
    if(IS_SPHINX_OK(sphinxErrorCode))
        return null;
    else
        return os;
}
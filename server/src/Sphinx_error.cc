#include "Sphinx_error.h"

[[nodiscard]]
Sphinx::error::SphinxStatus 
Sphinx::error::SphinxOK(void)
{
    return SphinxStatus("", Sphinx::error::SphinxErrorCode::Sphinx_OK);
}

[[nodiscard]]
Sphinx::error::SphinxStatus
Sphinx::error::SphinxError(std::string errorMsg)
{
    return SphinxStatus(errorMsg, Sphinx::error::SphinxErrorCode::Sphinx_ERROR);
}

[[nodiscard]]
Sphinx::error::SphinxStatus
Sphinx::error::SphinxErrorNullPtr(std::string errorMsg)
{
    return SphinxStatus(errorMsg, Sphinx::error::SphinxErrorCode::Sphinx_ERROR_NULL_PTR);
}
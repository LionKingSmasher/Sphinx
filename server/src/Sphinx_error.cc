#include "Sphinx_error.h"

[[nodiscard]]
sphinx::error::SphinxStatus 
sphinx::error::SphinxOK(void)
{
    return SphinxStatus("", sphinx::error::SphinxErrorCode::Sphinx_OK);
}

[[nodiscard]]
sphinx::error::SphinxStatus
sphinx::error::SphinxError(std::string errorMsg)
{
    return SphinxStatus(errorMsg, sphinx::error::SphinxErrorCode::Sphinx_ERROR);
}

[[nodiscard]]
sphinx::error::SphinxStatus
sphinx::error::SphinxErrorNullPtr(std::string errorMsg)
{
    return SphinxStatus(errorMsg, sphinx::error::SphinxErrorCode::Sphinx_ERROR_NULL_PTR);
}
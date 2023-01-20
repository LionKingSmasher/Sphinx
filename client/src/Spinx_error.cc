#include "Spinx_error.h"

[[nodiscard]]
spinx::error::SpinxStatus 
spinx::error::SpinxOK(void)
{
    return SpinxStatus("", spinx::error::SpinxErrorCode::SPINX_OK);
}

[[nodiscard]]
spinx::error::SpinxStatus
spinx::error::SpinxError(std::string errorMsg)
{
    return SpinxStatus(errorMsg, spinx::error::SpinxErrorCode::SPINX_ERROR);
}

[[nodiscard]]
spinx::error::SpinxStatus
spinx::error::SpinxErrorNullPtr(std::string errorMsg)
{
    return SpinxStatus(errorMsg, spinx::error::SpinxErrorCode::SPINX_ERROR_NULL_PTR);
}
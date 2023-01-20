#ifndef __SPINX_ERROR_H__
#define __SPINX_ERROR_H__

#include <string>

namespace spinx
{

namespace error
{

enum class SpinxErrorCode : int
{
    SPINX_OK,
    SPINX_ERROR,
    SPINX_ERROR_NULL_PTR
};

class SpinxStatus
{
public:
    std::string spinxErrorMsg;
    SpinxErrorCode spinxErrorCode;
private:
public:
    SpinxStatus(std::string errorMsg, SpinxErrorCode errorCode) : spinxErrorMsg(errorMsg), spinxErrorCode(errorCode) {}
};

SpinxStatus SpinxOK(void);
SpinxStatus SpinxError(std::string errorMsg);
SpinxStatus SpinxErrorNullPtr(std::string errorMsg);

}

}

#endif
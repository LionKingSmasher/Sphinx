#ifndef __Sphinx_ERROR_H__
#define __Sphinx_ERROR_H__

#include <string>

namespace Sphinx
{

namespace error
{

enum class SphinxErrorCode : int
{
    Sphinx_OK,
    Sphinx_ERROR,
    Sphinx_ERROR_NULL_PTR
};

class SphinxStatus
{
public:
    std::string SphinxErrorMsg;
    SphinxErrorCode SphinxErrorCode;
private:
public:
    SphinxStatus(std::string errorMsg, SphinxErrorCode errorCode) : SphinxErrorMsg(errorMsg), SphinxErrorCode(errorCode) {}
};

SphinxStatus SphinxOK(void);
SphinxStatus SphinxError(std::string errorMsg);
SphinxStatus SphinxErrorNullPtr(std::string errorMsg);

}

}

#endif
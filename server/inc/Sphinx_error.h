#ifndef __Sphinx_ERROR_H__
#define __Sphinx_ERROR_H__

#include <string>

namespace sphinx
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
    SphinxErrorCode sphinxErrorCode;
private:
public:
    SphinxStatus(std::string errorMsg, SphinxErrorCode errorCode) : SphinxErrorMsg(errorMsg), sphinxErrorCode(errorCode) {}
};

SphinxStatus SphinxOK(void);
SphinxStatus SphinxError(std::string errorMsg);
SphinxStatus SphinxErrorNullPtr(std::string errorMsg);

}

}

#endif
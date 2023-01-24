#ifndef __Sphinx_ERROR_H__
#define __Sphinx_ERROR_H__

#include <iostream>
#include <fstream>
#include <string>

#define IS_SPHINX_CLASS_OK(a1) (a1.sphinxErrorCode == sphinx::error::SphinxErrorCode::SPHINX_OK)
#define IS_SPHINX_OK(a1) (a1 == sphinx::error::SphinxErrorCode::SPHINX_OK)

namespace sphinx
{

namespace error
{

enum class SphinxErrorCode : int
{
    SPHINX_OK,
    SPHINX_ERROR,
    SPHINX_ERROR_NULL_PTR,
    SPHINX_ERROR_SOCKET_CREATE_FAILED,
    SPHINX_ERROR_SOCKET_BIND_FAILED,
    SPHINX_ERROR_SOCKET_LISTEN_FAILED
};

class SphinxStatus
{
private:
public:
    SphinxErrorCode sphinxErrorCode;
private:
public:
    SphinxStatus(SphinxErrorCode errorCode = SphinxErrorCode::SPHINX_OK) : sphinxErrorCode(errorCode) {}
    std::ostream& operator<<(std::string&&);
};

std::ostream& 
SphinxNullStream();

SphinxStatus 
SphinxOK(void);

SphinxStatus 
SphinxError(void);

SphinxStatus 
SphinxErrorNullPtr(void);

SphinxStatus
SphinxErrorSocketCreateFailed(void);

SphinxStatus 
SphinxErrorSocketBindFailed(void);

SphinxStatus
SphinxErrorSocketListenFailed(void);

}

}

#endif
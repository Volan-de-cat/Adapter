
#include <iostream>
#include <exception>

#include "ReadWrite.h"

ReadWrite::ReadWrite(std::unique_ptr<ICrypto> crypto, const std::string& fileName, int mode)
    : _mCrypto(std::move(crypto))
    , _mFile()
{
    _mFile.open(fileName, mode);
}
ReadWrite::~ReadWrite()
{
    if (_mFile)
    {
        _mFile.close();
    }
}

std::string ReadWrite::ReadString(const std::string key)
{
    std::string read = "";
    if (_mFile)
    {
        std::string str;
        getline(_mFile, str);
        if (!str.empty())
        {
            read = _mCrypto->decrypt(str, key);
        }
    }
    else
    {
        throw std::exception("File not open");
    }

    return read;
}

void ReadWrite::WriteString(std::string str, const std::string key)
{
    if (_mFile.is_open())
    {
        _mFile << _mCrypto->encrypt(str, key) << std::endl;
    }
    else 
    {
        throw std::exception("File not open");
    }
}
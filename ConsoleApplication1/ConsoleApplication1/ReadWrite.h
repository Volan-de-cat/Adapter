#pragma once

#include "ICrypto.h"
#include <string>
#include <fstream>

class ReadWrite final
{
public:
	ReadWrite(std::unique_ptr<ICrypto> crypto, const std::string& fileName, int mode);
	~ReadWrite();

	std::string ReadString(const std::string key);
	void WriteString(std::string str, const std::string key);

private:

	const std::unique_ptr<ICrypto> _mCrypto;
	std::fstream _mFile;
};


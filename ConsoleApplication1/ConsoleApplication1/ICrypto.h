#pragma once
#include <string>
class ICrypto
{
public:

	virtual std::string encrypt(const std::string data, const std::string key) const = 0;
	virtual std::string decrypt(const std::string data, const std::string key) const = 0;
};


#pragma once
#include "ICrypto.h"

class XorCrypto final : public ICrypto
{
public:

	XorCrypto() = default;
	~XorCrypto() = default;

	virtual std::string encrypt(const std::string data, const std::string key) const override;
	virtual std::string decrypt(const std::string data, const std::string key) const override;
};
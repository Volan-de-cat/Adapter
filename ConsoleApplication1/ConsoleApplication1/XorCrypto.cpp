#include <string>
#include <iostream>
#include <exception>
#include "XorCrypto.h"

std::string XorCrypto::encrypt(const std::string data, const std::string key) const
{
	if (data.empty() || key.empty())
	{
		throw std::exception("Invalide argument");
	}

	const size_t encryptedLen = ((data.length() + 1) / key.length()
		+ (0 != (data.length() + 1) % key.length())) * key.length();
	std::string encrypted(encryptedLen, 0);

	for (size_t i = 0; i < data.length(); i++)
	{
		encrypted[i] = data[i] ^ key[i % key.length()];
	}

	size_t offset = 1;
	for (size_t i = data.length(); i < encryptedLen; i++)
	{
		encrypted[i] = offset++ ^ key[i % key.length()];
	}

	return encrypted;
}
std::string XorCrypto::decrypt(const std::string data, const std::string key) const
{
	if (data.empty() || key.empty() || data.length() % key.length())
	{
		throw std::exception("Invalide argument");
	}

	size_t decryptedLen = data.length() - (data[data.length() - 1] ^ key[(data.length() - 1) % key.length()]);
	std::string decrypted(decryptedLen, 0);

	for (size_t i = 0; i < decryptedLen; i++)
	{
		decrypted[i] = data[i] ^ key[i % key.length()];
	}

	return decrypted;
}
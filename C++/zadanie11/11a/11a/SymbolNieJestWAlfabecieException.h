#pragma once

#include <exception>

using namespace std;

// Wlasny wyjatek rzucany wtedy kiedy symbol nie jest w alfabecie
class SymbolNieJestWAlfabecieException : public exception
{
public:
	// komunikat wyjatku
	virtual const char* what() const throw()
	{
		return "Symbol nie znajduje sie z alfabecie!";
	}
};
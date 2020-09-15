//writes C code from tokens

#ifndef CWriter_h
#define CWriter_h

#include "Tokens.h"

#include <string>
#include <vector>

namespace CGen
{
	//makes C code from CGen tokens
	std::string CGen(std::vector<Token>& tokens);
}

#endif
//defines the C tokens

#ifndef Tokens_h
#define Tokens_h

#include <string>

namespace CGen
{
	enum class TokenType
	{
		None = 0, //holds no specific data

		StringData, //data between quotes expects does not expect quotes but does check
		NumberData, //any numbers

		DataType, //stores the C data type

		//Function, //stores a function prototype
		ControlFlow, //gens control flow structures

		//specal operators

		Operator, //stores C operators
		Indentifier, //identifiers

		//tells what files to include, don't add quotes to it
		IncludeQuote, //#include ""
		IncludeBracket, //#include <>

		NewLine, //forces a new line
		Space, //forces a space

		TokenCount //the number of tokens
	};

	struct Token
	{
		TokenType type = TokenType::None;
		std::string data = "";
	};
}

#endif
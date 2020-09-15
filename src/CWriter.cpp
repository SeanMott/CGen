#include "CWriter.h"

#include <memory>

using namespace std;

string CGen::CGen(vector<Token>& tokens)
{
	string cCode;

	for (uint32_t i = 0; i < tokens.size(); i++)
	{
		//writes includes
		if (tokens[i].type == TokenType::IncludeBracket)
		{
			cCode += "#include <";
			cCode += tokens[i].data;
			cCode += ">\n";
		}
		else if (tokens[i].type == TokenType::IncludeQuote)
		{
			cCode += "#include \"";
			cCode += tokens[i].data;
			cCode += "\"\n";
		}

		//writes data type
		else if (tokens[i].type == TokenType::DataType)
		{
			cCode += tokens[i].data;
			cCode += ' ';
		}

		//writes operators
		else if (tokens[i].type == TokenType::Operator)
		{
			cCode += tokens[i].data;

			if (tokens[i].data == ";" || tokens[i].data == "{" || tokens[i].data == "}")
				cCode += '\n';
			else if (tokens[i].data == "," || tokens[i].data == "-" || tokens[i].data == "+" || tokens[i].data == "*" || tokens[i].data == "/")
				cCode += ' ';
		}

		//writes identifiers
		else if (tokens[i].type == TokenType::Indentifier)
			cCode += tokens[i].data;

		//control flow
		else if (tokens[i].type == TokenType::ControlFlow)
		{
			//if || else || if else

			//other
			cCode += tokens[i].data;
			cCode += ' ';
		}

		//writes string data
		else if (tokens[i].type == TokenType::StringData)
		{
			//adds quote is none is found
			if (tokens[i].data[0] != '"')
				cCode += '"';
			else if (tokens[i].data[0] != '\'')
				cCode += '\'';

			cCode += tokens[i].data;

			//adds quote is none is found
			if (tokens[i].data[tokens[i].data.length() - 1] != '"')
				cCode += '"';
			else if (tokens[i].data[tokens[i].data.length() - 1] != '\'')
				cCode += '\'';
		}

		//writes number data
		else if (tokens[i].type == TokenType::NumberData)
			cCode += tokens[i].data;

		//writes new line
		else if (tokens[i].type == TokenType::NewLine)
			cCode += '\n';

		//writes space
		else if (tokens[i].type == TokenType::Space)
			cCode += ' ';
	}

	//for now return the hello example
	return cCode; //return "#include <stdio.h>\nint main(int args, char* argv[])\n{\nprintf(\"Hello CGen!\");\n}";
}

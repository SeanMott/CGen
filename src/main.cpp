/*
CGen allows for C code to be produced and then compiled.
CGen comes as a lib this main file is just to test Tokens into C code.
For right now it uses Clang and a path has to be given to were Clang is.
If no Clang is provided it will use a version that comes with CGen.

Github Link: 

Created by Sean R. Mott || 09/14/2020

*/

#include "Compile.h"
#include "CWriter.h"
#include "ArgEngine.h"

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int args, char* argv[])
{
	//call Arg engine and pass arguments
	const char* arguments[] = { "-name", "HelloCGen", "-out", "exe", "-run", "true" };
	
	CGen::ArgEngine::Init(6, arguments);

	//pass tokens for testing
	vector<CGen::Token> tokens = {
		
		//includes
		{CGen::TokenType::IncludeBracket, "stdio.h"},

		//holds the hello CGen string
		{CGen::TokenType::DataType, "char*"},
		{CGen::TokenType::Indentifier, "text"},
		{CGen::TokenType::Space, ""},
		{CGen::TokenType::Operator, "="},
		{CGen::TokenType::Space, ""},
		{CGen::TokenType::StringData, "Hello CGen!\\nThis is a string made with CGen!\\n"},
		{CGen::TokenType::Operator, ";"},

		//makes the main function
		{CGen::TokenType::DataType, "int"},
		{CGen::TokenType::Indentifier, "main"},
		{CGen::TokenType::Operator, "("},
		{CGen::TokenType::DataType, "int"},
		{CGen::TokenType::Indentifier, "args"},
		{CGen::TokenType::Operator, ","},
		{CGen::TokenType::DataType, "char*"},
		{CGen::TokenType::Indentifier, "argv[]"},
		{CGen::TokenType::Operator, ")"},
		{CGen::TokenType::NewLine, ""},
		{CGen::TokenType::Operator, "{"},

		//makes a call to the built in print function
		{CGen::TokenType::Indentifier, "printf"},
		{CGen::TokenType::Operator, "("},
		{CGen::TokenType::StringData, "%s\\n"},
		{CGen::TokenType::Operator, ","},
		{CGen::TokenType::Indentifier, "text"},
		{CGen::TokenType::Operator, ")"},
		{CGen::TokenType::Operator, ";"},

		//returns 0
		{CGen::TokenType::ControlFlow, "return"},
		{CGen::TokenType::NumberData, "0"},
		{CGen::TokenType::Operator, ";"},

		//finishs main
		{CGen::TokenType::Operator, "}"}
	};

	//parse Tokens into C code and compile
	CGen::Compile(CGen::CGen(tokens));
	
	cin.get();
	return 0;
}
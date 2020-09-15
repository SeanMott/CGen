//compiles C code

#ifndef Compile_h
#define Compile_h

#include <string>

namespace CGen
{
	//compiles C code || returns false if it was unable to compile
	bool Compile(const std::string& code);
}

#endif
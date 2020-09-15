#include "Compile.h"

#include "ArgEngine.h"

#include <fstream>

using namespace std;

bool CGen::Compile(const string& code)
{
	//debug data
	string path = ArgEngine::ProgName() + ".c";

	if (code == "")
	{
		printf("ERROR: CGen Compile || Failed to compile no C code was provided.\n");
		return false;
	}

	//writes file || add path for temp file
	ofstream writeStream(path/*ArgEngine::GetTempPath()*/);
	if (!writeStream.is_open())
	{
		printf("ERROR: CGen File Write || Failed to write C file to %s\nCheck filepath arg passed to Arg Engine.\n", path.c_str());
		return false;
	}
	writeStream << code;
	writeStream.close();

	//call Clang and pass args || add optimization, build path, temp build path, add Clang path but later
	system(string("Clang -o " + ArgEngine::ProgName() + ArgEngine::OutputFileType() + ' ' + ArgEngine::ProgName() + ".c").c_str());
	//system(string("Clang -o " + name + filetype + ' ' + name + ".c").c_str());
	if (ArgEngine::RunProg())
		system(string(ArgEngine::ProgName() + ArgEngine::OutputFileType()).c_str());
		//system(string(name + ".exe").c_str());

	return true;
}

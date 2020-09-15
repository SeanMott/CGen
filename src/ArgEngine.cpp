#include "ArgEngine.h"

#include <memory>

using namespace std;

string CGen::ArgEngine::progName = "Prog", CGen::ArgEngine::outputFileType = ".exe";
bool CGen::ArgEngine::runProg = true;

bool CGen::ArgEngine::Init(int args, const char* argv[])
{
	if (args < 2)
	{
		printf("WARNING: CGen Args || No arguments were given to the Arg Engine defaults will be used.\nArg flags can be found at Github or other docs. Call a CGen executable with -git-url or -help to find the flags.\n");
		return false;
	}

	//process argument flags
	for (uint32_t i = 0; i < args; i++)
	{
		//displays help
		if (argv[i] == "-help" || argv[i] == "-h")
		{
			printf("Help Data\n");
			return false;
		}

		//gets git link
		else if (argv[i] == "-git" || argv[i] == "-g")
		{
			printf("Git Repo Link: https://github.com/SeanMott/CGen.git\n");
			return false;
		}

		//gets github URL
		else if (argv[i] == "-git-url" || argv[i] == "-url")
		{
			printf("Git URL: https://github.com/SeanMott/CGen\n");
			return false;
		}

		//sets the program name
		else if (argv[i] == "-name" || argv[i] == "-n")
		{
			i++;
			progName = string(argv[i]);
		}

		//sets the program out put type
		else if (argv[i] == "-out" || argv[i] == "-o")
		{
			i++;
			outputFileType = '.';
			outputFileType += argv[i];
		}

		//sets if the program will be ran after compiling
		else if (argv[i] == "-run" || argv[i] == "-r")
		{
			i++;
			runProg = (argv[i] == "true" ? true : false);
		}

		//invalid flag
		else
			printf("WARNING: CGen Args || %s is not a valid flag, check order of args passed.\nArg flags can be found at Github or other docs. Call a CGen executable with -git-url or -help to find the flags.\n", argv[i]);
	}

	return true;
}
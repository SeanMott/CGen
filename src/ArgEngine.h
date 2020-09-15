//handles arguments passed to CGen

#ifndef ArgEngine_h
#define ArgEngine_h

#include <string>

namespace CGen
{
	class ArgEngine
	{
		//vars
	private:

		static std::string progName, outputFileType;
		static bool runProg;

		//methods
	public:

		//inits the arg engine || returns false if -help or -git were passed in
		static bool Init(int args, const char* argv[]);

		//gets the program name
		static inline std::string ProgName() { return progName; }
		//gets output file type
		static inline std::string OutputFileType() { return outputFileType; }
		//gets if the program should be ran after compiling
		static inline bool RunProg() { return runProg; }
	};
}

#endif
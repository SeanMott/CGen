# CGen
CGen allows for C code to be produced and then compiled from Tokens.

CGen only requires a vector of tokens to be passed to the CGen method and it returns C code as a string. Pass that into the Compile method and it will place a C file where ever the temp directory was set through the Arg Engine and then it will be compiled.

A main file is included that shows what a hello world program would look like in CGen. CGen can just be compiled as a lib and linked to.

Clang is needed for CGen so one will have to be placed next to the executable that links CGen or CGen itself. This is untill a Clang path can be added to the Arg Engine.

# Arg Flags

The Arg Engine will abort once it hits any of theses flags. Theses flags should be passed to a executable version of CGen but they can be passed when called as a lib.

- -help || shows all the args that can be passed to the Arg Engine
- -h || shows all the args that can be passed to the Arg Engine

- -git || shows the link to be used when cloning the git repo
- -g || shows the link to be used when cloning the git repo

- -git-url || shows the web url for the github
- -url || shows the web url for the github

Theses flags can be hit and will not abort

- -name || -name "name" || sets the name of the program if not given the name defaults to Prog
- -n || -n "name" || sets the name of the program if not given the name defaults to Prog

- -out || -out "exe" || sets the output file type if not given it will default to exe
- -o || -o "exe" || sets the output file type if not given it will default to exe

- -run || -run "true" || sets if the program should run after compiling, if not given it will by default
- -r || -r "true" || sets if the program should run after compiling, if not given it will by default

# Building
CGen uses Premake and a project file is given with the source.

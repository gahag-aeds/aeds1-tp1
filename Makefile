SrcDir = src
BinDir = bin

CheckDirs = [ -d "$(BinDir)" ] || mkdir "$(BinDir)";

MainFile         = $(SrcDir)/Main.cpp
OutputFileName   = $(basename $(notdir $(MainFile)))
OutputFile       = $(BinDir)/$(OutputFileName)
CompilationUnits = $(SrcDir)/allegro/*.cpp \
                   $(SrcDir)/game/*.cpp

Build       = clang++ # or g++
Standard    = c++14
Libs        = allegro-5 allegro_ttf-5
BuildFlags  = $(shell pkg-config --cflags --libs $(Libs))	\
              -std=$(Standard)														\
              -I $(SrcDir)																\
              -o $(OutputFile)														\


build: $(MainFile)
	@$(CheckDirs)
	@$(Build) $(BuildFlags) $(CompilationUnits) $(MainFile)

run: build
	@cd $(BinDir) && ./$(OutputFileName)


clean:
	rm -f $(OutputFile)

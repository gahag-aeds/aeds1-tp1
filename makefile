SrcDir = src
BinDir = bin

MainFile         = $(SrcDir)/Main.cpp
ScoreFile        = $(BinDir)/score.dat
OutputFileName   = Ikaruga
OutputFile       = $(BinDir)/$(OutputFileName)
CompilationUnits = $(SrcDir)/allegro/*.cpp \
                   $(SrcDir)/game/*.cpp

Build       = g++ # or clang++
Standard    = c++14
Libs        = allegro-5 allegro_ttf-5
BuildFlags  = $(shell pkg-config --cflags --libs $(Libs)) \
              -Wall                                       \
              -std=$(Standard)                            \
              -I $(SrcDir)                                \
              -o $(OutputFile)


directories:
	@[ -d "$(BinDir)" ] || mkdir "$(BinDir)";

score.dat: directories
	@echo "0" > $(ScoreFile)

build: directories score.dat $(MainFile)
	@$(Build) $(BuildFlags) $(CompilationUnits) $(MainFile)

run: directories build
	@cd $(BinDir) && ./$(OutputFileName)


clean:
	rm -f $(OutputFile)

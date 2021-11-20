SrcDir = src
BinDir = bin

ScoreFile  = $(BinDir)/score.dat
OutputFile = $(BinDir)/ikaruga

CompilationUnits = $(shell find $(SrcDir) -name '*.cpp')

Build       = clang++ # or g++
Warnings    = -Wall
Standard    = -std=c++14
Libs        = allegro-5 allegro_ttf-5
BuildFlags  = $(shell pkg-config --cflags --libs $(Libs)) \
              $(Warnings)                                 \
              $(Standard)                                 \
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

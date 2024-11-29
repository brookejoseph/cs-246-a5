CXX = g++								
CXXFLAGS = -std=c++20 -g -Wall -Werror=vla -MMD

SRC = main.cc \
	  observer/subject.cc \
      gameengine/gameengine.cc \
      board/board.cc \
      block/blockZ.cc \
      block/blockT.cc \
      block/blockI.cc \
      block/blockL.cc \
      block/blockJ.cc \
      block/blockO.cc \
      block/blockS.cc \
      block/blockstar.cc \
      level/level.cc \
      level/level0.cc  \
      level/level1.cc \
      level/level2.cc \
      level/level3.cc \
      level/level4.cc \
      block/block.cc \
	  textdisplay/textdisplay.cc \


OBJ = $(SRC:.cc=.o)

all: biquadris

biquadris: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

clean:
	rm -f biquadris $(OBJ)

CXX = g++
CXXFLAGS = -std=c++17 -Iblock -Iboard -I../gameengine

SRC = testing.cc \
      ../gameengine/gameengine.cc \
      ../board/board.cc \
      ../block/blockZ.cc \
      ../block/blockT.cc \
      ../block/blockI.cc \
      ../block/blockL.cc \
      ../block/blockJ.cc \
      ../block/blockO.cc \
      ../block/blockS.cc \
      ../block/block.cc 

OBJ = $(SRC:.cc=.o)

all: testing

testing: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

clean:
	rm -f testing $(OBJ)

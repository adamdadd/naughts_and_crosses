  all: src/naughts_and_crosses.cpp
	g++ -std=c++11 -o naughts_and_crosses src/naughts_and_crosses.cpp

  clean:
	$(RM) naughts_and_crosses



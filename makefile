  # build an executable named myprog from myprog.c
  all: naughts_and_crosses.cpp
	g++ -o naughts_and_crosses naughts_and_crosses.cpp

  clean:
	$(RM) naughts_and_crosses



EXE=2048
SRCS=src/main.cpp \
src/core/game.cpp \
src/core/game_board.cpp \
src/core/game_board_tile.cpp \
src/core/game_board_slot.cpp \
src/core/util.cpp \
src/platforms/terminal/term_game.cpp \
src/platforms/terminal/term_game_board.cpp

IDIR=src

CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -I$(IDIR)
LDFLAGS=-g
LDLIBS=-lcurses

OBJS=$(subst .cpp,.o,$(SRCS))

all: game

game: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .depend

include .depend

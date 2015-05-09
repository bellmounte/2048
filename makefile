EXE=2048
SRCS=src/main.cpp \
src/game_board.cpp \
src/game_board_tile.cpp \
src/game_board_slot.cpp \
src/platforms/terminal/output.cpp

CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g
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
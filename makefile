OBJS0MAIN   = main.o defns.o
SOURCE0MAIN = main.cpp
HEADER0MAIN =
OUT0MAIN    = gp

CC       = g++
FLAGS    = -g -c -Werror -Wall
#-Wall -Wextra -pedantic-errors

all: gp

gp: $(SOURCE0MAIN) $(LFLAGS)
	$(CC) -g $(SOURCE0MAIN) -o $(OUT0MAIN)

clean:
	rm -f $(OBJS0MAIN) $(OUT0MAIN)
	
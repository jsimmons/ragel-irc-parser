CFLAGS = -g -O0 -Wall -Wextra -Ilinenoise $(OPTFLAGS)
CC = clang

SOURCES = $(wildcard src/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SOURCES)) linenoise/linenoise.o

all : irc-parser

ragel :
	ragel -G2 src/irc-parser.rl

src/irc-parser.c : src/irc-parser.rl src/irc-parser-common.rl

irc-parser : $(OBJECTS) 
	$(CC) -o irc-parser $(CFLAGS) $(OBJECTS)

linenoise/linenoise.o : linenoise/linenoise.c linenoise/linenoise.h

clean :
	rm -f $(OBJECTS) 
	rm -f irc-parser

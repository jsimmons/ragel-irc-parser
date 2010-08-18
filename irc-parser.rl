#include "irc-parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

%%{
    machine irc_parser;

    action mark {
        printf("marking: %zu\n", fpc - argv[1]);
    }

    action write_prefix {
        printf("got a prefix: %zu\n", fpc - argv[1]);
    }

    action write_command {
        printf("got a command: %zu\n", fpc - argv[1]);
    }

    action write_trailing {
        printf("got a trailing: %zu\n", fpc - argv[1]);
    }

    action write_middle {
        printf("got a middle: %zu\n", fpc - argv[1]);
    }

    action write_message {
        printf("message completed: %zu\n", fpc - argv[1]);
    }

    include irc_parser_common "irc-parser-common.rl";
        
}%%

%% write data;

int main(int argc, char **argv)
{
    int cs;
    if(argc > 1) {
        char *p = argv[1];
        char *pe = p + strlen(p);
        char *eof = pe;

        %% write init;
        %% write exec;
    }

    printf("%i\n", cs);
    return 0;
}

#include "irc-parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linenoise.h"

%%{
    machine irc_parser;

    action mark {
        printf("marking: %zu\n", fpc - data);
        mark = fpc - data;
    }

    action write_name {
        printf("got a nick/servername(prefix): %zu\n", fpc - data);
    }

    action write_user {
        printf("got a user(prefix): %zu\n", fpc - data);
    }

    action write_host {
        printf("got a host(prefix): %zu\n", fpc - data);
    }

    action prefix_err {
        printf("error parsing prefix! %zu continuing happily\n\n", fpc - data);
        fhold; fgoto gobble_line;
    }

    action write_command {
        printf("got a command: %zu\n", fpc - data);
    }

    action command_err {
        printf("error parsing command! %zu continuing happily\n\n", fpc - data);
        fhold; fgoto gobble_line;
    }

    action write_arg {
        printf("got an arg: %zu\n", fpc - data);
    }

    action arg_err {
        printf("error parsing argument! %zu continuing happily\n\n", fpc - data);
        fhold; fgoto gobble_line;
    }

    action write_message {
        printf("message completed: %zu\n\n", fpc - data);
    }

    action message_err {
        printf("error parsing message! %zu continuing happily\n\n", fpc - data);
        fhold; fgoto gobble_line;
    }

    include irc_parser_common "irc-parser-common.rl";
        
}%%

%% write data;

const char *data = "PING\r\n"
"PING 1234\r\n"
"1234\r\n"
"PIN\rG\r\n"
"PRIVMSG #luahelp :say something\r\n"
":ccfreak2k!~ccfreak2k@4chan.fm PRIVMSG #wiremod :No.\r\n"
":ccfreak2k@@!~ccfreak2k@4chan.fm PRIVMSG #wiremod :No.\r\n"
":ccfreak2k!~ccfreak2k@4chan.fm PRIVMSG #wi\rremod :No.\r\n"
"PRIVMSG abc :def hij\r\n";

int main(int argc, char **argv)
{
    int cs;
    size_t mark;

    const char *p = data;
    const char *pe = p + strlen(p);
    const char *eof = pe;

    int stack[10] = {0};
    int top = 0;

    %% write init;
    %% write exec;

    printf("Finished at state %i\n", cs);

    return 0;
}

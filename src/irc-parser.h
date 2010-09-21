#ifndef RAGEL_IRC_PARSER_H
#define RAGEL_IRC_PARSER_H
#if 0
#include <glib.h>

typedef struct
{
    GString name;
    GString user;
    GString host;

    GString command;

    GSList args;
} IrcLine;

typedef 

typedef struct
{
    int cs;
    size_t mark;
    char *data;
} IrcParser;

void irc_parser_init(IrcParser *parser);
void irc_parser_exec(IrcParser *parser, const char *data, size_t length, GError **error);
void irc_line_free(IrcLine *line);
void irc_parser_free(IrcParser *parser);

IrcLine *irc_line_parse(IrcParser *parser, const char *data, size_t length, GError **error);
void irc_line_free(IrcParser *parser);
#endif
#endif

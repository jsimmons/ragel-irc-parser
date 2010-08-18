
#line 1 "irc-parser.rl"
#include "irc-parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#line 36 "irc-parser.rl"



#line 15 "irc-parser.c"
static const char _irc_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	4, 2, 2, 5, 2, 3, 5, 2, 
	4, 5, 3, 0, 3, 5
};

static const char _irc_parser_key_offsets[] = {
	0, 0, 7, 9, 11, 16, 21, 26, 
	32, 33, 38, 41, 44
};

static const char _irc_parser_trans_keys[] = {
	58, 48, 57, 65, 90, 97, 122, 48, 
	57, 48, 57, 10, 13, 32, 58, 122, 
	10, 13, 32, 58, 122, 10, 13, 32, 
	58, 122, 48, 57, 65, 90, 97, 122, 
	32, 10, 13, 32, 58, 122, 10, 13, 
	122, 10, 13, 122, 32, 65, 90, 97, 
	122, 0
};

static const char _irc_parser_single_lengths[] = {
	0, 1, 0, 0, 5, 5, 5, 0, 
	1, 5, 3, 3, 1
};

static const char _irc_parser_range_lengths[] = {
	0, 3, 1, 1, 0, 0, 0, 3, 
	0, 0, 0, 0, 2
};

static const char _irc_parser_index_offsets[] = {
	0, 0, 5, 7, 9, 15, 21, 27, 
	31, 33, 39, 43, 47
};

static const char _irc_parser_indicies[] = {
	2, 0, 3, 3, 1, 4, 1, 5, 
	1, 1, 1, 1, 7, 1, 6, 1, 
	1, 1, 1, 1, 8, 1, 1, 10, 
	1, 1, 9, 0, 3, 3, 1, 11, 
	1, 1, 1, 13, 1, 1, 12, 1, 
	1, 1, 14, 1, 1, 1, 15, 11, 
	16, 16, 1, 0
};

static const char _irc_parser_trans_targs[] = {
	2, 0, 5, 12, 3, 8, 9, 10, 
	6, 6, 7, 4, 9, 4, 11, 11, 
	12
};

static const char _irc_parser_trans_actions[] = {
	1, 0, 0, 1, 0, 0, 1, 0, 
	1, 0, 3, 5, 0, 7, 1, 0, 
	0
};

static const char _irc_parser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	9, 15, 18, 12, 9
};

static const int irc_parser_start = 1;
static const int irc_parser_first_final = 8;
static const int irc_parser_error = 0;

static const int irc_parser_en_main = 1;


#line 39 "irc-parser.rl"

int main(int argc, char **argv)
{
    int cs;
    if(argc > 1) {
        char *p = argv[1];
        char *pe = p + strlen(p);
        char *eof = pe;

        
#line 97 "irc-parser.c"
	{
	cs = irc_parser_start;
	}

#line 49 "irc-parser.rl"
        
#line 104 "irc-parser.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _irc_parser_trans_keys + _irc_parser_key_offsets[cs];
	_trans = _irc_parser_index_offsets[cs];

	_klen = _irc_parser_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _irc_parser_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _irc_parser_indicies[_trans];
	cs = _irc_parser_trans_targs[_trans];

	if ( _irc_parser_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _irc_parser_actions + _irc_parser_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 10 "irc-parser.rl"
	{
        printf("marking: %zu\n", p - argv[1]);
    }
	break;
	case 1:
#line 14 "irc-parser.rl"
	{
        printf("got a prefix: %zu\n", p - argv[1]);
    }
	break;
	case 2:
#line 18 "irc-parser.rl"
	{
        printf("got a command: %zu\n", p - argv[1]);
    }
	break;
	case 4:
#line 26 "irc-parser.rl"
	{
        printf("got a middle: %zu\n", p - argv[1]);
    }
	break;
#line 202 "irc-parser.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _irc_parser_actions + _irc_parser_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 0:
#line 10 "irc-parser.rl"
	{
        printf("marking: %zu\n", p - argv[1]);
    }
	break;
	case 2:
#line 18 "irc-parser.rl"
	{
        printf("got a command: %zu\n", p - argv[1]);
    }
	break;
	case 3:
#line 22 "irc-parser.rl"
	{
        printf("got a trailing: %zu\n", p - argv[1]);
    }
	break;
	case 4:
#line 26 "irc-parser.rl"
	{
        printf("got a middle: %zu\n", p - argv[1]);
    }
	break;
	case 5:
#line 30 "irc-parser.rl"
	{
        printf("message completed: %zu\n", p - argv[1]);
    }
	break;
#line 248 "irc-parser.c"
		}
	}
	}

	_out: {}
	}

#line 50 "irc-parser.rl"
    }

    printf("%i\n", cs);
    return 0;
}

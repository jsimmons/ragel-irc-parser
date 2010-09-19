
#line 1 "irc-parser.rl"
#include "irc-parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#line 44 "irc-parser.rl"



#line 15 "irc-parser.c"
static const char _irc_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 4, 1, 
	6, 2, 1, 0, 2, 1, 2, 2, 
	1, 3, 2, 4, 7, 2, 5, 7, 
	2, 6, 7, 3, 0, 5, 7, 3, 
	1, 0, 2, 3, 1, 2, 0, 3, 
	1, 2, 3
};

static const char _irc_parser_key_offsets[] = {
	0, 0, 7, 9, 11, 16, 21, 28, 
	34, 41, 48, 55, 62, 69, 76, 83, 
	90, 97, 104, 111, 112, 117, 120, 123
};

static const char _irc_parser_trans_keys[] = {
	58, 48, 57, 65, 90, 97, 122, 48, 
	57, 48, 57, 10, 13, 32, 58, 122, 
	10, 13, 32, 58, 122, 10, 13, 32, 
	33, 58, 64, 122, 48, 57, 65, 90, 
	97, 122, 10, 13, 32, 33, 58, 64, 
	122, 10, 13, 32, 33, 58, 64, 122, 
	10, 13, 32, 33, 58, 64, 122, 10, 
	13, 32, 33, 58, 64, 122, 10, 13, 
	32, 33, 58, 64, 122, 10, 13, 32, 
	33, 58, 64, 122, 10, 13, 32, 33, 
	58, 64, 122, 10, 13, 32, 33, 58, 
	64, 122, 10, 13, 32, 33, 58, 64, 
	122, 10, 13, 32, 33, 58, 64, 122, 
	10, 13, 32, 33, 58, 64, 122, 32, 
	10, 13, 32, 58, 122, 10, 13, 122, 
	10, 13, 122, 32, 65, 90, 97, 122, 
	0
};

static const char _irc_parser_single_lengths[] = {
	0, 1, 0, 0, 5, 5, 7, 0, 
	7, 7, 7, 7, 7, 7, 7, 7, 
	7, 7, 7, 1, 5, 3, 3, 1
};

static const char _irc_parser_range_lengths[] = {
	0, 3, 1, 1, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 2
};

static const unsigned char _irc_parser_index_offsets[] = {
	0, 0, 5, 7, 9, 15, 21, 29, 
	33, 41, 49, 57, 65, 73, 81, 89, 
	97, 105, 113, 121, 123, 129, 133, 137
};

static const char _irc_parser_indicies[] = {
	2, 0, 3, 3, 1, 4, 1, 5, 
	1, 1, 1, 1, 7, 1, 6, 1, 
	1, 1, 1, 1, 8, 1, 1, 10, 
	11, 1, 12, 1, 9, 0, 3, 3, 
	1, 1, 1, 10, 14, 1, 15, 1, 
	13, 1, 1, 17, 18, 1, 19, 1, 
	16, 1, 1, 17, 14, 1, 20, 1, 
	13, 1, 1, 17, 22, 1, 23, 1, 
	21, 1, 1, 25, 26, 1, 27, 1, 
	24, 1, 1, 25, 22, 1, 28, 1, 
	21, 1, 1, 25, 22, 1, 23, 1, 
	21, 1, 1, 10, 30, 1, 31, 1, 
	29, 1, 1, 33, 34, 1, 35, 1, 
	32, 1, 1, 33, 22, 1, 36, 1, 
	21, 1, 1, 33, 30, 1, 31, 1, 
	29, 37, 1, 1, 1, 39, 1, 1, 
	38, 1, 1, 1, 40, 1, 1, 1, 
	41, 37, 42, 42, 1, 0
};

static const char _irc_parser_trans_targs[] = {
	2, 0, 5, 23, 3, 19, 20, 21, 
	6, 6, 7, 8, 15, 9, 10, 11, 
	9, 7, 10, 11, 11, 12, 13, 14, 
	12, 7, 13, 14, 14, 16, 17, 18, 
	16, 7, 17, 18, 14, 4, 20, 4, 
	22, 22, 23
};

static const char _irc_parser_trans_actions[] = {
	1, 0, 0, 1, 0, 0, 1, 0, 
	1, 0, 3, 3, 3, 1, 9, 9, 
	0, 12, 3, 12, 31, 1, 9, 35, 
	0, 39, 3, 12, 31, 1, 9, 9, 
	0, 15, 3, 3, 9, 5, 0, 7, 
	1, 0, 0
};

static const char _irc_parser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 18, 24, 27, 21, 18
};

static const int irc_parser_start = 1;
static const int irc_parser_first_final = 19;
static const int irc_parser_error = 0;

static const int irc_parser_en_main = 1;


#line 47 "irc-parser.rl"

int main(int argc, char **argv)
{
    int cs;
    if(argc > 1) {
        char *p = argv[1];
        char *pe = p + strlen(p);
        char *eof = pe;

        
#line 132 "irc-parser.c"
	{
	cs = irc_parser_start;
	}

#line 57 "irc-parser.rl"
        
#line 139 "irc-parser.c"
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
        printf("got a nick/servername(prefix): %zu\n", p - argv[1]);
    }
	break;
	case 2:
#line 18 "irc-parser.rl"
	{
        printf("got a user(prefix): %zu\n", p - argv[1]);
    }
	break;
	case 3:
#line 22 "irc-parser.rl"
	{
        printf("got a host(prefix): %zu\n", p - argv[1]);
    }
	break;
	case 4:
#line 26 "irc-parser.rl"
	{
        printf("got a command: %zu\n", p - argv[1]);
    }
	break;
	case 6:
#line 34 "irc-parser.rl"
	{
        printf("got a middle: %zu\n", p - argv[1]);
    }
	break;
#line 249 "irc-parser.c"
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
	case 4:
#line 26 "irc-parser.rl"
	{
        printf("got a command: %zu\n", p - argv[1]);
    }
	break;
	case 5:
#line 30 "irc-parser.rl"
	{
        printf("got a trailing: %zu\n", p - argv[1]);
    }
	break;
	case 6:
#line 34 "irc-parser.rl"
	{
        printf("got a middle: %zu\n", p - argv[1]);
    }
	break;
	case 7:
#line 38 "irc-parser.rl"
	{
        printf("message completed: %zu\n", p - argv[1]);
    }
	break;
#line 295 "irc-parser.c"
		}
	}
	}

	_out: {}
	}

#line 58 "irc-parser.rl"
    }

    printf("%i\n", cs);
    return 0;
}

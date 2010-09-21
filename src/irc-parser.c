
#line 1 "src/irc-parser.rl"
#include "irc-parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linenoise.h"


#line 63 "src/irc-parser.rl"



#line 17 "src/irc-parser.c"
static const int irc_parser_start = 19;
static const int irc_parser_first_final = 19;
static const int irc_parser_error = 0;

static const int irc_parser_en_gobble_line = 17;
static const int irc_parser_en_main = 19;


#line 66 "src/irc-parser.rl"

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

    
#line 51 "src/irc-parser.c"
	{
	cs = irc_parser_start;
	top = 0;
	}

#line 90 "src/irc-parser.rl"
    
#line 59 "src/irc-parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 58 )
		goto st5;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr15;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr16;
	} else
		goto tr16;
	goto tr37;
tr0:
#line 38 "src/irc-parser.rl"
	{
        printf("error parsing command! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	goto st0;
tr3:
#line 38 "src/irc-parser.rl"
	{
        printf("error parsing command! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 47 "src/irc-parser.rl"
	{
        printf("error parsing argument! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	goto st0;
tr6:
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	goto st0;
tr9:
#line 29 "src/irc-parser.rl"
	{
        printf("error parsing prefix! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	goto st0;
tr14:
#line 29 "src/irc-parser.rl"
	{
        printf("error parsing prefix! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 38 "src/irc-parser.rl"
	{
        printf("error parsing command! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	goto st0;
tr19:
#line 47 "src/irc-parser.rl"
	{
        printf("error parsing argument! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	goto st0;
tr37:
#line 29 "src/irc-parser.rl"
	{
        printf("error parsing prefix! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 38 "src/irc-parser.rl"
	{
        printf("error parsing command! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	goto st0;
#line 169 "src/irc-parser.c"
st0:
cs = 0;
	goto _out;
tr15:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st1;
tr39:
#line 52 "src/irc-parser.rl"
	{
        printf("message completed: %zu\n\n", p - data);
    }
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 195 "src/irc-parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st2;
	goto tr0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st3;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 13: goto tr4;
		case 32: goto tr5;
	}
	goto tr3;
tr4:
#line 34 "src/irc-parser.rl"
	{
        printf("got a command: %zu\n", p - data);
    }
	goto st4;
tr22:
#line 43 "src/irc-parser.rl"
	{
        printf("got an arg: %zu\n", p - data);
    }
	goto st4;
tr25:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
#line 43 "src/irc-parser.rl"
	{
        printf("got an arg: %zu\n", p - data);
    }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 242 "src/irc-parser.c"
	if ( (*p) == 10 )
		goto st20;
	goto tr6;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 58 )
		goto tr40;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr39;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr41;
	} else
		goto tr41;
	goto tr14;
tr40:
#line 52 "src/irc-parser.rl"
	{
        printf("message completed: %zu\n\n", p - data);
    }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 271 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr9;
		case 58: goto tr9;
		case 64: goto tr9;
		case 122: goto tr9;
	}
	if ( 32 <= (*p) && (*p) <= 33 )
		goto tr9;
	goto tr8;
tr8:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 293 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr9;
		case 32: goto tr11;
		case 33: goto tr12;
		case 58: goto tr9;
		case 64: goto tr13;
		case 122: goto tr9;
	}
	goto st6;
tr11:
#line 17 "src/irc-parser.rl"
	{
        printf("got a nick/servername(prefix): %zu\n", p - data);
    }
	goto st7;
tr29:
#line 21 "src/irc-parser.rl"
	{
        printf("got a user(prefix): %zu\n", p - data);
    }
	goto st7;
tr33:
#line 25 "src/irc-parser.rl"
	{
        printf("got a host(prefix): %zu\n", p - data);
    }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 326 "src/irc-parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr15;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr16;
	} else
		goto tr16;
	goto tr14;
tr16:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st8;
tr41:
#line 52 "src/irc-parser.rl"
	{
        printf("message completed: %zu\n\n", p - data);
    }
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 358 "src/irc-parser.c"
	switch( (*p) ) {
		case 13: goto tr4;
		case 32: goto tr5;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st8;
	} else if ( (*p) >= 65 )
		goto st8;
	goto tr3;
tr5:
#line 34 "src/irc-parser.rl"
	{
        printf("got a command: %zu\n", p - data);
    }
	goto st9;
tr23:
#line 43 "src/irc-parser.rl"
	{
        printf("got an arg: %zu\n", p - data);
    }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 385 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr19;
		case 13: goto tr19;
		case 32: goto tr19;
		case 58: goto st11;
		case 122: goto tr19;
	}
	goto tr18;
tr18:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 405 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr19;
		case 13: goto tr22;
		case 32: goto tr23;
		case 58: goto tr19;
		case 122: goto tr19;
	}
	goto st10;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 10: goto tr19;
		case 13: goto tr25;
		case 122: goto tr19;
	}
	goto tr24;
tr24:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 435 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr19;
		case 13: goto tr22;
		case 122: goto tr19;
	}
	goto st12;
tr12:
#line 17 "src/irc-parser.rl"
	{
        printf("got a nick/servername(prefix): %zu\n", p - data);
    }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 452 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr9;
		case 58: goto tr9;
		case 64: goto tr9;
		case 122: goto tr9;
	}
	if ( 32 <= (*p) && (*p) <= 33 )
		goto tr9;
	goto tr27;
tr27:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 474 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr9;
		case 32: goto tr29;
		case 33: goto tr9;
		case 58: goto tr9;
		case 64: goto tr30;
		case 122: goto tr9;
	}
	goto st14;
tr13:
#line 17 "src/irc-parser.rl"
	{
        printf("got a nick/servername(prefix): %zu\n", p - data);
    }
	goto st15;
tr30:
#line 21 "src/irc-parser.rl"
	{
        printf("got a user(prefix): %zu\n", p - data);
    }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 501 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr9;
		case 58: goto tr9;
		case 64: goto tr9;
		case 122: goto tr9;
	}
	if ( 32 <= (*p) && (*p) <= 33 )
		goto tr9;
	goto tr31;
tr31:
#line 12 "src/irc-parser.rl"
	{
        printf("marking: %zu\n", p - data);
        mark = p - data;
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 523 "src/irc-parser.c"
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr9;
		case 32: goto tr33;
		case 33: goto tr9;
		case 58: goto tr9;
		case 64: goto tr9;
		case 122: goto tr9;
	}
	goto st16;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 13 )
		goto st18;
	goto st17;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 10: goto tr36;
		case 13: goto st18;
	}
	goto st17;
tr36:
#line 18 "src/irc-parser.rl"
	{ {stack[top++] = 21; goto st19;} }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 558 "src/irc-parser.c"
	if ( (*p) == 13 )
		goto st18;
	goto st17;
	}
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 20: 
#line 52 "src/irc-parser.rl"
	{
        printf("message completed: %zu\n\n", p - data);
    }
	break;
	case 4: 
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	break;
	case 5: 
	case 6: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
#line 29 "src/irc-parser.rl"
	{
        printf("error parsing prefix! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	break;
	case 1: 
	case 2: 
#line 38 "src/irc-parser.rl"
	{
        printf("error parsing command! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	break;
	case 9: 
	case 10: 
	case 11: 
	case 12: 
#line 47 "src/irc-parser.rl"
	{
        printf("error parsing argument! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	break;
	case 7: 
#line 29 "src/irc-parser.rl"
	{
        printf("error parsing prefix! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 38 "src/irc-parser.rl"
	{
        printf("error parsing command! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	break;
	case 3: 
	case 8: 
#line 38 "src/irc-parser.rl"
	{
        printf("error parsing command! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 47 "src/irc-parser.rl"
	{
        printf("error parsing argument! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
#line 56 "src/irc-parser.rl"
	{
        printf("error parsing message! %zu continuing happily\n\n", p - data);
        p--; {goto st17;}
    }
	break;
#line 682 "src/irc-parser.c"
	}
	}

	_out: {}
	}

#line 91 "src/irc-parser.rl"

    printf("Finished at state %i\n", cs);

    return 0;
}

/*
 *    file:             getch.c
 *    creation date:    2020-10-05
 *    last update:      2020-10-05
 *    author:           kaoru kakinuma
 */
#include <termios.h>
#include <stdio.h>

#include "getch.h"

static struct termios sOld, sCurrent;

/* Initialize new terminal i/o settings */
static void initTermios( void ) 
{
    tcgetattr( 0, &sOld ); /* grab old terminal i/o settings */
    sCurrent = sOld; /* make new settings same as old settings */
    sCurrent.c_lflag &= ~ICANON; /* disable buffered i/o */
    sCurrent.c_lflag &= ~ECHO; /* set no echo mode */
    tcsetattr( 0, TCSANOW, &sCurrent ); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
static void resetTermios( void ) 
{
    tcsetattr( 0, TCSANOW, &sOld );
}

/* Read a character */
char getch( void )
{
    initTermios();
    char ch = getchar();
    resetTermios();
    return ch;
}

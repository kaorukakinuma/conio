/*
 *    file:             getch.c
 *    creation date:    2020-10-05
 *    last update:      2020-10-06
 *    author:           kaoru kakinuma
 */
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios sOld, sNew;

/* Initialize new terminal i/o settings */
static void init_termios( void ) 
{
    tcgetattr( STDIN_FILENO, &sOld ); /* grab old terminal i/o settings */
    sNew = sOld; /* make new settings same as old settings */
    sNew.c_lflag &= ~ICANON; /* disable buffered i/o */
    sNew.c_lflag &= ~ECHO; /* set no echo mode */
    tcsetattr( STDIN_FILENO, TCSANOW, &sNew ); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
static void reset_termios( void ) 
{
    tcsetattr( STDIN_FILENO, TCSANOW, &sOld );
}

/* Read a character */
int getch( void )
{
    init_termios();
    int ch = getchar();
    reset_termios();
    return ch;
}

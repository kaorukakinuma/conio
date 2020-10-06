/*
 *    file:             kbhit.c
 *    creation date:    2020-10-06
 *    last update:      2020-10-06
 *    author:           kaoru kakinuma
 */
#include <stdio.h>
#include <fcntl.h>
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

/* Detect key press */
int kbhit( void )
{
    init_termios();
    int fd = fcntl( STDIN_FILENO, F_GETFL, 0 );
    fcntl( STDIN_FILENO, F_SETFL, fd | O_NONBLOCK );
    int ch = getchar();
    fcntl( STDIN_FILENO, F_SETFL, fd );
    reset_termios();

    if ( ch != EOF ) {
        ungetc( ch, stdin );
        return 1;
    }

    return 0;
}

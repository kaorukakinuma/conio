/*
 * MIT License
 * 
 * Copyright (c) 2020 Kaoru Kakinuma
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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

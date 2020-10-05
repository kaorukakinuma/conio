#include <stdio.h>
#include "getch.h"

int main( int argc, char *argv[] )
{
    (void)argc;
    (void)argv;

    while ( 1 ) {
        char ch = getch();
        printf( "%c ", ch );
    }

    return 0;
}

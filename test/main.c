#include <stdio.h>
#include "conio.h"

int main( int argc, char *argv[] )
{
    (void)argc;
    (void)argv;

    printf( "Press any key.\n" );
    while ( 1 ) {
        if ( kbhit() ) {
            char ch = getch();
            printf( "%c", ch );
        }
    }

    return 0;
}

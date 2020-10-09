# Conio

Dependencies: `none`  
Includes: `conio.h`


## How to Build

```sh
$ sudo ./mk.sh
#snip
$ ls /home/lib
libconio.a
$ ls /home/include
conio.h
```


## Usage

```c
#include <stdio.h>
#include <conio.h>

int main( void )
{
    printf( "Press any key.\n" );

    while ( 1 ) {
        if ( kbhit() ) {
            char ch = getch();
            printf( "%c is pressed.", ch );
            break;
        }
    }

    return 0;
}
```

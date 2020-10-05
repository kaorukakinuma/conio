# Conio

+ Dependencies: `none`
+ Includes: `conio.h`


## How to build

```
$ git clone https://github.com/kaorukakinuma/conio.git
$ cd conio
$ sudo ./mk.sh
#snip
$ ls /home/lib
libconio.a
$ ls /home/include
conio.h
```


## How to run a test

```
$ ./test/run.sh
```


## Usage

```c
#include <stdio.h>
#include <conio.h>

int main( void )
{
    while ( 1 ) {
        if ( kbhit() ) {
            char ch = getch();
            printf( "%c", ch );
        }
    }

    return 0;
}
```

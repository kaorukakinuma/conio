# Getch

+ Dependencies: `none`
+ Includes: `getch.h`


## How to build

```
$ git clone https://github.com/kaorukakinuma/getch.git
$ cd getch
$ sudo ./mk.sh
#snip
$ ls /home/lib
libgetch.a
$ ls /home/include
getch.h
```


## How to run a test

```
$ ./test/run.sh
```


## Usage

```c
#include <stdio.h>
#include <getch.h>

int main( void )
{
    while ( 1 ) {
        char ch = getch();
        printf( "%c ", ch );
    }

    return 0;
}
```

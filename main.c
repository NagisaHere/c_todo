#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    echo(void)
    console log
*/
void hello(void) {
    printf("Hello World!\n");
}

int main(void) {
    // initialise basic ncurses window
    
    hello();

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    endwin();
    return 0;
}


#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    // initialise basic ncurses window
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}
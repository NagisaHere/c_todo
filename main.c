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

// What is #define?
// Used to declare a constant

// declare max number of items and length of todo tasks
#define maxItems 100
#define maxLength 50


// What are typedefs?
// typedefs are used to set alternative names to data types (like unsigned int)
// an example:
// typedef short unsigned int USHORT
// short unsigned int (= USHORT)

typedef struct {
    char task[maxLength]; // I have no idea what this is
    int completed; // variable to track completion
} todoItem;

typedef struct {
    todoItem items[maxItems];
    int count;
} todoList;

// make save to file function
// I have no idea why astersisks are in the parameters but okay?
// this function I think expects a pointer?
void saveToFile(todoList *list, const char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp != NULL) {
        // test write file
        fprintf(fp, "Test writing line");
    } else {
        printf("Error has occured with opening filePath");
    }
    fclose(fp);
}

// make load function



int main(void) {
    // initialise basic ncurses window
    
    hello();

    // declare new test todoList
    // then call the saveToFile function
    todoItem testItem = {"Hello", 1};

    todoList testList = {testItem, 1};

    char testFP[] = "test.txt";

    // function works yay
    saveToFile(&testList, testFP); 

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    endwin();
    return 0;
}


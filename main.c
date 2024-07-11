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

// File IO: thank you to https://www.learnc.net/c-tutorial/c-read-text-file/

// make save to file function
// I have no idea why astersisks are in the parameters but okay?
// this function I think expects a pointer?
void saveToFile(todoList *list, const char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp != NULL) {
        // test write file
        // fprintf(fp, "Test writing line");

        // arrows are used to access members of a structure in a pointer
        // printf("list count is %d\n", list->count);  // why is this not printing???

        for (int i = 0; i < list->count; i++) {
            fprintf(fp, "%d, %s\n", list->items[i].completed,
                    list->items[i].task);
        }

    } else {
        perror("Error has occured with opening filePath");
        return;
    }
    fclose(fp);
}

// make load function
void loadFromFile(todoList *list, const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error has occured with opening filePath");
        return;
    }

    list->count = 0;  // reset to 0 to replace stored list with smth new

    // fscanf(stream (fp), const char* format) is used
    // %[^\n] means read until you have found a \n character
    // no idea why % is red though

    while (fscanf(fp, "%d, %[^\n]\n", &list->items[list->count].completed,
        list->items[list->count].task) == 2) {
            list->count++;

            if (list->count >= maxItems) {
                break;
            }
        }

    fclose(fp);
}



int main(void) {
    // initialise basic ncurses window
    
    hello();

    // test load
    todoItem testItem = {"Goodbye", 1};

    todoList testList = {{testItem}, 1};
    loadFromFile(&testList, "test.txt");

    printf("%s", testItem.task);  // this I dont think works?

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    endwin();
    return 0;
}


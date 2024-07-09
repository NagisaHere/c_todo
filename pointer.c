// Test file to understand how pointers work
#include <stdio.h>

int main(void) {
    // An integer with a value to set to X
    int x = 4;

    // * denotes that the variable is a pointer
    // pX is the variable name (its common practice to use p)
    // & denotes "the address of"
    int *pX = &x; // pointer that points to x

    // y is assigned the value of the variable in which *pX points to (in this
    // case, x)
    int y = *pX;
};
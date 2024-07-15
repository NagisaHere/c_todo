#include <stdio.h>

void TestScan(void) {
    // test scan and print the output
    const char* fp = "test.txt";
    FILE *file = fopen(fp, "r");

    int number;
    char word[50];

    if (fscanf(fp, "%d, %[\n]\n", &number, word) == 2) {
        printf("Number: %d, Word: %s \n", number, word);
    }
    else {
        printf("Error reading file");
    }

    fclose(fp);
}

// boilerplate
void TestLoad(void) {
   const char *filename = "example1.txt";
   FILE *file = fopen(filename, "r");

   // If the file does not exist, create and write initial data to it
   if (file == NULL) {
       file = fopen(filename, "w");
       if (file == NULL) {
           perror("Error creating file");
       }
       fprintf(file, "123 HelloWorld\n");
       fclose(file);
       file = fopen(filename, "r");
       if (file == NULL) {
           perror("Error opening file");
       }
   }

   int number;
   char word[50];

   if (fscanf(file, "%d %[^\n]\n", &number, word) == 2) {
       printf("Number: %d, Word: %s\n", number, word);
   } else {
       printf("Failed to read data from file.\n");
   }

   fclose(file);
}
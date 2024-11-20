#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Alphabetical order
    string names[] = { "Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron" };


    for (int i = 0; i < 6; i++) {
        // if (names[i] == "Ron") {  // ! THIS DOES NOT WORK (we can't compare strings directly, ''all at once'', because of the limitations of C). So, to solve this, we use 'strcmp()' instead, to compare two strings.
           if (strcmp(names[i], "Ron") == 0) 
            {
            printf("Ron is at index %i\n", i);
            }
    }

}
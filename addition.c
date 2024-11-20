#include <cc50.h>
#include <stdio.h>


int main(void) {


        // Prompt user for two integers, then add them together
        int x = get_int("x: ");
        int y = get_int("y: ");

        printf("x + y = %li\n", x + y);

        return 0;
}

// to compile this on windows, run the command prompt as administrator and type:
// gcc addition.c -o addition.exe
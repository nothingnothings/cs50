#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Missing command-line\n");
        return 1;
    }

    printf("Hello, %s\n", argv[1]); // This won't print, if the first if statement is true.
    return 0;
}
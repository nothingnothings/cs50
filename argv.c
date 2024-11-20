#include <cs50.h>
#include <stdio.h>
#include <string.h>


// This is how we receive arguments from the command line, in C:
int main(int argc, string argv[]) // argc is the number of arguments (including the program's name, like 'argv', in this case.), argv is an array of strings, passed by the user, in the command line, after the command invocation.
{
    if (argc == 2) {
        // printf("hello, %s\n", argv[1]);

        int n = strlen(argv[1]);

        for (int i = 0; i < n; i++) {
            printf("%c\n", argv[1][i]);
        }
    } 
    else 
    {
        printf("hello, world");
    }
}

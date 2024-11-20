#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("output: ");

    // for (int i = 0; s[i] != '\0'; i++) // * Oldschool way of checking for null terminator

    int str_length = strlen(s);

    for (int i = 0; i < str_length; i++) // * C way of checking for null terminator
    {
        printf("%c", s[i]);
    } 
    printf("\n");
}
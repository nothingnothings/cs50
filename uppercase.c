#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// Convert to uppercase
// int main(void)
// {
//     string s = get_string("Before: ");
//     printf("After: ");

//     int n = strlen(s);

//     for (int i = 0; i < n; i++)
//     {
//         if(s[i] >= 'a' && s[i] <= 'z') {
//             printf("%c", s[i] - 32);
//         }
//         else {
//             printf("%c", s[i]);
//         }
//     }
// }


int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        if (islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
    }
}
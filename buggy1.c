#include <cs50.h>
#include <stdio.h>


// Prototype
int get_negative_int(void);

int main(void)
{

    int i = get_negative_int(); // this function does not exist
    printf("i: %i\n", i);
    return 0;
}



int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative Integer: ");
    }
    while (n < 0);
    return i;
}
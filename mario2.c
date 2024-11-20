#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramid_height;

    // Get pyramid height
    pyramid_height = get_int("Pyramid height: ");

    // Ensure the height is between 1 and 7
    while (pyramid_height < 1 || pyramid_height > 8)
    {
        printf("Pyramid height must be between 1 and 7.\n");
        pyramid_height = get_int("Pyramid height: ");
    }

    // Create the pyramid
    for (int i = 0; i < pyramid_height; i++)
    {
        // Print leading spaces
        for (int j = 0; j < pyramid_height - i - 1; j++)
        {
            printf(" ");
        }

        // Print blocks
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}

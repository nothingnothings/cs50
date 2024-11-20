#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for dollar amount
    float dollars = get_float("Change: ");

    // Convert dollars to cents
    int cents = (int) (dollars * 100 + 0.5); // Add 0.5 for rounding to the nearest cent

    // Calculate amount of coins needed
    int quarters = cents / 25;
    cents = cents % 25;

    int dimes = cents / 10;
    cents = cents % 10;

    int nickels = cents / 5;
    cents = cents % 5;

    int pennies = cents; // Remaining cents are pennies

    // Output results
    printf("You receive %i quarters, %i dimes, %i nickels, and %i pennies.\n", quarters, dimes,
           nickels, pennies);
    // printf("Amount of coins: %i\n", quarters + dimes + nickels + pennies);

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);

    return 0;
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int initial_population;
    int final_value;
    int years = 0;

    // Get initial population
    initial_population = get_int("Initial population: ");
    while (initial_population < 9)
    {
        printf("Initial population must be greater than 8.\n");
        initial_population = get_int("Initial population: ");
    }

    // Get final population goal
    final_value = get_int("Final value: ");
    while (initial_population > final_value)
    {
        printf("Final value must not be smaller than the initial population.\n");
        final_value = get_int("Final value: ");
    }

    // Calculate years required to reach or exceed the final population
    while (initial_population < final_value)
    {
        int births = initial_population / 3;
        int deaths = initial_population / 4;
        initial_population += (births - deaths);
        years++;
    }

    printf("Years: %i\n", years);
    return 0;
}

#include <cc50.h>
#include <stdio.h>

int main(void) {
        // Prompt user for a float
        float x = get_float("x: ");
        float y = get_float("y: ");

        printf("%f\n", x / y);

        return 0;
}
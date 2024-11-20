#include <cc50.h>
#include <stdio.h>


// int main(void) {
//         // Prompt user for a int
//         int x = get_int("x: ");
//         int y = get_int("y: ");

//         float z = x / y;

//         printf("%f\n", z);

//         return 0;
// }



int main(void) {
        // Prompt user for a int
        int x = get_int("x: ");
        int y = get_int("y: ");

        float z = (float) x / (float) y; // This is type casting in C (similar to PHP).

        printf("%f\n", z);

        return 0;
}






counter = counter + 1;

counter += 1;






if (x < y)
{
    printf("x is less than y!\n");
} 
else if (x > y)
{
    printf("x is greater than y!\n");
}
else
{
    printf("x is equal to y!\n");
}




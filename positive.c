// Abstraction and scope

#include <cc50.h>
#include <stdio.h>

// Prototype (a hint for the function that is implemented down there):
int get_positve_int(void);

int main(void) {

    int i = get_positve_int();
    printf("i = %i\n", i);

    return 0;
}

int get_positve_int(void) {
    int n;

    do {
        n = get_int("Enter a positive integer: ");
    } while (n < 1);
    return n;
}
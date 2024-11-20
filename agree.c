#include <cc50.h>
#include <stdio.h>

int main(void) {
        // Prompt user for a string 
        char c = get_char("Do you agree? (y/n): ");
        if (c == 'y' || c == 'Y') {
                printf("Agreed!\n");
        } else if (c == 'n' || c == 'N') {
                printf("Not agreed.\n");
        } else {
                printf("Not agreed.\n");
        }
}
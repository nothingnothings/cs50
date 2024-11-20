#include <cs50.h>
#include <stdio.h>
#include <string.h>


// int main(void) {

//     string names[] = { "Brian", "David"};
//     string numbers[] = {'+1-212-555-1212', '+1-212-555-1213'};

//     for (int i = 0; i < 2; i++) {

//         if (strcmp(names[i], "David") == 0) {
//             printf("Found %s\n", numbers[i]);
//             return 0;
//         }
//     }  

//     printf("Not found\n");
//     return 1;

// }





// This is how you define data structures (like objects), in C...
typedef struct 
{
    string name;
    string number;
} 
person;


const inst NUMBER = 10;

int main(void) {

    person people[NUMBER];

    // people[0].name = "Brian";
    // people[0].number = "12211920220";

    // people[1].name = "David";
    // people[1].number = "121212211421";

    for (int i = 0; i < NUMBER; i++) {
        people[i].name = get_string("What's their name?\n");
        people[i].number = get_string("What's their number?\n");
    }

    for (int i = 0; i < 2; i++) {
        if (strcmp(people[i].name, "David") == 0) {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }  

    printf("Not found\n");
    return 1;

}




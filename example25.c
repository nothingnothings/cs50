
#include <cs50.h>
#include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int i;
//     for (i = 0; i < argc; i++)
//         printf("%s\n", argv[i]);
//     return 0;
// }


int main(void) {
    printf("Hello World!\n");
    return 0;
}

// To compile, use the following command:
// gcc -o example example.c


// Gnu stands for GNU Compiler Collection










int main(void) {
    printf("Hello World!\n");
}







int main(argc, argv){
    // print the argument as a string:
    printf("%s\n", argv[0]);
}




// You need to define the type of the variable
char *name = "Arthur";

string answer = get_string("What is your name?");






int main(void) {
string answer = get_string("What is your name? ");
printf("hello, %s\n", answer);
}
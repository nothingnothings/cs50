#include <cs50.h>
#include <stdio.h>

// Prototype
float get_score(void);
int scores[3];


// * Without arrays:
// int main(void)
// {
//     int score1 = 72;
//     int score2 = 73;
//     int score3 = 33;

//     printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
//     return 0;
// }

// * With arrays:
// int main(void)
// {

//     // scores[0] = 72;
//     // scores[1] = 73;
//     // scores[2] = 33;


//     scores[0] = get_int("Score: ");
//     scores[1] = get_int("Score: ");
//     scores[2] = get_int("Score: ");

//     printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
//     return 0;
// }

const int TOTAL = 3;

int main(void)
{
    int scores[TOTAL];

    for (int i = 0; i < TOTAL; i++) {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(TOTAL, scores));
    return 0;
}

float average(int length, int array[]) {
    int sum = 0;


    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    return (float) sum / (float) length;
}

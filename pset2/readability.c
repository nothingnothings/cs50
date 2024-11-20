#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Prompt user for input
    string user_text = get_string("Text: ");

    int number_of_letters = 0;
    int number_of_words = 1;  // Start at 1 to account for the last word
    int number_of_sentences = 0;

    // Loop through each character in the text
    for (int i = 0, n = strlen(user_text); i < n; i++)
    {
        if (isalpha(user_text[i]))
        {
            number_of_letters++;
        }
        else if (isspace(user_text[i]))
        {
            number_of_words++;
        }
        else if (user_text[i] == '.' || user_text[i] == '?' || user_text[i] == '!')
        {
            number_of_sentences++;
        }
    }

    // Calculate L and S as averages per 100 words
    float L = (float) number_of_letters / number_of_words * 100;
    float S = (float) number_of_sentences / number_of_words * 100;

    // Calculate Coleman-Liau index
    float coleman_liau = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade
    if (coleman_liau < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman_liau >= 1 && coleman_liau < 16)
    {
        printf("Grade %.0f\n", round(coleman_liau));
    }
    else
    {
        printf("Grade 16+\n");
    }
}

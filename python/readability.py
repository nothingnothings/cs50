#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

# int main(void)
# {
#     // Prompt user for input
#     string user_text = get_string("Text: ");

#     int number_of_letters = 0;
#     int number_of_words = 1;  // Start at 1 to account for the last word
#     int number_of_sentences = 0;

#     // Loop through each character in the text
#     for (int i = 0, n = strlen(user_text); i < n; i++)
#     {
#         if (isalpha(user_text[i]))
#         {
#             number_of_letters++;
#         }
#         else if (isspace(user_text[i]))
#         {
#             number_of_words++;
#         }
#         else if (user_text[i] == '.' || user_text[i] == '?' || user_text[i] == '!')
#         {
#             number_of_sentences++;
#         }
#     }

#     // Calculate L and S as averages per 100 words
#     float L = (float) number_of_letters / number_of_words * 100;
#     float S = (float) number_of_sentences / number_of_words * 100;

#     // Calculate Coleman-Liau index
#     float coleman_liau = 0.0588 * L - 0.296 * S - 15.8;

#     // Print the grade
#     if (coleman_liau < 1)
#     {
#         printf("Before Grade 1\n");
#     }
#     else if (coleman_liau >= 1 && coleman_liau < 16)
#     {
#         printf("Grade %.0f\n", round(coleman_liau));
#     }
#     else
#     {
#         printf("Grade 16+\n");
#     }
# }




while True:
    try:
        # Prompt the user for input
        user_text = input("Text: ")
        
        # Check if input is a non-empty string
        if not user_text:
            print("Input cannot be empty.")
            continue
        
        break
    except ValueError:
        # Handle non-numeric input
        print("Invalid input. Please enter a non-empty string.")


# Initialize variables to store number of letters, words, and sentences
number_of_letters = 0
number_of_words = 1
number_of_sentences = 0

# Loop through each character in the text
for i in range(len(user_text)):
    # Check if character is alphabetic
    if user_text[i].isalpha():
        number_of_letters += 1
    # Check if character is whitespace
    elif user_text[i].isspace():
        number_of_words += 1
    # Check if character is a sentence ending
    elif user_text[i] in ['.', '?', '!']:
        number_of_sentences += 1

# Calculate L and S as averages per 100 words
L = number_of_letters / number_of_words * 100
S = number_of_sentences / number_of_words * 100

# Calculate Coleman-Liau index
COLEMAN_LIAU = 0.0588 * L - 0.296 * S - 15.8

# Print the grade    
if COLEMAN_LIAU < 1:
    print("Before Grade 1")
elif COLEMAN_LIAU >= 1 and COLEMAN_LIAU < 16:
    print("Grade", round(COLEMAN_LIAU))
else:
    print("Grade 16+")

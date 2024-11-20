#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Pontos de cada letra do alfabeto.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Solicitar ao usuário duas palavras

    string first_word = get_string("first word: ");
    string second_word = get_string("second word: ");

    // Verificar se as palavras são iguais
    // if (strcmp(first_word, second_word) == 0)
    // {
    //     printf("Tie!\n");
    //     return 1;
    // } else {
    //     printf("The two words are different.\n");
    // }

    // Calcular os pontos de cada palavra
    int first_score = compute_score(first_word);
    int second_score = compute_score(second_word);

    printf("first score: %i", first_score);
    printf("second score: %i", second_score);

    // Imprimir o vencedor
    if (first_score > second_score)
    {
        printf("Player 1 wins!\n");
    } else if (first_score < second_score)
    {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}


int compute_score(string word)
{
    // Computa e devolve os pontos de cada palavra
    if (strlen(word) == 0)
    {
        return 0;
    }
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        } else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}

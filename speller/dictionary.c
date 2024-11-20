// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// const unsigned int N = 26 * 26 * 26 * 26; // 456976
const unsigned int N = 26; // 456976

// Hash table
node *table[N];

// Helper function
int case_insensitive_compare(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (tolower((unsigned char) *s1) != tolower((unsigned char) *s2))
        {
            return tolower((unsigned char) *s1) - tolower((unsigned char) *s2);
        }
        s1++;
        s2++;
    }
    return tolower((unsigned char) *s1) - tolower((unsigned char) *s2);
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if (word == NULL)
    {
        return false;
    }
    else if (strlen(word) > LENGTH)
    {
        return false;
    }
    else if (word[0] == '\0')
    {
        return false;
    }

    // Check for exact match, inside of hash table:
    // Hash the word to obtain the index in the hash table
    unsigned int index = hash(word);

    // Iterate over each node in the linked list at this index
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // If word matches node's word, return true
        if (case_insensitive_compare(word, cursor->word) == 0)
        {
            return true;
        }

        // Move to next node
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
// unsigned int hash(const char *word)
// {
//      TODO: Improve this hash function
//     return toupper(word[0]) - 'A';
// }

unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        // Make it case-insensitive by converting to lowercase
        c = tolower(c);
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % N; // N is the size of your hash table
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer to store each word read from the file
    char word[LENGTH + 1];

    // Read each word from the dictionary file
    while (fscanf(file, "%s", word) != EOF)
    {

        // Create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            free(new_node);
            return false;
        }

        // Copy word into new node
        strcpy(new_node->word, word);

        // Hash the word to obtain the index in the hash table
        unsigned int index = hash(word);

        // Insert the node into the hash table at the computed index
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Close the dictionary file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int counter = 0;

    if (N == 0)
    {
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            counter++;
            cursor = cursor->next;
        }
    }

    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    if (N == 0)
    {
        return false;
    }

    // Iterate over each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        // Set a pointer to the beginning of the linked list at this bucket
        node *cursor = table[i];

        // Free each node in the linked list
        while (cursor != NULL)
        {
            // Keep track of the next node before freeing
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}

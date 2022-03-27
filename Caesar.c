#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string encrypt(int iterator, string text);
int check_valid(int count, string input);

int main(int argc, string argv[])
{
    int k;
    // If the argument is invalid, fails
    if (check_valid(argc, argv[1]))
    {
        return 1;
    }
    // If the argument is valid
    else
    {
        k = atoi(argv[1]);
    }
    // Get the string to encrypt
    printf("Plaintext:  ");
    string plaintext = get_string("");
    // Process the cypher
    printf("Ciphertext: %s\n", encrypt(k, plaintext));
    return 0; // Great Success
}

// Checks that the CLA is a non-negative integer
int check_valid(int count, string input)
{
    // Single argument check
    if (count != 2)
    {
        printf("ERROR: Segmentation Fault\n");
        return 1;
    }
    // Iterate to check for non-numerals
    else
    {
        for (int i = 0; i < strlen(input); i++)
        {
            if (!isdigit(input[i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    return 0; // We're in business, baby!
}

// Processes the Caesar Encryption
string encrypt(int iterator, string text)
{
    // Iterate through text
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] -= 'A'; // 7
                text[i] += iterator; // 8
                text[i] %= 26; // 8
                text[i] += 'A'; // 105
            }
            if (islower(text[i]))
            {
                text[i] -= 'a'; // 7
                text[i] += iterator; // 8
                text[i] %= 26; // 8
                text[i] += 'a'; // 105
            }
        }
        else
        {
            continue;
        }
    }
    return text;
}

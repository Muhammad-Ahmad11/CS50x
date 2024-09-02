#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Ties!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum = 0 ;
    int ascii = 65; //Storing 65 in ascii because ASCII of alphabets starts with A(65)
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            if (word[i] == ascii + j
                || word[i] == ascii + j +
                32)   //Checking for the required characters by adding a number(j) in ascii(65) to change its ASCII and comparing for each characetr when character matched it adds the desired value assigned to that character according to POINTS array in the sum
            {
                sum += POINTS[i];
                break;             //break statement is used so that we do not have to run condition for other values which is also useless for the memory
            }
            else
            {
                sum += 0;    //zero is added in case when condition not satisfied
            }
        }
    }

    return sum;              //returning final sum
}
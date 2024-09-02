#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int main()
{
    //Getting string input
    string text = get_string("Enter Text: ");
    float letters = 0;
    float words = 0;
    float sentences = 0;
    int length = strlen(text);

    //Counting letters
    for (int i = 0 ; i < length ; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }

    //Counting words
    for (int i = 0 ; i < length ; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    words++;

    //Counting Sentences
    for (int i = 0 ; i < length ; i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentences++;
        }
    }

    //Formula
    float L = ((letters / words) * 100);
    float S = ((sentences / words) * 100);
    float Grade = round(0.0588 * L - 0.296 * S - 15.8);

    int c = 0;   //check

    //Making Grade by using ceil and floor operations
    for (int i = 1 ; i < 16 ; i++)
    {
        float check = i + 0.5;
        if (round(Grade) == check)
        {
            Grade = ceil(Grade);
            c = 1;
            break;
        }
        if (round(Grade) < check)
        {
            Grade = floor(Grade);
            c = 1;
            break;
        }
    }
    if (c == 0)
    {
        Grade =  ceil(Grade);
    }

    //Printing Exact Grade
    int Final_Grade = Grade;
    if (Final_Grade  < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Final_Grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", Final_Grade);
    }
}

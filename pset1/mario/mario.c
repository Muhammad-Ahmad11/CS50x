#include <cs50.h>
#include <stdio.h>

int main()
{
    int height = 0;
    int second_pyramid = 0;
    //Taking input Height:
    do
    {
        height = get_int("Enter Height: ");
    }
    while (height <= 0 || height > 8);

    //Drawing pyramids
    for (int i = 0 ; i < height ; i++)   //Nested loop
    {
        for (int j = 0 ; j < height ; j++)
        {
            if (j >= height - 1 - i)  //Conditions
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");

        //Nested loop
        for (int m = second_pyramid ; m < second_pyramid + 1 ; m++)
        {
            for (int n = 0 ; n < height ; n++)
            {
                if (n <= m)    //conditions
                {
                    printf("#");
                }
            }
            printf("\n");
        }
        second_pyramid++;
    }
}

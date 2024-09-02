#include <stdio.h>
#include <cs50.h>

int main()
{
    int height = 0;
    int pyramid = 0;
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
            if (!(j >= height - 1 - i))  //Conditions
            {
                printf(" ");
            }
        }
        //Nested loop
            for (int n = 0 ; n < height ; n++)
            {
                if (n <= pyramid)   //conditions
                {
                    printf("#");
                }
            }
            printf(y);
        pyramid++;
    }

}

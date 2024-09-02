#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float dollars = 0;
    int coins = 0;

    do
    {
        dollars = get_float("Change owned: ");      //Taking amount in dollars (float)
    }
    while (dollars < 0);

    dollars = dollars * 100;
    int cents = round(dollars);   //round used here to get correct values
    //Conditions to calculate exact coins
    do
    {
        if (cents >= 25)        //if cents greater than 25 detuct them first
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents >= 10)    //if cents greater than 10 detuct them first
        {
            coins++;
            cents = cents - 10;
        }
        else if (cents >= 5)      //if cents greater than 5 detuct them first
        {
            coins++;
            cents = cents - 5;
        }
        else if (cents >= 1)      //if cents greater than 25 detuct them first
        {
            coins++;
            cents = cents - 1;
        }
        else                     //if on reamining cash left then break
        {
            break;
        }
    }
    while (cents != 0);
    printf("%i",    coins);    //Printing coins
    printf("\n");

}
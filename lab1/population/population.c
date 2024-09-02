#include <cs50.h>
#include <stdio.h>

int main()
{
    int start_size = 0;
    int end_size = 0;
    int years = 0;
    //Taking initial population size
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    //Taking final population size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    //Calculation years to reach population to end_size
    while (start_size != end_size && start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }
    printf("Years: %i", years);
    printf("\n");

}
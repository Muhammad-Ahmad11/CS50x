#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Taking input from user in string format
    string name = get_string("What is your name?\n");
    //Greeting user
    printf("hello, %s\n", name);
}
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool flag = false;

    //Checking if user has given some input or not
    if (argc != 1)
    {
        int count = 0;

        //Checking if user has entered more than one input or input other then integers
        for (int i = 0 ; i < argc ; i++)
        {
            for (int o = 0 ; o < strlen(argv[i]) ; o++)
                if (argv[i][o] >= 48 && argv[i][o] <= 57)
                {
                    count++;
                }
        }

        if (count == strlen(argv[1]))
        {
            flag = true;
        }
        if (flag)
        {
            string plaintext = get_string("Plain text: ");  //Taking string input from user
            int k = 0;
            int value = 65;
            int length = 0 ;
            length = strlen(plaintext);
            char ciphertext[100] = "";
            int array[26];

            //Initilizing array
            for (int i = 0 ; i < 26 ; i++)
            {
                array[i] = 99;
            }
            int j = 0;
            int v = 65;

            //Finding locations that at which character are present like if digits are shifted by 1 then this code
            //will find location of new digits which is 2 and stored them in an array
            for (int i = 0 ; i < length ; i++)
            {
                for (int w = 0 ; w < 26 ; w++)
                {
                    if (plaintext[i] == value + w || plaintext[i] == value + w + 32)
                    {
                        array[j] = (w + atoi(argv[1])) % 26;
                        break;
                    }
                }
                j++;
            }

            //On the basis of the locations of array and like if previous digit is 'A' or 'a' this will
            //shift to 'B' or small 'b' and store them in cipher text
            for (int i = 0 ; i < length ; i++)
            {

                //This if condition will help to not to convert other characters to new locations like '.' or ','
                //other characters other than alphabets are store exactly the same in the ciphertext array
                if (((plaintext[i] >= 65 && plaintext[i] <= 90) || (plaintext[i] >= 97 && plaintext[i] <= 122)))
                {
                    for (int l = 0 ; l < 26 ; l++)
                    {
                        if (array[i] == l)
                        {
                            if (!(isupper(plaintext[i])))
                            {
                                ciphertext[k] = value + 32 + l;
                            }
                            else
                            {
                                ciphertext[k] = value + l;
                            }
                            k++;
                            break;
                        }
                    }
                }
                else
                {
                    int n = plaintext[i];
                    ciphertext[k] = n;
                    k++;
                }
            }
            //Printing ciphertext
            printf("ciphertext: ");
            printf("%s\n", ciphertext);
        }
        else
        {
            printf("Usage: ./caesar key");
        }
    }
    else
    {
        printf("Usage: ./caesar key");
        exit(1);
    }
}

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    //Input checker
    if (argc != 1)
    {
        bool flag = false;
        int length =  strlen(argv[1]);
        //Length checker
        if (length == 26)
        {
            //Invalid characters in key checking
            for (int s = 0 ; s < 26 ; s++)
            {
                if (!((argv[1][s] >= 65 && argv[1][s] <= 90) || (argv[1][s] >= 97 && argv[1][s] <= 122)))
                {
                    flag = true;
                }
            }

            if (!flag)
            {
                //Checking if any character in the key given is repeated or not if the characters are repeated
                //then it do not not consider that key
                int temp = 0;
                for (int i = 0 ; i < length ; i++)
                {
                    for (int j = i + 1 ; j < length ; j++)
                    {
                        if (argv[1][i] == argv[1][j])
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                    {
                        break;
                    }
                }
                if (!flag)
                {

                    int array[26];
                    for (int f = 0 ; f < 26 ; f++)
                    {
                        if (islower(argv[1][f]))
                        {
                            array[f] = argv[1][f] - 32;
                        }
                        else
                        {
                            array[f] = argv[1][f];
                        }
                    }

                    string plaintext = get_string("Plain text: ");  //Taking string input from user
                    int k = 0;
                    char ciphertext[100] = "";
                    length = strlen(plaintext);
                    for (int m = 0 ; m < length ; m++)
                    {

                        //This if condition will help to not to convert other characters to new locations like '.' or ','
                        //other characters other than alphabets are store exactly the same in the ciphertext array

                        if (((plaintext[m] >= 65 && plaintext[m] <= 90) || (plaintext[m] >= 97 && plaintext[m] <= 122)))
                        {
                            // Takes ascii of entered characters one by one

                            int ascii = plaintext[m];
                            int value = 65;
                            for (int l = 0 ; l < 26 ; l++)
                            {
                                if (ascii == value + l || ascii == value + l + 32)
                                {
                                    //Checking that if characters are not in upper case so add 32 in them ASCII so to store lower case
                                    //in cipher text array
                                    if (!(isupper(plaintext[m])))
                                    {
                                        ciphertext[k] = array[l] + 32;
                                    }
                                    else
                                    {
                                        ciphertext[k] = array[l];
                                    }
                                    k++;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            //This else is executing because we have to not to convert characetrs other than the alphabetic characters
                            //this else stores all the characters other than ASCII in the same way as they were entered as string in plaintext
                            int n = plaintext[m];
                            ciphertext[k] = n;
                            k++;
                        }
                    }
                    //Printing ciphertext in string format
                    printf("ciphertext: ");
                    printf("%s\n", ciphertext);
                }
                else
                {
                    printf("\nAll characters of key must be unique.");
                    exit(1);
                }
            }
            else
            {
                printf("Key must contain 26 characters.\n");
                exit(1);
            }
        }
        else
        {
            printf("Invalid characters in key\n");
            exit(1);
        }
    }
    else
    {
        printf("\nUsage: ./substitution key");
        exit(1);
    }
}
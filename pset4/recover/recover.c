#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    //argc 1 means that only 1 argument is passed which is itself for this file is ./recover
    //argc 2 means that 1 command line argument is passed if the condition is not satisfied that it executes else part and
    //exits main by returning 1
    if (argc == 2)
    {
        //opening file in reading mode
        FILE *inptr = fopen(argv[1], "r");

        FILE *outptr = NULL;
        if (inptr != NULL)
        {
            unsigned char buffer[512];
            int blockcount = 0;
            //character array is used to store name of .jpg file
            //its size is 8 because "000.jpg" includes 7 characters and the last one is null character
            char filename[8];
            bool newblockfound = false;
            while (fread(buffer, 512, 1, inptr))
            {
                //This condition is used to detect first four bytes of JPGs files which is are same sequence
                //if this condition is true we close previous file and starts adding data to a new file
                if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    if (newblockfound)
                    {
                        fclose(outptr);
                    }
                    sprintf(filename, "%03i.jpg", blockcount);
                    outptr = fopen(filename, "w");
                    blockcount += 1;
                    newblockfound = true;
                }
                if (newblockfound)
                {
                    fwrite(&buffer, 512, 1, outptr);
                }
            }
        }

        else
        {
            fprintf(stderr, " Could not open. %s.\n", argv[1]);
            return 1;
        }
        //CLOSING FILES
        fclose(inptr);
        //LAST file is not closed because we donot found the new block after that so we are closing it here
        fclose(outptr);

    }
    else
    {
        printf("Usage: ./recover image\n");
        return 1;
    }


}

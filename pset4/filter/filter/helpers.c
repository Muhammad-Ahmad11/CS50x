#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float grayscale = 0;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            grayscale = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;
            //dividing each grayscale pixel by 3.0 to get average of colors which is grey
            //Rounding off that figure to get exact value
            image[i][j].rgbtBlue = round(grayscale);
            image[i][j].rgbtGreen = round(grayscale);
            image[i][j].rgbtRed = round(grayscale);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            //As we are taking product of colors with some figure now as the position pof pixel increases with respect to
            //height or width some of them may reach out of scope of range of bits used to represent colors which is from
            //0 to 255 so we set them to max. 255 to be in range
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen  > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;

            image[i][j].rgbtGreen = sepiaGreen;

            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n = width - 1;
    int new_image[3];
    for (int i = 0 ; i < height ; i++)
    {
        //width is halfed because we have to horizontally reflect the image
        for (int j = 0 ; j < width / 2 ; j++)
        {

            new_image[0] = image[i][j].rgbtRed;
            new_image[1] = image[i][j].rgbtGreen;
            new_image[2] = image[i][j].rgbtBlue;

            //swapping pixels of left side to right and from right side to left side
            image[i][j].rgbtRed = image[i][n - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][n - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][n - j].rgbtBlue;

            image[i][n - j].rgbtRed = new_image[0];
            image[i][n - j].rgbtGreen = new_image[1];
            image[i][n - j].rgbtBlue = new_image[2];
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    float check = 0;
    int row = 0, green = 0, blue = 0, red = 0, col = 0;
    for (int p = 0; p < height; p++)
    {
        for (int q = 0; q < width; q++)
        {
            //starting 3x3 grid with -1 because when we are adding values other then the borders we have to take one from the left
            // of that value and the valkue itself and right one are added by incrementing the figure r and same is in the case for
            //for s integer below
            for (int r = -1; r < 2; r++)
            {
                row = p + r;
                for (int s = -1; s < 2; s++)
                {
                    col = q + s;
                    if (row < 0 || row > height - 1 || col < 0 || col > width - 1) //ignoring out of borders of each 3x3 grid
                    {
                        continue;
                    }
                    red += image[row][col].rgbtRed;
                    green += image[row][col].rgbtGreen;
                    blue += image[row][col].rgbtBlue;
                    check += 1;
                }
            }
            new_image[p][q].rgbtRed = round(red / check);
            new_image[p][q].rgbtGreen = round(green / check);
            new_image[p][q].rgbtBlue = round(blue / check);
            red  = 0;
            green = 0;
            blue = 0;
            check = 0;
        }

    }

    for (int t = 0; t < height; t++)
    {
        for (int v = 0; v < width; v++)
        {
            image[t][v].rgbtBlue = new_image[t][v].rgbtBlue;
            image[t][v].rgbtGreen = new_image[t][v].rgbtGreen;
            image[t][v].rgbtRed = new_image[t][v].rgbtRed;
        }
    }

    return;
}

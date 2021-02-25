#include "helpers.h"
#include "math.h"
#include "string.h"

#define MP(pixel) ((pixel) > 255 ? 255 : (pixel)) // MaxPixel

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE *imgPtr = &image[i][j];

            int sumValue = (int) imgPtr->rgbtBlue + imgPtr->rgbtGreen + imgPtr->rgbtRed;
            BYTE meanValue = round(sumValue / 3.0);

            *imgPtr = (RGBTRIPLE) {.rgbtBlue = meanValue,
                                   .rgbtGreen = meanValue,
                                   .rgbtRed = meanValue};
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    void swapPixels(RGBTRIPLE *a, RGBTRIPLE *b);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < (width / 2); j++)
            swapPixels(&image[i][j], &image[i][width - 1 - j]);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImg[height][width];
    memcpy(tmpImg, image, height * width * sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            float base = 0.0;
            int sB = 0, sG = 0, sR = 0;

            for (int row = i - 1; row < i + 2; row++) {
                for (int col = j - 1; col < j + 2; col++) {
                    if ((row != height) && (row != -1) &&
                            (col != width) && (col != -1)) {
                        sB += (tmpImg[row][col].rgbtBlue);
                        sG += (tmpImg[row][col].rgbtGreen);
                        sR += (tmpImg[row][col].rgbtRed);
                        base++;
                    }
                }
            }

            image[i][j] = (RGBTRIPLE) {.rgbtBlue = round(sB / base),
                                       .rgbtGreen = round(sG / base),
                                       .rgbtRed = round(sR / base)};
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int sqrtOfa2Plusb2(int a, int b);

    RGBTRIPLE tmpImg[height][width];
    memcpy(tmpImg, image, height * width * sizeof(RGBTRIPLE));

    const int GxWeights[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    const int GyWeights[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            int GxB = 0, GxG = 0, GxR = 0;
            int GyB = 0, GyG = 0, GyR = 0;

            for (int row = i - 1; row < i + 2; row++) {
                for (int col = j - 1; col < j + 2; col++) {
                    if ((row != height) && (row != -1) && (col != width) && (col != -1)) {

                        int GxWeight = GxWeights[row - i + 1][col - j + 1];
                        int GyWeight = GyWeights[row - i + 1][col - j + 1];

                        // Gx
                        GxB += (GxWeight * tmpImg[row][col].rgbtBlue);
                        GxG += (GxWeight * tmpImg[row][col].rgbtGreen);
                        GxR += (GxWeight * tmpImg[row][col].rgbtRed);

                        // Gy
                        GyB += (GyWeight * tmpImg[row][col].rgbtBlue);
                        GyG += (GyWeight * tmpImg[row][col].rgbtGreen);
                        GyR += (GyWeight * tmpImg[row][col].rgbtRed);
                    }
                }
            }

            image[i][j] = (RGBTRIPLE) {
                .rgbtBlue = MP(sqrtOfa2Plusb2(GxB, GyB)),
                .rgbtGreen = MP(sqrtOfa2Plusb2(GxG, GyG)),
                .rgbtRed = MP(sqrtOfa2Plusb2(GxR, GyR))
            };
        }
    }
}

void swapPixels(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tempImage = *a;
    *a = *b;
    *b = tempImage;
}

// Square root of a^2 + b^2.
int sqrtOfa2Plusb2(int a, int b)
{
    return (int) round(sqrt(a*a + b*b));
}

#include "helpers.h"
#include "math.h"
#include "string.h"

#define MP(pixel) ((pixel) > 255 ? 255 : (pixel)) // MaxPixel

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE *px = &image[i][j];
            BYTE mpx = round((px->rgbtBlue + px->rgbtGreen + px->rgbtRed) / 3.0);
            *px = (RGBTRIPLE) {.rgbtBlue = mpx, .rgbtGreen = mpx, .rgbtRed = mpx};
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE *px = &image[i][j];

            int sB = round(.131 * px->rgbtBlue + .534 * px->rgbtGreen + .272 * px->rgbtRed);
            int sG = round(.168 * px->rgbtBlue + .686 * px->rgbtGreen + .349 * px->rgbtRed);
            int sR = round(.189 * px->rgbtBlue + .769 * px->rgbtGreen + .393 * px->rgbtRed);

            *px = (RGBTRIPLE) {.rgbtBlue = MP(sB), .rgbtGreen = MP(sG), .rgbtRed = MP(sR)};
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        int halfOfWidth = width / 2;
        for (int j = 0; j < halfOfWidth; j++) {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Keep image currently pixels.
    RGBTRIPLE tempImage[height][width];
    memcpy(tempImage, image, sizeof(RGBTRIPLE) * height * width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            float base = 0.0;
            int sB = 0, sG = 0, sR = 0;

            for (int row = i - 1; row < i + 2; row++) {
                for (int col = j - 1; col < j + 2; col++) {
                    if ((row != height) && (row != -1) && (col != width) && (col != -1)) {
                        sB += (tempImage[row][col].rgbtBlue);
                        sG += (tempImage[row][col].rgbtGreen);
                        sR += (tempImage[row][col].rgbtRed);
                        base++;
                    }
                }
            }

            image[i][j].rgbtBlue  = round(sB / base);
            image[i][j].rgbtGreen = round(sG / base);
            image[i][j].rgbtRed   = round(sR / base);
        }
    }
}

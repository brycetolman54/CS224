#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

#define BAD_NUMBER_ARGS 1
#define BAD_OPTION 2
#define FSEEK_ERROR 3
#define FREAD_ERROR 4
#define MALLOC_ERROR 5
#define FWRITE_ERROR 6

/**
 * Parses the command line.
 *
 * argc:      the number of items on the command line (and length of the
 *            argv array) including the executable
 * argv:      the array of arguments as strings (char* array)
 * grayscale: the integer value is set to TRUE if grayscale output indicated
 *            outherwise FALSE for threshold output
 *
 * returns the input file pointer (FILE*)
 **/
FILE *parseCommandLine(int argc, char **argv, int *isGrayscale, int *isScaled) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [-g]\n", argv[0]);
        exit(BAD_NUMBER_ARGS);
    }

    if (argc == 2) {
        if (strcmp(argv[1], "-g") == 0) {
            *isGrayscale = TRUE;

        } else if (strcmp(argv[1], "-s") == 0) {
            *isScaled = TRUE;

        } else {
            fprintf(stderr, "Unknown option: '%s'\n", argv[1]);
            fprintf(stderr, "Usage: %s [-g]\n", argv[0]);
            exit(BAD_OPTION);
        }
    }

    return stdin;
}

unsigned getFileSizeInBytes(FILE* stream) {
    unsigned fileSizeInBytes = 0;

    rewind(stream);
    if (fseek(stream, 0L, SEEK_END) != 0) {
        exit(FSEEK_ERROR);
    }
    fileSizeInBytes = ftell(stream);

    return fileSizeInBytes;
}

void getBmpFileAsBytes(unsigned char* ptr, unsigned fileSizeInBytes, FILE* stream) {
    rewind(stream);
    if (fread(ptr, fileSizeInBytes, 1, stream) != 1) {
#ifdef DEBUG
        printf("feof() = %x\n", feof(stream));
        printf("ferror() = %x\n", ferror(stream));
#endif
        exit(FREAD_ERROR);
    }
}

unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red) {
    return (blue + green + red) / 3;
}

unsigned char getAverageColors(unsigned char first, unsigned char second, unsigned char third, unsigned char fourth) {
    return (first + second + third + fourth) / 4;
}

void applyThresholdToPixel(unsigned char* pixel) {
    unsigned char avg = getAverageIntensity(*pixel, *(pixel + 1), *(pixel + 2));
    unsigned char col = avg >= 128 ? 0xff : 0x00;
    for(int i =0; i < 3; i++) {
        pixel[i] = col;
    }
}

void applyGrayscaleToPixel(unsigned char* pixel) {
    unsigned char gs = getAverageIntensity(*pixel, *(pixel + 1), *(pixel + 2));
    for(int i = 0; i < 3; ++i) {
        pixel[i] = gs;
    }
}

void applyFilterToPixel(unsigned char* pixel, int isGrayscale) {
    if(isGrayscale) {
        applyGrayscaleToPixel(pixel);
    }
    else {
        applyThresholdToPixel(pixel);
    }
}

void applyScaleToColor(unsigned char* pixel, int right, int up) {

    unsigned char color = getAverageColors(*pixel, *(pixel + right), *(pixel + up), *(pixel + right + up));

    pixel[0] = color;
    pixel[right] = color;
    pixel[up] = color;
    pixel[right + up] = color;
}

void applyScaleToPixels(unsigned char* pixel, int offset, int fullRow, int fullCol) {
    for(int i = 0; i < 3; ++i) {
        applyScaleToColor(pixel + i, 3 * fullCol, -1 * offset * fullRow);
    }
}

void applyFilterToRow(unsigned char* row, int width, int isGrayscale) {
    for(int i = 0; i < width; ++i) {
        applyFilterToPixel(row + i * 3, isGrayscale);
    }
}

void applyScaleToRow(unsigned char* row, int width, int padding, int fullRow) {
    for(int i = 0; i < width; i += 2) {
        applyScaleToPixels(row + i * 3, width * 3 + padding, fullRow, width - i != 1);
    }
}

void applyFilterToPixelArray(unsigned char* pixelArray, int width, int height, int isGrayscale) {
    int padding = width * 3 % 4 > 0 ? 4 - width * 3 % 4 : 0;

#ifdef DEBUG
    printf("padding = %d\n", padding);
#endif

    for(int i = 0; i < height; ++i) {
        applyFilterToRow(pixelArray + (width * 3 + padding) * i, width, isGrayscale);
    }
}

void applyScaleToPixelArray(unsigned char* pixelArray, int width, int height) {

    int padding = width * 3 % 4 > 0 ? 4 - width * 3 % 4 : 0;

    for(int i = height; i > 0; i = i - 2) {
        applyScaleToRow(pixelArray + (width * 3 + padding) * i, width, padding, i != 1);
    }
}

void parseHeaderAndApplyFilter(unsigned char* bmpFileAsBytes, int isGrayscale, int isScaled) {
    int offsetFirstBytePixelArray = *(unsigned int *)(bmpFileAsBytes + 10);
    int width = *(unsigned int *)(bmpFileAsBytes + 18);
    int height = *(unsigned int *)(bmpFileAsBytes + 22);
    unsigned char* pixelArray = (unsigned char *)(bmpFileAsBytes + offsetFirstBytePixelArray);

#ifdef DEBUG
    printf("offsetFirstBytePixelArray = %u\n", offsetFirstBytePixelArray);
    printf("width = %u\n", width);
    printf("height = %u\n", height);
    printf("pixelArray = %p\n", pixelArray);
#endif

    if(isScaled) {
        applyScaleToPixelArray(pixelArray, width, height);
    }
    else {
        applyFilterToPixelArray(pixelArray, width, height, isGrayscale);
    }
}

int main(int argc, char **argv) {
    int grayscale = FALSE;
    int scaled = FALSE;
    unsigned fileSizeInBytes = 0;
    unsigned char* bmpFileAsBytes = NULL;
    FILE *stream = NULL;

    stream = parseCommandLine(argc, argv, &grayscale, &scaled);
    fileSizeInBytes = getFileSizeInBytes(stream);

#ifdef DEBUG
    printf("fileSizeInBytes = %u\n", fileSizeInBytes);
#endif

    bmpFileAsBytes = (unsigned char *)malloc(fileSizeInBytes);
    if (bmpFileAsBytes == NULL) {
        exit(MALLOC_ERROR);
    }
    getBmpFileAsBytes(bmpFileAsBytes, fileSizeInBytes, stream);

    parseHeaderAndApplyFilter(bmpFileAsBytes, grayscale, scaled);

#ifndef DEBUG
    if (fwrite(bmpFileAsBytes, fileSizeInBytes, 1, stdout) != 1) {
        exit(FWRITE_ERROR);
    }
#endif

    free(bmpFileAsBytes);
    return 0;
}

#include "bitmap.h"
#include "video.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//"skips" next n symbols in the stream
void fskip(FILE *file, int n)
{
    while (n-- > 0)
    {
        fgetc(file);
    }
}

Bitmap *read_bmp(const char *name)
{
    FILE *file;
    Bitmap *result = (Bitmap *)malloc(sizeof(Bitmap));
    short ncolors;
    long index;
    int x;

    if ((file = fopen(name, "rb")) == NULL)
    {
        printf("Enable to open BMP file. File : %s\n", name);
        exit(1);
    }

    /* valid bitmap file has BM as first bytes */
    if (fgetc(file) != 'B' || fgetc(file) != 'M')
    {
        fclose(file);
        printf("%s is not a bitmap file.\n", file);
        exit(1);
    }

    // skip till we get to width byte
    fskip(file, 16);
    fread(&result->width, sizeof(short), 1, file);
    // skip will we get to height byte
    fskip(file, 2);
    fread(&result->height, sizeof(short), 1, file);
    // skip till we get to color mode byte
    fskip(file, 22);
    fread(&ncolors, sizeof(short), 1, file);
    fskip(file, 6);

    // if colors are 0 then assume we are using 8bit color mode
    if (ncolors <= 0)
    {
        ncolors = 256;
    }

    // attempt to allocate memory and quit if we fail
    if ((result->bytes = (byte *)malloc((short)result->width * result->height)) == NULL)
    {
        fclose(file);
        printf("Unable to allocate memory for bitmap. Aborting");
        exit(1);
    }
    // just read file line by line
    for (index = (result->height - 1) * result->width; index >= 0; index -= result->width)
    {
        for (x = 0; x < result->width; x++)
        {
            result->bytes[(short)index + x] = (byte)fgetc(file);
        }
    }
    printf("Loaded %s. Info: \n Width = %i; Height = %i; Colors = %i\n", name, result->width, result->height, ncolors);
    fclose(file);
    return result;
}

void free_bmp(Bitmap *bmp)
{
    free(bmp->bytes);
    free(bmp);
}

void draw_bitmap(Bitmap *bmp, int x, int y)
{
    // Where bmp should be drawn on screen
    short in_offset = (y << 8) + (y << 6) + x;
    // Current reading postion in bitmap
    short bmp_offset = 0;
    int i = 0;
    for (i = 0; i < bmp->height; i++)
    {
        memcpy(&VGA[in_offset], &bmp->bytes[bmp_offset], bmp->width);
        bmp_offset += bmp->width;
        in_offset += SCREEN_WIDTH;
    }
}
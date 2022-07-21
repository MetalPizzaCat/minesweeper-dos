#ifndef BITMAP_H
#define BITMAP_H
typedef struct Bitmap
{
    int width;
    int height;
    unsigned char *bytes;
} Bitmap;

//Loads bitmap directly into memory
Bitmap *read_bmp(const char *name);

//Frees memory allocated for bitmap
void free_bmp(Bitmap *bmp);

// Draws bitmap directly into VGA
void draw_bitmap(Bitmap *bmp, int x, int y);
#endif
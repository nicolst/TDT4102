#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/


Image::Image(int width, int height) : width(width), height(height) {
    data = new Color[width*height];
}

Image::~Image() {
    /* Enter your code here */
    delete[] data;
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

const Pixel *Image::getScanLine(int line) const {
    // return data + (line*width);
    return &data[line*width];
}

Pixel *Image::getScanLine(int line) {
    return &data[line*width];
}

Color Image::getPixelColor(int x, int y) const {
    if (x >= width || y >= height) return Color();
    return data[y*width + x];
}

void Image::setPixelColor(int x, int y, const Color &color) {
    if (x >= width || y >= height) return;
    data[y*width + x] = color;
}

void Image::fill(const Color &color) {
    for (int i = 0; i < width*height; i++) {
        data[i] = color;
    }
}

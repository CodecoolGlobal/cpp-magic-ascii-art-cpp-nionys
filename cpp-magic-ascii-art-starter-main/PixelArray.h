//
// Created by x on 13/01/2025.
//

#ifndef PIXELARRAY_H
#define PIXELARRAY_H


class PixelArray {
    int height;
    int width;
    int depth;
    unsigned char* data;

public:
    PixelArray(int height, int width, int depth) : height(height), width(width), depth(depth), data(new unsigned char[height * width * depth]){};

    ~PixelArray() {
        delete[] data;
    }

    void setCell(int row, int column, int layer, unsigned char value) {
        data [depth * width * row + depth * column + layer] = value;
    }

    unsigned char getCell(int row, int column, int layer) {
        return data [depth * width * row + depth * column + layer];
    }
};

#endif //PIXELARRAY_H

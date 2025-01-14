//
// Created by x on 13/01/2025.
//

#ifndef PIXELARRAY_H
#define PIXELARRAY_H


class PixelArray {
public:
    const int height;
    const int width;
    const int depth;
private:
    unsigned char* data;

public:
    PixelArray(const int height, const int width, const int depth) : height(height), width(width), depth(depth), data(new unsigned char[height * width * depth]){};

    ~PixelArray() {
        delete[] data;
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    void setCell(const int &row, const int &column, const int &layer, const unsigned char &value) {
        data [depth * width * row + depth * column + layer] = value;
    }

    [[nodiscard]] unsigned char getCell(const int &row, const int &column, const int &layer) const {
        return data [depth * width * row + depth * column + layer];
    }
};

#endif //PIXELARRAY_H

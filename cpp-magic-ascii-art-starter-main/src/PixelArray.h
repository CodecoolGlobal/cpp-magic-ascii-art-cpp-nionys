//
// Created by x on 13/01/2025.
//

#ifndef PIXELARRAY_H
#define PIXELARRAY_H

template<typename T>
class PixelArray {
private:
    int height;
    int width;
    T *data{};

public:
    PixelArray(const int height, const int width) : height(height), width(width),
                                                    data(new T[height * width]) {
    };

    ~PixelArray() {
        delete[] data;
    }

    PixelArray<T>& operator= (PixelArray<T> other) {
        height = other.height;
        width = other.width;
        delete[] data;
        data = new T[height * width];
        memcpy(data, other.data, height * width * sizeof(T));
        return *this;
    }

    int getHeight() const {
        return height;
    }

    int getWidth() const {
        return width;
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    void setCell(const int &row, const int &column, const T &value) {
        int idx = width * row + column;
        data[idx] = value;
    }

    [[nodiscard]] T getCell(const int &row, const int &column) const {
        int idx = width * row + column;
        return data[idx];
    }
};

#endif //PIXELARRAY_H

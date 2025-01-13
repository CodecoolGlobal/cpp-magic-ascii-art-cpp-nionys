//
// Created by Patrik on 13/01/2025.
//
#include <filesystem>

#include <iostream>

#include "PixelArray.h"
#include "ImageReader/BmpImageReader/BmpImageReader.h"

using namespace std;

int main(int argc, char **argv) {
    cout << "Hello World!" << endl;
    int width;
    int height;

    BmpImageReader bmpImageReader;

    PixelArray array = bmpImageReader.readImage("../pics/test2.bmp", width, height);
    for (int i = 0; i < height; i++) {
        if (i > 0) {
            break;
        }
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                std::cout << +array.getCell(i, j, k) << " ";
            }
            cout << ",";
        }
        cout << endl;
    }
}

//
// Created by Patrik on 13/01/2025.
//
#include <filesystem>

#include <iostream>
#include <utility>

#include "PixelArray.h"
#include "./ImageReader/BmpImageReader/BmpImageReader.h"

using namespace std;


int main(int argc, char **argv) {
    cout << "Hello World!" << endl;

    BmpImageReader bmpImageReader;

    PixelArray array = bmpImageReader.readImage("../pics/test2.bmp");
    // for (int i = 0; i < height; i++) {
    //     for (int j = 0; j < width; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             std::cout << +array.getCell(i, j, k) << " ";
    //         }
    //         cout << ",";
    //     }
    //     cout << endl;
    // }

    Grayscale gs{"@#8&o:*. "};
    gs.convert(array);
}

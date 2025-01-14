//
// Created by Patrik on 13/01/2025.
//

#include <fstream>
#include <iostream>

#include "Grayscale.h"
#include "PixelArray.h"
#include "./ImageReader/BmpImageReader/BmpImageReader.h"

using namespace std;


int main(int argc, char **argv) {
    cout << "Hello World!" << endl;

    BmpImageReader bmpImageReader;

    Grayscale gs{"@#8&o:*. "};
    PixelArray array = bmpImageReader.readImage("../pics/test2.bmp");
    PixelArray grayArray = gs.convert(array);

    ofstream outFile("asd.txt");
    if (!outFile.is_open()) {
        throw runtime_error("Error opening file");
    }
    for (int r = 0; r < grayArray.height; r++) {
        // if (r>12) break;
        for (int c = 0; c < grayArray.width; c++) {
            // if (c>12) break;
            outFile << grayArray.getCell(r, c, 0);
        }
        outFile << endl;
    }
    outFile.close();

}

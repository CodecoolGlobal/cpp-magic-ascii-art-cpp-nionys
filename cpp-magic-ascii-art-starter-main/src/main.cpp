//
// Created by Patrik on 13/01/2025.
//

#include <fstream>
#include <iostream>

#include "./ImageReader/BmpImageReader/BmpImageReader.h"
#include "Grayscale.h"
#include "ImageReader/JpegReader/JpegReader.h"
#include "PixelArray.h"

using namespace std;


int main(int argc, char **argv) {
    cout << "Hello World!" << endl;

    BmpImageReader bmpImageReader;
    JpegReader jpeg_reader;


    Grayscale gs{"@#8&o:*. "};
    PixelArray array = jpeg_reader.readImage("../pics/test2.jpg");
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

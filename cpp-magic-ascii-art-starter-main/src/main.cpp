//
// Created by Patrik on 13/01/2025.
//

#include <fstream>
#include <iostream>

#include "Grayscale.h"
#include "PixelArray.h"
#include "./ImageReader/BmpImageReader/BmpImageReader.h"
#include "./ImageReader/PngImageReader/PngImageReader.h"

using namespace std;


int main(int argc, char **argv) {
    cout << "Hello World!" << endl;
    BmpImageReader bmpImageReader;
    PngImageReader pngImageReader;

    Grayscale gs{"@#8&o:*. "};
    PixelArray bmpArray = bmpImageReader.readImage("../pics/test2.bmp");
    PixelArray pngArray = pngImageReader.readImage("../pics/test2.png");

    PixelArray grayBmpArray = gs.convert(bmpArray);
    PixelArray grayPngArray = gs.convert(pngArray);

    ofstream outFileBmp("bmp.txt");
    if (!outFileBmp.is_open()) {
        throw runtime_error("Error opening file");
    }
    for (int r = 0; r < grayBmpArray.height; r++) {
        // if (r>12) break;
        for (int c = 0; c < grayBmpArray.width; c++) {
            // if (c>12) break;
            outFileBmp << grayBmpArray.getCell(r, c, 0);
        }
        outFileBmp << endl;
    }
    outFileBmp.close();

    ofstream outFilePng("png.txt");
    if (!outFilePng.is_open()) {
        throw runtime_error("Error opening file");
    }
    for (int r = 0; r < grayPngArray.height; r++) {
        // if (r>12) break;
        for (int c = 0; c < grayPngArray.width; c++) {
            // if (c>12) break;
            outFilePng << grayPngArray.getCell(r, c, 0);
        }
        outFilePng << endl;
    }
    outFilePng.close();

}

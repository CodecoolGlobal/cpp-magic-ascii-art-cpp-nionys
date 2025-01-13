//
// Created by Patrik on 13/01/2025.
//

#ifndef IMAGEREADER_H
#define IMAGEREADER_H
#include "EasyBMP.h"


class ImageReader {

public:
    static unsigned char *readBmp(std::string filePath, int &width, int &height) {
        BMP bmp;
        bmp.ReadFromFile(filePath.c_str());
        width = bmp.TellWidth();
        height = bmp.TellHeight();
        unsigned char* array = new unsigned char[height*width*3];
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                array[3*width*j+3*i] = bmp.GetPixel(i, j).Red;
                array[3*width*j+3*i+1]= bmp.GetPixel(i, j).Green;
                array[3*width*j+3*i+2] = bmp.GetPixel(i, j).Blue;
            }
        }
        return  array;
    }
};


#endif // IMAGEREADER_H

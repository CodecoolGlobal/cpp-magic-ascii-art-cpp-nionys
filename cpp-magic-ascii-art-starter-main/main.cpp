//
// Created by Patrik on 13/01/2025.
//
#include <filesystem>
#include <array>

#include <iostream>
#include "EasyBMP_1.06/EasyBMP.h"
#include "ImageReader/ImageReader.h"

using namespace std;
int main(int argc, char **argv) {


    cout<<"Hello World!"<<endl;
    int width;
    int height;
  unsigned char* array = ImageReader::readBmp("../pics/test2.bmp", width, height);
  for (int i = 0; i < height; i++) {
    if (i>0) {
        break;
    }
      for (int j = 0; j < width; j++) {
          for (int k = 0; k < 3; k++) {
              std::cout << +array[3*width*i+3*j+k]<< " ";
          }
          cout << "," ;

      }
      cout << endl;
  }


}
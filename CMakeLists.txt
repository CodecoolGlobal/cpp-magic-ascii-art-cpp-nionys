cmake_minimum_required(VERSION 3.30)
project(cpp_magic_ascii_art_cpp_nionys)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static" )
include_directories(cpp-magic-ascii-art-starter-main/src/external/EasyBMP_1.06)
set(EXECUTABLE_OUTPUT_PATH "${cpp_magic_ascii_art_cpp_nionys_SOURCE_DIR}/cpp-magic-ascii-art-starter-main/executable")
add_executable(cpp_magic_ascii_art_cpp_nionys
        cpp-magic-ascii-art-starter-main/src/main.cpp
        cpp-magic-ascii-art-starter-main/src/external/EasyBMP_1.06/EasyBMP.cpp
        cpp-magic-ascii-art-starter-main/src/external/EasyBMP_1.06/EasyBMP.h
        cpp-magic-ascii-art-starter-main/src/external/EasyBMP_1.06/EasyBMP_BMP.h
        cpp-magic-ascii-art-starter-main/src/external/EasyBMP_1.06/EasyBMP_DataStructures.h
        cpp-magic-ascii-art-starter-main/src/external/lodepng/lodepng.cpp
        cpp-magic-ascii-art-starter-main/src/external/lodepng/lodepng.h
        cpp-magic-ascii-art-starter-main/src/external/EasyBMP_1.06/EasyBMP_VariousBMPutilities.h
        cpp-magic-ascii-art-starter-main/src/ImageReader/ImageReader.h
        cpp-magic-ascii-art-starter-main/src/ImageReader/BmpImageReader/BmpImageReader.cpp
        cpp-magic-ascii-art-starter-main/src/ImageReader/BmpImageReader/BmpImageReader.h
        cpp-magic-ascii-art-starter-main/src/PixelArray.h
        cpp-magic-ascii-art-starter-main/src/Grayscale.h
        cpp-magic-ascii-art-starter-main/src/Grayscale.cpp
)
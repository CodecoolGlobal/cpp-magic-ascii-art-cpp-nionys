cmake_minimum_required(VERSION 3.30)
project(cpp_magic_ascii_art_cpp_nionys)

set(CMAKE_CXX_STANDARD 14)

include_directories(cpp-magic-ascii-art-starter-main/EasyBMP_1.06)

add_executable(cpp_magic_ascii_art_cpp_nionys
        cpp-magic-ascii-art-starter-main/main.cpp
        cpp-magic-ascii-art-starter-main/EasyBMP_1.06/EasyBMP.cpp
        cpp-magic-ascii-art-starter-main/EasyBMP_1.06/EasyBMP.h
        cpp-magic-ascii-art-starter-main/EasyBMP_1.06/EasyBMP_BMP.h
        cpp-magic-ascii-art-starter-main/EasyBMP_1.06/EasyBMP_DataStructures.h
        cpp-magic-ascii-art-starter-main/EasyBMP_1.06/EasyBMP_VariousBMPutilities.h)

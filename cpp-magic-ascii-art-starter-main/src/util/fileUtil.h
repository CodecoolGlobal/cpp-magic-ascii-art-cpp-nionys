//
// Created by User on 2025. 01. 15..
//

#ifndef FILEUTIL_H
#define FILEUTIL_H
#include <fstream>

inline extern void writeToFile(const std::string& filePath, const std::string& content) {
    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        throw std::runtime_error("couldnt open " + filePath);
    }
    outputFile << content;
    outputFile.close();
}

#endif //FILEUTIL_H

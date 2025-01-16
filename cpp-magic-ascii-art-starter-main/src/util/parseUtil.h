//
// Created by User on 2025. 01. 15..
//

#ifndef PARSEUTIL_H
#define PARSEUTIL_H

#include <stdexcept>
#include <string>

inline extern int parseInt(const std::string& s) {
    size_t len;
    const int result = stoi(s, &len);
    if (s.length() != len) {
        throw std::invalid_argument("input \""+s+"\" is not a number");
    }
    return result;
}

#endif //PARSEUTIL_H

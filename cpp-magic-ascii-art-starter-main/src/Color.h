//
// Created by User on 2025. 01. 15..
//

#ifndef COLOR_H
#define COLOR_H

struct Color {
private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
public:
    Color(): red(0), green(0), blue(0) {}
    Color(const unsigned char red, const unsigned char green, const unsigned char blue): red(red), green(green), blue(blue) {}
    unsigned char getRed() const { return red; }
    unsigned char getGreen() const { return green; }
    unsigned char getBlue() const { return blue; }
};

#endif //COLOR_H

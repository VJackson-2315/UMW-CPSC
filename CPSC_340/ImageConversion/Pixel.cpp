//
// Created by Victoria Jackson on 9/8/2025.
//
#include <iostream>
#include <fstream>
#include <sstream>

#include "Pixel.h"

using std::cout, std::cin, std::endl, std::istringstream;

/**
 * Creates a black pixel
 */
Pixel::Pixel() {
    red = 0;
    green = 0;
    blue = 0;
    max = 0;
}

/**
 * Creates a pixel with inputed values
 * @param r red val
 * @param g green val
 * @param b blue val
 * @param m maximum val, should be consistent throughout the image
 */
Pixel::Pixel(int r, int g, int b, int m) {
    red = r;
    green = g;
    blue = b;

    redc = r;
    greenc = g;
    bluec = b;

    max = m;
}

/**
 * Makes each color value equal to the average
 */
void Pixel::grayscale() {
    int grey = (red + green + blue) / 3;

    red = grey;
    green = grey;
    blue = grey;
}

/**
 * Updated values are the differences of them and the max
 */
void Pixel::invert() {
    red = max - red;
    green = max - green;
    blue = max - blue;
}

/**
 * Reverts values back to the original
 */
void Pixel::revert() {
    red = redc;
    green = greenc;
    blue = bluec;
}

void Pixel::set(int r, int g, int b) {
    red = r;
    green = g;
    blue = b;
}

int Pixel::getRed() {
    return red;
}

int Pixel::getGreen() {
    return green;
}

int Pixel::getBlue() {
    return blue;
}

int Pixel::getMax() {
    return max;
}
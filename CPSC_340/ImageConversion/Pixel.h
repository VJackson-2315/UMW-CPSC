//
// Created by Victoria Jackson on 9/8/2025.
//

#ifndef IMAGECONVERSION_PIXEL_H
#define IMAGECONVERSION_PIXEL_H


class Pixel {
    public:
        // Constructor
        Pixel();
        Pixel(int r, int g, int b, int m);

        void grayscale();
        void invert();
        void revert();

        int getRed();
        int getGreen();
        int getBlue();
        int getMax();

        void set(int red, int green, int blue);

    private:
        int red, green, blue;
        int redc, greenc, bluec;
        int max;
};


#endif //IMAGECONVERSION_PIXEL_H
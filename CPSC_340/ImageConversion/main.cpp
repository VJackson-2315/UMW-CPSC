#include "ArrayList.h"

int main() {
    ArrayList image = ArrayList("snow.ppm");
    image.grayscale(true);
    image.revert();
    image.invert(true);

    return 0;
}
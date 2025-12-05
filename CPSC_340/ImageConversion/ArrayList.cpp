#include <iostream>
#include <fstream>
#include <sstream>

#include "arrayList.h"
#include "pixel.h"

using std::cout, std::cin, std::endl, std::string, std::getline, std::istringstream, std::ofstream, std::ifstream;

/**
 * Creates an empty list of pixels
 */
ArrayList::ArrayList() {
    rows = 5;
    cols = 5;

    rowCapacity = 10;
    colCapacity = 10;

    Pixel* pixel;

    heapArray = new Pixel*[rows];

    // Allocating rows
    for (int i = 0; i < rows; i++) {
        cout << i << endl;
        heapArray[i] = new Pixel[cols + 1];
    }

    // Values initialized
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            heapArray[i][j] = Pixel();
        }
    }
}

/**
 * Creates an array list of pixels with a file
 * @param file
 */
ArrayList::ArrayList(string file) {
    ifstream inputFile(file);
    if (!inputFile.is_open()) { // Check if the file exists
        cout << "Error opening file!" << endl;
        exit(0);
    }

    int dot = file.find('.');
    string type = file.substr(dot);
    if (type != ".ppm") { // Check if the file is .ppm
        cout << "File Type " << type << " not supported" << endl;
        cout << "Program needs .ppm files" << endl;
        exit(0);
    }
    filename = file.substr(0, dot);

    string line;
    getline(inputFile, line);
    istringstream ppm(line);
    string ppmType;
    ppm >> ppmType;
    if (ppmType != "P3") { //Check if the ppm file is valid
        cout << "File invalid" << endl;
        return;
    }

    getline(inputFile, line); //size
    istringstream size(line);
    size >> rowCapacity >> colCapacity; //Stream the line that has the size, and have rows and cols equal to the ints

    rows = rowCapacity;
    cols = colCapacity;

    heapArray = new Pixel*[rows];

    // Allocating rows
    for (int i = 0; i < rows; i++) {
        heapArray[i] = new Pixel[cols + 1];
    }

    getline(inputFile, line); //color max
    istringstream color(line);
    int max;
    color >> max;

    int red;
    int green;
    int blue;
    int rowNum = 0;
    int colNum = 0;

    // Values initialized
    while (inputFile >> red >> green >> blue) { // int 1 is red, 2 is green, 3 is blue
        if (rowNum >= rows) {
            rowNum = 0;
            colNum++;
        }
        heapArray[rowNum][colNum] = Pixel(red, green, blue, max);
        rowNum++;
    }

    inputFile.close();
}

/**
 * Deletes the ArrayList
 */
ArrayList::~ArrayList() {
    std::cout << "Array destructor" << std::endl;
    for (int i = 0; i < rows; i++) {
        delete[] heapArray[i];
    }
    delete[] heapArray;
}

/**
 * Adds a new pixel
 * @param value new pixel value
 */
void ArrayList::add(Pixel value) {
    if (rows == rowCapacity) {
        resize (rowCapacity * 2, colCapacity);
    }
    if (cols == colCapacity) {
        resize (rowCapacity, colCapacity * 2);
    }
    for (int i = 0; i < cols++; i++) {
        Pixel pixel = get(rows++, i);
        if (pixel.getMax() != 0) {
            heapArray[rows++][i] = value;
            return;
        }
    }
}

/**
 * Gets a certain pixel value
 * @param row row value
 * @param col col value
 * @return Pixel
 */
Pixel ArrayList::get(int row, int col) {
    return heapArray[row][col];
}

/**
 * Grayscales all pixels in the ArrayList
 * @param makeFile bool that determines if a file should be created
 */
void ArrayList::grayscale(bool makeFile) {
    cout << "Grayscale" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Pixel pixel = get(i, j);
            pixel.grayscale();
            heapArray[i][j] = pixel;

        }
    }

    if (makeFile) {
        createFile("grayscale");
    }
}

/**
 * Inverts all pixels in the ArrayList
 * @param makeFile bool that determines if a file should be created
 */
void ArrayList::invert(bool makeFile) {
    cout << "Invert" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Pixel pixel = get(i, j);
            pixel.invert();
            heapArray[i][j] = pixel;
        }
    }

    if (makeFile) {
        createFile("invert");
    }
}

/**
 * Reverts ArrayList to original values. No file is outputed
 */
void ArrayList::revert() {
    cout << "Reverting" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Pixel pixel = get(i, j);
            pixel.revert();
            heapArray[i][j] = pixel;
        }
    }
}

/**
 * @return number of rows
 */
int ArrayList::getRows() {
    return rows;
}

/**
 * @return number of columns
 */
int ArrayList::getCols() {
    return cols;
}

/**
 * Creates a new file with the updated pixels
 * @param type name of file
 */
void ArrayList::createFile(std::string type) {
    // 6 pixels per line, no more than 70 characters
    string name = filename + "-" + type + ".ppm"; //example: file-grayscale.ppm
    ofstream out(name);
    if (!out.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }
    out << "P3" << endl;
    out << rows << " " << cols << endl;
    out << "255" << endl;
    int numPix = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (numPix >= 6) {
                numPix = 0;
                out << endl;
            }
            Pixel pixel = heapArray[j][i];
            out << pixel.getRed() << " " << pixel.getGreen() << " " << pixel.getBlue() << " ";
            int numChar;
            numPix++;
        }
    }
    out.close();
}

/**
 * Resizes the ArrayList
 * @param newX New capacity for rows
 * @param newY New capacity for cols
 */
void ArrayList::resize(size_t newX, size_t newY) {
    Pixel** newArray = new Pixel*[newX];

    for (int i = 0; i < newX; i++) {
        newArray[i] = new Pixel[newY + 1];
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            newArray[i][j] = heapArray[i][j];
        }
    }

    delete[] heapArray;

    heapArray = newArray;

    rowCapacity = newX;
    colCapacity = newY;
}

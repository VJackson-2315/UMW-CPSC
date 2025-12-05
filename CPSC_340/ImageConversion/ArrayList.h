//
// Created by Evan Coleman on 1/16/25.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

#include "Pixel.h"

class ArrayList {
    public:
        //Constructor (default)
        ArrayList();

        //Constructor (with file)
        ArrayList(std::string file);

        //Destructor
        ~ArrayList();
        void destruct();

        void add(Pixel value);

        void insert(int index, Pixel value);

        void remove(int index);

        void print();

        Pixel get(int row, int col);

        //Image Changes
        void grayscale(bool createFile);
        void invert(bool createFile);
        void revert();

        int getRows();

        int getCols();


    private:
        void resize(size_t newX, size_t newY);
        void createFile(std::string type);
        int rows; //array
        int cols; //number of arrays
        size_t rowCapacity;
        size_t colCapacity;
        std::string filename;
        Pixel** heapArray;
    //protected:
};


#endif //ARRAYLIST_H

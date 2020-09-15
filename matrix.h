#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <sstream>
#include <vector>
#include "mainwindow.h"
#include "mainwindow.h"

using namespace std;

class Matrix {
    private:
        int width;
        int height;
        int** values;
    public:
        Matrix(int height, int width);
        Matrix(int height, int width, string str);

        Matrix* add(Matrix m);
        Matrix* sub(Matrix m);
        Matrix* mult(Matrix m);
        Matrix* scale(int factor);

        bool isSquare();
        int& at(int y_coord, int x_coord) {return values[y_coord][x_coord];}
        int &getHeight(){return this->height;}
        int &getWidth(){return this->width;}

        vector<int> return_row(int col);
        vector<int> return_col(int row);

        string stringify();
};


#endif // MATRIX_H

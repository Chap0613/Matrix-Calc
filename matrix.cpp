#include "matrix.h"

int dot_product(vector<int> v1, vector<int> v2);

Matrix::Matrix(int height, int width)
 {
    this->width = width;
    this->height = height;

    values = new int*[height];
    for(int i = 0; i < height; i++) {
        values[i] = new int[width];
    }
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->values[i][j] = 0;
        }
    }
}

Matrix::Matrix(int height, int width, string str) {
    this->width = width;
    this->height = height;

    stringstream ss(str);
    vector<int> nums(width * height);
    int input, count;
    count = 0;

    for(int i = 0; i < width * height; i++) {
        if(ss >> input) {
            nums.at(i) = input;
        }
    }
    count = 0;

    values = new int*[height];
    for(int i = 0; i < height; i++) {
        values[i] = new int[width];
    }
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->values[i][j] = nums.at(count);
            count++;
        }
    }
}

bool Matrix::isSquare() {
    if (this->width == this->height) {
        return true;
    }
    return false;
}

string Matrix::stringify() {
    string str = "";
    for(int i = 0; i < this->height; i++) {
        for(int j = 0; j < this->width; j++) {
            string temp = to_string(values[i][j]);
            str += temp + " ";
        }
        str += "\n";
    }
    return str;
}

Matrix* Matrix::add(Matrix m) {
    if (this->getWidth() != m.getWidth() || this->getHeight() != m.getHeight()) {
        return NULL;
    }
    Matrix* solution = new Matrix(this->height, this->width);

    for(int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                solution->values[i][j] = this->at(i,j) + m.at(i,j);
            }
    }
    return solution;
}

Matrix* Matrix::sub(Matrix m) {
    if (this->getWidth() != m.getWidth() || this->getHeight() != m.getHeight()) {
        return NULL;
    }
    Matrix* solution = new Matrix(this->height, this->width);

    for(int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                solution->values[i][j] = this->at(i,j) - m.at(i,j);
            }
    }
    return solution;
}

Matrix* Matrix::scale(int n) {
    Matrix* solution = new Matrix(this->height, this->width);

    for(int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                solution->values[i][j] = this->at(i,j) * n;
            }
    }
    return solution;
}

Matrix* Matrix::mult(Matrix m) {
    if (this->width != m.getHeight()) {
        return NULL;
    }
    Matrix* solution = new Matrix(this->height, m.getWidth());

    for(int i = 0; i < solution->getHeight(); i++) {
        for (int j = 0; j < solution->getWidth(); j++) {
            solution->values[i][j] = dot_product(this->return_row(i),m.return_col(j));
        }
    }

    return solution;
}

vector<int> Matrix::return_col(int col_num) {
    vector<int> col;
    for(int i = 0; i < this->height; i++) {
        col.push_back(this->values[i][col_num]);
    }
    return col;
}

vector<int> Matrix::return_row(int row_num) {
    vector<int> row;
    for(int i = 0; i < this->height; i++) {
        row.push_back(this->values[row_num][i]);
    }
    return row;
}

int dot_product(vector<int> v1, vector<int> v2) {
    int sum = 0;
    for(unsigned int i = 0; i < v1.size(); i++) {
        sum += v1.at(i) * v2.at(i);
    }
    return sum;
}








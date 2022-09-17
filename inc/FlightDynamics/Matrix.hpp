#ifndef H_MATRIX
#define H_MATRIX

#include<vector>
using namespace std;

class Matrix{
    public:
       unsigned int rows;
       unsigned int cols;
       vector<vector<double>> data;
       int is_square;
};

Matrix addMatrix(Matrix a, Matrix b);
#endif
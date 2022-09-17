#include "Matrix.hpp"
#include <vector>

using namespace std;

Matrix addMatrix(Matrix a, Matrix b){
    if(a.rows != b.rows || a.cols != b.cols){
        throw "Incompatible matrix dimensions.";
    }

    Matrix res;
    res.rows = a.rows;
    res.cols = a.cols;
    res.data = a.data;

    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            res.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return res;
};

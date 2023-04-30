/**
 * @file Matrix.cpp
 * @author Ryan Portocarrero (ryan.portocarrero@colorado.edi)
 * @brief Linear algebra implementation
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Matrix.hpp"
#include <vector>

using namespace std;

/**
 * @brief Adds two matrices.
 * 
 * @param a First matrix
 * @param b Second matrix
 * @return Matrix resulting from the addition.
 */
Matrix matrix_sum(Matrix a, Matrix b){
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
}

Matrix new_column_matrix(vector<float> input_vector){
    Matrix res;
    res.rows = input_vector.size();
    res.cols = 1;
    vector<vector<float>> values;
    
    for(int i=0;i<res.rows;i++){
        values.push_back({input_vector[i]});
    }
    res.data = values;

    return res;
}


Matrix new_row_matrix(vector<float> input_gradient){
    Matrix res;
    res.cols = input_gradient.size();
    res.rows = 1;
    res.data = {input_gradient};
    return res;
}

Matrix new_square_matrix(int dim){
    Matrix result;
    result.rows = dim;
    result.cols = dim;
    result.is_square = 1;
    vector<vector<float>> values(result.rows, vector<float> (result.cols, 0)); //initizlize matrix of all zeros

    result.data = values;
    return result;
}

Matrix new_unit_matrix(int dim){
    Matrix result;
    result.rows = dim;
    result.cols = dim;
    result.is_square = 1;
    vector<vector<float>> values(result.rows, vector<float> (result.cols, 0)); //resize matrix of all zeros

    for(int i=0;i<dim;i++){
        values[i][i] = 1;
    }

    result.data = values;
    return result;
}

Matrix new_skew_symmetric(vector<float> input_vector){
    if(input_vector.size() != 3){
        throw "Incorrect Dimensions";
    }
    Matrix result;
    result.cols = 3;
    result.rows = 3;
    result.is_square = 1;
    
    float p = input_vector[0];
    float q = input_vector[1];
    float r = input_vector[2];

    result.data = {{0, -r, q},{r, 0, -p},{-q, p, 0}};
    return result;
}

Matrix matrix_const_mult(Matrix a, float b){
    Matrix result;
    result.rows = a.rows;
    result.cols = a.cols;
    result.is_square = a.is_square;
    result.data = a.data;

    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            result.data[i][j] = a.data[i][j] * b; //multiply all values
        }
    }
    return result;
}

Matrix matrix_transpose(Matrix a){
    Matrix result;
    result.rows = a.cols;
    result.cols = a.rows;
    result.is_square = a.is_square;
    //reshape matrix of all zeros
    vector<vector<float>> values(result.rows, vector<float>(result.cols, 0));
    result.data = values;

    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            result.data[j][i] = a.data[i][j]; //transpose values
        }
    }
    return result;
}

Matrix matrix_product(Matrix a, Matrix b){
    if(a.cols != b.rows){
        throw "matrix dimensions incorrect";
    }
    Matrix result;
    result.rows = a.rows;
    result.cols = b.cols;
    //initiaize proper size empty matrix
    vector<vector<float>> values(a.rows, vector<float>(b.cols, 0));

    float sum;
    for(int i=0;i<result.rows;i++){
        for(int j=0;j<result.cols;j++){
            sum = 0;
            for(int k=0;k<a.cols;k++){
                sum = sum + a.data[i][k] * b.data[k][j];
            }
            values[i][j] = sum;
        }
    }

    result.data = values;
    return result;
}

float scalar_product(vector<float> a, vector<float> b){
    if(a.size() != b.size()){
        throw "invalid dimensions";
    }

    float sum=0;
    for(int i=0;i<a.size();i++){
        sum = sum + a[i]*b[i];
    }
    return sum;
}

vector<float> Matrix_vector_product(Matrix a, vector<float> b){
    if(a.cols != b.size()){
        throw "Invalid Dimensions";
    }

    vector<float> result = b;

    for(int i=0;i<a.rows;i++){
        float sum=0;
        for(int j=0;j<a.cols;j++){
            sum += a.data[i][j]*b[j];
        }
        result[i] = sum;
    }
    return result;
}

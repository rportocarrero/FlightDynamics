/**
 * @file Matrix.hpp
 * @author Ryan Portocarrero (ryan.portocarrero@colorado.edu)
 * @brief This is the header file for a linear algebra implementation
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef H_MATRIX
#define H_MATRIX

#include <vector>
using namespace std;

/**
 * @brief This is the base Matrix class
 * 
 */
class Matrix{
    public:
       unsigned int rows;
       unsigned int cols;
       vector<vector<float>> data;
       int is_square = 0;
};

Matrix new_column_matrix(vector<float> input_vector);
Matrix new_row_matrix(vector<float> input_gradient);
Matrix new_square_matrix(int dim);
Matrix new_unit_matrix(int dim);
Matrix new_skew_symmetric(vector<float> input_vector);

Matrix matrix_sum(Matrix a, Matrix b);
Matrix matrix_const_mult(Matrix a, float b);
Matrix matrix_transpose(Matrix a);
Matrix matrix_product(Matrix a, Matrix b);
float scalar_product(vector<float> a, vector<float> b);
Matrix unit_vector_product(Matrix a, Matrix b);


#endif
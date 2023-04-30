#include "Matrix.hpp"
#include "gtest/gtest.h"

using namespace std;

TEST(MatrixTest, MatrixInitialize)
{
    Matrix t;
    t.cols = 10;
    t.rows = 20;
    t.data = {{1,2,3}, {4,5,6}, {7,8,9}};

    ASSERT_EQ(t.cols, 10);
    ASSERT_EQ(t.rows, 20);
    ASSERT_EQ(t.data[0][0], 1);
}

TEST(MatrixTest, Add2x2Matrix){
    Matrix a;
    Matrix b;
    a.cols = 2;
    b.cols = 2;
    a.rows = 2;
    b.rows = 2;
    a.data = {{1,2},{3,4}};
    b.data = {{5,6},{7,8}};

    Matrix c = matrix_sum(a, b);
    
    vector<vector<float>> expected_data = {{6,8},{10,12}};
    ASSERT_EQ(c.data,expected_data);
}

TEST(MatrixTest, AddDiffDimMatrix){
    Matrix a;
    Matrix b;
    a.cols = 2;
    b.cols = 1;
    a.rows = 2;
    b.rows = 1;
    a.data = {{1,2},{3,4}};
    b.data = {{5},{6}};

    EXPECT_ANY_THROW(Matrix c = matrix_sum(a, b));
}

TEST(MatrixTest, InitColMatrix){
    vector<float> a = {1,2,3};
    Matrix A = new_column_matrix(a);

    vector<vector<float>> expected_data = {{1},{2},{3}};

    ASSERT_EQ(A.data,expected_data);
}

TEST(MatrixTest, InitRowMatrix){
    vector<float> a = {1,2,3};
    Matrix A = new_row_matrix(a);

    vector<vector<float>> expected_data = {{1,2,3}};

    ASSERT_EQ(A.data,expected_data);
}

TEST(MatrixTest, InitSquareMatrix){
    Matrix A = new_square_matrix(3);
    vector<vector<float>> expected_data = {{0,0,0},{0,0,0},{0,0,0}};
    ASSERT_EQ(A.data, expected_data);
}

TEST(MatrixTest, InitUnitMatrix){
    Matrix A = new_unit_matrix(3);
    vector<vector<float>> expected_data = {{1,0,0},{0,1,0},{0,0,1}};
    ASSERT_EQ(A.data, expected_data);
}

TEST(MatrixTest, InitSkewSymmetric){
    vector<float> input = {1,2,3};
    Matrix A = new_skew_symmetric(input);
    vector<vector<float>> expected_data = {{0,-3,2},{3,0,-1},{-2,1,0}};
    ASSERT_EQ(A.data, expected_data);
}

TEST(MatrixTest, InitSkewSymmetricWrongDims){
    vector<float> input = {1,2};
    ASSERT_ANY_THROW(new_skew_symmetric(input));
    input = {1,2,3,4};
    ASSERT_ANY_THROW(new_skew_symmetric(input));
}

TEST(MatrixTest, ConstantMultiplication){
    Matrix A;
    A.rows = 3;
    A.cols = 3;
    A.is_square=1;
    A.data = {{1,2,3},{4,5,6},{7,8,9}};
    
    Matrix result = matrix_const_mult(A, 2);
    vector<vector<float>> expected_data = {{2,4,6},{8,10,12},{14,16,18}};
    ASSERT_EQ(result.data, expected_data);
}

TEST(MatrixTest, Transpose2x2){
    Matrix A;
    A.rows = 2;
    A.cols = 2;
    A.is_square = 1;
    A.data = {{1,2},{3,4}};

    Matrix result = matrix_transpose(A);
    vector<vector<float>> expected_data = {{1,3},{2,4}};
    ASSERT_EQ(result.data, expected_data);
}

TEST(MatrixTest, Transpose4x2){
    Matrix A;
    A.rows = 4;
    A.cols = 2;
    A.is_square = 1;
    A.data = {{1,2},{3,4},{5,6},{7,8}};

    Matrix result = matrix_transpose(A);
    vector<vector<float>> expected_data = {{1,3,5,7},{2,4,6,8}};
    ASSERT_EQ(result.data, expected_data);
}

TEST(MatrixTest, product2x2){
    Matrix A;
    A.rows = 2;
    A.cols = 2;
    A.is_square = 1;
    A.data = {{-1,4},{2,3}};

    Matrix B;
    B.rows = 2;
    B.cols = 2;
    B.is_square = 2;
    B.data = {{9,-3},{6,1}};

    Matrix result = matrix_product(A,B);
    
    vector<vector<float>> expected_data = {{15,7},{36,-3}};
    ASSERT_EQ(result.data, expected_data);
}

TEST(MatrixTest, product2x3x4){
    Matrix A;
    A.rows = 2;
    A.cols = 3;
    A.data = {{2,1,4},{0,1,1}};

    Matrix B;
    B.rows = 3;
    B.cols = 4;
    B.data = {{6,3,-1,0},{1,1,0,4},{-2,5,0,2}};

    Matrix result = matrix_product(A,B);
    
    vector<vector<float>> expected_data = {{5,27,-2,12},{-1,6,0,6}};
    ASSERT_EQ(result.data, expected_data);
}

TEST(MatrixTest, scalarProduct){
    vector<float> A = {3,2,-1};
    vector<float> B = {5,5,0};
    float value = scalar_product(A,B);
    ASSERT_EQ(value, 25);
}

TEST(MatrixTest, scalarProductInvalidDim){
    vector<float> A = {3,2,-1,3};
    vector<float> B = {5,5,0};
    EXPECT_ANY_THROW(scalar_product(A,B));
}

TEST(MatrixTest, vectorProductInvalidDim){
    Matrix A;
    A.rows = 3;
    A.cols = 3;
    A.data = {{1,0,0},{0,1,0},{0,0,1}};
    vector<float> B = {1,2};
    vector<float> expected = {1,2,3};

    EXPECT_ANY_THROW(Matrix_vector_product(A, B));
}

TEST(MatrixTest, vectorProduct){
    Matrix A;
    A.rows = 3;
    A.cols = 3;
    A.data = {{1,2,3},{3,1,2},{2,3,1}};
    vector<float> B = {1,2,3};
    vector<float> expected = {14,11,11};

    vector<float> result = Matrix_vector_product(A, B);
    ASSERT_EQ(result, expected);
}
// SubtractTest.cpp
#include "Matrix.hpp"
#include "gtest/gtest.h"

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

    Matrix c = addMatrix(a, b);
    
    vector<vector<double>> expected_data = {{6,8},{10,12}};
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

    EXPECT_ANY_THROW(Matrix c = addMatrix(a, b));
}
/**
 * @file test_main.cpp
 * @author Ryan Portocarrero (ryan.portocarrero@colorado.edu)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// AllTests.cpp
#include "gtest/gtest.h"

/**
 * @brief Function to run all unit tests
 * 
 * @param argc 
 * @param argv 
 * @return int return value
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
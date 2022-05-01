#include "SquareMaker.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(SquareMaker, square) {

    // Arrange
    int x = 3;
    SquareMaker thing = SquareMaker();

    // Act
    thing.SquareThis(x);

    // Assert
    GTEST_ASSERT_EQ(x, 9);
}
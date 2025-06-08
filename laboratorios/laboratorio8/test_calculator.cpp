#include <gtest/gtest.h>
#include "calculator.h"

TEST(CalculatorTest, Add) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
}

TEST(CalculatorTest, Subtract) {
    Calculator calc;
    EXPECT_EQ(calc.subtract(5, 3), 2);
}

TEST(CalculatorTest, Multiply) {
    Calculator calc;
    EXPECT_EQ(calc.multiply(3, 4), 12);
}

TEST(CalculatorTest, Divide) {
    Calculator calc;
    EXPECT_EQ(calc.divide(10, 2), 5);
}

TEST(CalculatorTest, DivideByZero) {
    Calculator calc;
    EXPECT_THROW(calc.divide(10, 0), const char*);
}

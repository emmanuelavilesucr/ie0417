#include <gtest/gtest.h>
#include "calculator_buggy.h"

TEST(CalculatorBuggyTest, Add) {
    CalculatorBuggy calc;
    EXPECT_EQ(calc.add(2, 3), 5); // Esta prueba fallará
}

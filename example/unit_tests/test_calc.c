#include "Eagle.h"
#include "../calc.h"

TEST(T_ADD)
{
    int a = 5;
    int b = 4;

    int sum = addNumbers(a, b);

    CHECK_EQ(sum, 9);
}

TEST(T_MULT)
{
    int a = 6;
    int b = -2;

    int prod = multNumbers(a, b);

    CHECK_TRUE(prod < 0);
    CHECK_EQ(prod, -12);
}

TEST(T_FAIL)
{
    int a = 5;
    a++;

    CHECK_TRUE(a > 0);
    CHECK_FALSE(a % 5 == 1);
    CHECK_EQ(a, 6);
}
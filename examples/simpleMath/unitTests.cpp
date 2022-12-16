#include "mymathfuncs.h"
#include "iostream"

TEST(T_POS_ADDITION)
{
    int a = 5;
    int b = 4;

    int result = addition(a, b);

    CHECK_EQ(result, 9);
}

TEST(T_NEG_ADDITION)
{
    int a = 5;
    int b = -4;

    int result = addition(a, b);

    CHECK_EQ(result, 1);
}

TEST(T_POS_MULTIPLY)
{
    int a = 5;
    int b = 4;

    int result = multiplication(a, b);
    CHECK_EQ(result, 20);
}

TEST(T_COMPOUND_TEST)
{
    int a = 5;
    int b = -7;

    int sum = addition(a, b);

    CHECK_EQ(sum, -2);

    int square = multiplication(sum, sum);

    CHECK_TRUE(square > 0);
}

TEST(T_WILL_FAIL)
{
    int a = 5;
    int b = 4;

    CHECK_NEQ(a, b);
    CHECK_EQ(a, b);
    CHECK_LESS(a, b);
    CHECK_GREATER(a, b);
}

TEST(T_WILL_PASS)
{
    CHECK_TRUE(true);
}

TEST(T_ANOTHER_PASS)
{
    CHECK_NEQ(5, 6);
}

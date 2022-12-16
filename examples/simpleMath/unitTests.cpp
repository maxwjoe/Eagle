#include "mymathfuncs.h"
#include "iostream"

TEST(T_MY_ADDER)
{
    int a = 5;
    int b = 4;

    int result = myAdder(a, b);

    CHECK_EQ(result, 9);
}

TEST(T_MY_MULTI)
{
    int a = 5;
    int b = 4;

    int result = myMulti(a, b);
    CHECK_EQ(result, 20);
}

TEST(T_MY_EQUAL)
{
    int a = 5;
    int b = 4;

    CHECK_EQ(a, 67);
    CHECK_NEQ(a, 67);
    CHECK_GREATER(a, b);
    CHECK_GREATER(b, a);
}

#include "mymathfuncs.h"
#include "iostream"

TEST(T_MY_ADDER)
{
    int a = 5;
    int b = 4;

    return myAdder(a, b) == 9;
}

TEST(T_MY_MULTI)
{
    int a = 5;
    int b = 4;

    return myMulti(a, b) == 20;
}

TEST(T_MY_EQUAL)
{
    int a = 5;
    int b = 4;

    CHECK_EQ(a, 67);
    CHECK_FALSE((5 == 5));
    CHECK_NEQ(a, 67);
    CHECK_NEQ(a, 5);
    CHECK_GREATER(a, b);
    CHECK_GREATER(b, a);

    return myIsEqual(a, b) == false;
}

#include "mymathfuncs.h"

int T_MY_ADDER()
{
    int a = 5;
    int b = 4;

    return myAdder(a, b) == 9;
}

int T_MY_MULT()
{
    int a = 5;
    int b = 4;

    return myMulti(a, b) == 20;
}

int T_MY_EQUAL()
{
    int a = 5;
    int b = 4;

    return myIsEqual(a, b) == false;
}
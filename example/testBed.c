#include "Eagle.h"
#include "./unit_tests/test_calc.c"

int main()
{
    EAGLE_INIT();
    EAGLE_SET_VERBOSE(1);

    ADD_TEST(SIMPLE_MATH, T_ADD);
    ADD_TEST(SIMPLE_MATH, T_MULT);
    ADD_TEST(SIMPLE_MATH, T_FAIL);

    RUN_ALL();

    EAGLE_END();
}
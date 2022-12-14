#include "Eagle.h"
#include "./unit_tests/test_calc.c"

int main()
{
    EAGLE_INIT();

    ADD_TEST(SIMPLE_MATH, T_ADD);
    ADD_TEST(SIMPLE_MATH, T_FAIL);
    ADD_TEST(SIMPLE_MATH, T_MULT);

    RUN_COLLECTION(SIMPLE_MATH);

    EAGLE_END();
}
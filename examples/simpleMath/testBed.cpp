#include "Eagle.h"
#include "mymathfuncs.h"

#include "unitTests.cpp"

#define MATH_COL "Mathematics"

int main()
{
    // === SETUP ===
    EAGLE_INIT(true);

    // === Add Tests ===
    ADD_TEST(SIMPLE_MATHS, T_MY_ADDER);
    ADD_TEST(SIMPLE_MATHS, T_MY_MULTI);
    ADD_TEST(SIMPLE_MATHS, T_MY_EQUAL);

    // === RUN ===
    RUN_ALL_TESTS();

    EAGLE_EXIT();
}
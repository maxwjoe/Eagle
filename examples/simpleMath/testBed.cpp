#include "Eagle.h"
#include "mymathfuncs.h"

#include "unitTests.cpp"

#define MATH_COL "Mathematics"

int main()
{
    // === SETUP ===
    EAGLE_INIT(true);

    // === Add Tests ===
    ADD_TEST(EXAMPLE, T_POS_ADDITION);
    ADD_TEST(EXAMPLE, T_NEG_ADDITION);
    ADD_TEST(EXAMPLE, T_POS_MULTIPLY);
    ADD_TEST(EXAMPLE, T_COMPOUND_TEST);
    ADD_TEST(EXAMPLE, T_WILL_FAIL);
    ADD_TEST(EXAMPLE, T_WILL_PASS);
    ADD_TEST(EXAMPLE, T_ANOTHER_PASS);

    // === RUN ===
    RUN_ALL_TESTS();

    EAGLE_EXIT();
}
#include "stdio.h"
#include "Eagle.h"

TEST(T_FAIL)
{
    int x = 5;
    for (int i = 0; i < 1000000; i++)
    {
        x++;
    }
    x--;

    CHECK_TRUE(5 == 5);
    CHECK_TRUE(6 == 4);
    CHECK_EQ(5, 5);
}

TEST(T_PASS)
{
    int x = 5;
    for (int i = 0; i < 1000000; i++)
    {
        x++;
    }
    x--;

    CHECK_TRUE(5 == 5);
    CHECK_EQ(5, 5);
}

int main()
{
    EAGLE_INIT();
    EAGLE_SET_VERBOSE(1);

    ADD_TEST(C_TESTS, T_PASS);
    ADD_TEST(C_TESTS, T_PASS);
    ADD_TEST(C_TESTS, T_PASS);
    ADD_TEST(C_TESTS, T_FAIL);
    ADD_TEST(C_TESTS, T_PASS);
    ADD_TEST(C_TESTS, T_PASS);

    ADD_TEST(C_ANOTH, T_PASS);
    ADD_TEST(C_ANOTH, T_PASS);
    ADD_TEST(C_ANOTH, T_PASS);
    ADD_TEST(C_ANOTH, T_PASS);

    RUN_ALL();

    EAGLE_END();

    return 0;
}
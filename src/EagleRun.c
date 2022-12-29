#include "stdio.h"
#include "Eagle.h"

TEST(T_TEST)
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

int main()
{
    EAGLE_INIT();

    ADD_TEST(C_TESTS, T_TEST);

    RUN_ALL();

    EAGLE_END();

    return 0;
}
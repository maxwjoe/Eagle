#include "stdio.h"
#include "Eagle.h"

void T_TEST(Test t)
{
    int x = 5;
    for (int i = 0; i < 1000000; i++)
    {
        x++;
    }
    x--;
}

int main()
{
    Eagle e = EagleNew();

    EagleAddCollection(e, "COL_ONE");
    EagleAddTest(e, "COL_ONE", "T_TEST", &T_TEST);
    EagleAddTest(e, "COL_TWO", "T_TESTT", &T_TEST);

    EagleRunAll(e);

    EagleFree(e);

    return 0;
}
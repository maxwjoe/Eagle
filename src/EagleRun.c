#include "stdio.h"
#include "EagleTest.h"

void T_TEST(Test t)
{
    for (int i = 0; i < 1000; i++)
    {
        i += 2;
    }
}

int main()
{

    Test t = TestNew("T_TEST_CREATE", &T_TEST);
    TestSetCondition(t, ConditionNew("TRUE_CONDITION", 1));
    TestSetCondition(t, ConditionNew("FALSE_CONDITION", 0));

    TestRun(t);

    TestFree(t);

    return 0;
}
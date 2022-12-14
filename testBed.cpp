#include "Eagle.h"

int testCaseOne()
{
    return 1;
}

int testCaseTwo()
{
    int x = 5;
    for (int i = 0; i < 10000000; i++)
    {
        x++;
    }

    return x == 5;
}

int main()
{

    Eagle *e = new Eagle();

    e->SetVerbose(false);

    e->AddTest("Examples", "CASE_ONE", &testCaseOne);
    e->AddTest("Examples", "CASE_TWO", &testCaseTwo);
    e->AddTest("Examples", "CASE_THREE", &testCaseOne);

    e->AddTest("Other", "CASE_ONE", &testCaseOne);
    e->AddTest("Other", "CASE_TWO", &testCaseOne);
    e->AddTest("Other", "CASE_THREE", &testCaseTwo);
    e->AddTest("Other", "CASE_FOUR", &testCaseOne);

    e->RunAll();

    delete e;
    return 0;
}
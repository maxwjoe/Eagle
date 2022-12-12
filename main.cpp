#include "Eagle.h"

// --- Example File to use testing framework ---

int testFunctionPass()
{
    return 1;
}

int testFunctionFail()
{
    int x = 5;
    for (int i = 0; i < 10000; i++)
    {
        x++;
    }

    return x == 3;
}

int main()
{

    Eagle *e = new Eagle();

    e->verbose(true);

    e->addTest("MyCollection", "shouldpass", &testFunctionPass);
    e->addTest("MyCollection", "shouldfail", &testFunctionFail);

    e->addTest("Other", "shouldpass", &testFunctionPass);
    e->addTest("Other", "shouldfail", &testFunctionFail);

    e->runAll();

    delete e;
}
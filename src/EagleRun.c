#include "stdio.h"
#include "EagleCollection.h"

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

    Collection myCollection = CollectionNew("C_COLLECTION");
    CollectionSetVerbose(myCollection, 1);

    CollectionAddTest(myCollection, TestNew("T_BASIC", &T_TEST));
    CollectionAddTest(myCollection, TestNew("T_BASI", &T_TEST));
    CollectionAddTest(myCollection, TestNew("T_BASIiC", &T_TEST));
    CollectionAddTest(myCollection, TestNew("T_BASICii", &T_TEST));

    CollectionRun(myCollection);

    CollectionFree(myCollection);

    return 0;
}
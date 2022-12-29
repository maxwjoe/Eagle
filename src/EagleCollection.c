#include "EagleCollection.h"
#include "stdlib.h"
#include "string.h"

typedef struct collection
{
    char *name;
    Test *unit_tests;
    int test_count;
    int test_capacity;
    int is_verbose;
} *Collection;

Collection CollectionNew(char *collection_name)
{
    if (collection_name == NULL)
    {
        return NULL;
    }

    Collection c = (Collection)malloc(sizeof(struct collection));

    if (c == NULL)
    {
        return NULL;
    }

    // Copy collection_name into the name buffer
    size_t name_length = strlen(collection_name);
    c->name = (char *)calloc(name_length + 1, sizeof(char));

    if (c->name == NULL)
    {
        free(c);
        return NULL;
    }

    memcpy(c->name, collection_name, name_length);

    // Allocate unit_tests array buffer
    c->test_capacity = DEFAULT_UNIT_TEST_ARRAY_SIZE;
    c->unit_tests = (Test *)malloc(c->test_capacity * sizeof(Test));

    if (c->unit_tests == NULL)
    {
        free(c->name);
        free(c);
        return NULL;
    }

    c->test_count = 0;
    c->is_verbose = DEFAULT_VERBOSE_VALUE;
    return c;
}

int CollectionAddTest(Collection c, Test t)
{
    if (c == NULL || t == NULL)
    {
        return 0;
    }

    // Handle array overflow
    if (c->test_count == c->test_capacity)
    {
        int newCapacity = UNIT_TEST_GROWTH_FACTOR * c->test_capacity;
        Test *newBuffer = (Test *)realloc(c->unit_tests, newCapacity * sizeof(Test));

        if (newBuffer == NULL)
        {
            return 0;
        }

        c->unit_tests = newBuffer;
        c->test_capacity = newCapacity;
    }

    // Append test to array
    TestSetVerbose(t, c->is_verbose);
    c->unit_tests[c->test_count] = t;
    c->test_count++;

    return 1;
}

int CollectionRun(Collection c)
{
    if (c == NULL)
    {
        return 0;
    }

    int pass_count = 0;
    for (int i = 0; i < c->test_count; i++)
    {
        pass_count += TestRun(c->unit_tests[i]);
    }

    return pass_count;
}

int CollectionGetTestCount(Collection c)
{
    if (c == NULL)
    {
        return 0;
    }

    return c->test_count;
}

int CollectionSetVerbose(Collection c, int is_verbose)
{
    if (c == NULL)
    {
        return 0;
    }

    for (int i = 0; i < c->test_count; i++)
    {
        TestSetVerbose(c->unit_tests[i], is_verbose);
    }

    return 1;
}

char *CollectionGetName(Collection c)
{
    if (c == NULL)
    {
        return NULL;
    }

    return c->name;
}

int CollectionFree(Collection c)
{
    if (c == NULL)
    {
        return 0;
    }

    free(c->name);

    for (int i = 0; i < c->test_count; i++)
    {
        TestFree(c->unit_tests[i]);
    }

    free(c->unit_tests);
    free(c);

    return 1;
}

#include "Eagle.h"
#include "EagleCollection.h"
#include "EagleTest.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "gui.h"

typedef struct eagle
{
    Collection *collections;
    int is_verbose;
    int collection_count;
    int collection_capacity;
} *Eagle;

Eagle EagleNew()
{
    Eagle e = (Eagle)malloc(sizeof(struct eagle));

    if (e == NULL)
    {
        return NULL;
    }

    e->collection_capacity = DEFAULT_COLLECTION_ARRAY_SIZE;
    e->collections = (Collection *)malloc(sizeof(Collection) * e->collection_capacity);

    if (e->collections == NULL)
    {
        free(e);
        return NULL;
    }

    e->collection_count = 0;
    e->is_verbose = DEFAULT_VERBOSE_VALUE;

    return e;
}

int EagleSetVerbose(Eagle e, int is_verbose)
{
    if (e == NULL)
    {
        return 0;
    }

    e->is_verbose = is_verbose;

    int is_success = 1;
    for (int i = 0; i < e->collection_count; i++)
    {
        is_success &= CollectionSetVerbose(e->collections[i], e->is_verbose);
    }

    return is_success;
}

int EagleRunCollection(Eagle e, char *collection_name)
{
    if (e == NULL || collection_name == NULL)
    {
        return 0;
    }

    EagleSetVerbose(e, e->is_verbose);

    // Find tgtCollection
    Collection tgtCollection = NULL;

    for (int i = 0; i < e->collection_count; i++)
    {
        char *name_i = CollectionGetName(e->collections[i]);
        int cmp_res = strcmp(name_i, collection_name);

        if (cmp_res == 0)
        {
            tgtCollection = e->collections[i];
            break;
        }
    }

    if (tgtCollection == NULL)
    {
        return 0;
    }

    // Run Collection

    time_t t;
    time(&t);

    line("┏","━","┓");
    cent("┃"," ","┃", "Running Collection");
    line("┣","━","┫");
    left("┃"," ","┃", " Name: %s", CollectionGetName(tgtCollection));
    left("┃"," ","┃", " Time: %s", strtok(ctime(&t), "\n"));

    if (e->is_verbose)
    {
        line("┣","━","┫");
    }

    int pass_count = CollectionRun(tgtCollection);
    int test_count = CollectionGetTestCount(tgtCollection);

    line("┣","━","┫");
    left("┃"," ","┃", " Summary : %d out of %d tests passed", pass_count, test_count);
    line("┗","━","┛");

    return 1;
}

int EagleRunAll(Eagle e)
{
    if (e == NULL)
    {
        return 0;
    }

    EagleSetVerbose(e, e->is_verbose);

    time_t t;
    time(&t);

    line("┏","━","┓");
    cent("┃"," ","┃", "Running All Tests");
    line("┣","━","┫");
    left("┃"," ","┃", " Time: %s", strtok(ctime(&t), "\n"));

    int total_tests = 0;
    int total_passed = 0;
    for (int i = 0; i < e->collection_count; i++)
    {
        if (i == 0) {
            line("╭","─","╮");
        } else {
            line("┠","─","┨");
        }
        left("┃","","┃", " Collection: %s", CollectionGetName(e->collections[i]));
        line("┠","─","┨");
        int test_count = CollectionGetTestCount(e->collections[i]);
        int pass_count = CollectionRun(e->collections[i]);

        if (e->is_verbose)
        {
            line("┠","─","┨");
        }
        left("┃","","┃", " Summary : %d out of %d tests passed", pass_count, test_count);
        if (i == e->collection_count-1)
        {
            line("╰","─","╯");
        }

        total_passed += pass_count;
        total_tests += test_count;
    }

    cent("┃"," ","┃", "End All Tests");
    line("┣","━","┫");
    left("┃"," ","┃", " Final Summary : %d out of %d tests passed", total_passed, total_tests);
    line("┗","━","┛");

    return 1;
}

Collection EagleAddCollection(Eagle e, char *collection_name)
{
    if (e == NULL || collection_name == NULL)
    {
        return NULL;
    }

    // Handle array overflow
    if (e->collection_count == e->collection_capacity)
    {
        int newCapacity = COLLECTION_ARRAY_GROWTH_FACTOR * e->collection_capacity;
        Collection *newBuffer = (Collection *)realloc(e->collections, newCapacity * sizeof(Collection));

        if (newBuffer == NULL)
        {
            return NULL;
        }

        e->collections = newBuffer;
        e->collection_capacity = newCapacity;
    }

    // Create collection and append to the array
    Collection newCollection = CollectionNew(collection_name);

    if (newCollection == NULL)
    {
        return NULL;
    }

    CollectionSetVerbose(newCollection, e->is_verbose);
    e->collections[e->collection_count] = newCollection;
    e->collection_count++;

    return newCollection;
}

int EagleAddTest(Eagle e, char *collection_name, char *test_name, unitTestPtr test)
{
    if (!(e && collection_name && test_name && test))
    {
        return 0;
    }

    // Search for the collection and create if it does not exist
    Collection tgtCollection = NULL;

    for (int i = 0; i < e->collection_count; i++)
    {
        char *name_i = CollectionGetName(e->collections[i]);
        int cmp_res = strcmp(name_i, collection_name);

        if (cmp_res == 0)
        {
            tgtCollection = e->collections[i];
            break;
        }
    }

    if (tgtCollection == NULL)
    {
        tgtCollection = EagleAddCollection(e, collection_name);
        CollectionSetVerbose(tgtCollection, e->is_verbose);
    }

    // Create and add test to tgtCollection
    Test newTest = TestNew(test_name, test);

    if (newTest == NULL)
    {
        return 0;
    }

    int is_success = CollectionAddTest(tgtCollection, newTest);

    return is_success;
}

int EagleFree(Eagle e)
{
    if (e == NULL)
    {
        return 0;
    }

    for (int i = 0; i < e->collection_count; i++)
    {
        CollectionFree(e->collections[i]);
    }

    free(e->collections);
    free(e);

    return 1;
}

#include "EagleTest.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "EagleMacros.h"
#include "gui.h"

// s_logResult : Log a test outcome to the console
static void s_logResult(Test t, int result, double duration);

typedef struct test
{
    char *name;
    int is_verbose;
    int condition_count;
    int condition_capacity;
    unitTestPtr unit_test;
    Condition *condition_table;
} *Test;

Test TestNew(char *name, unitTestPtr test)
{
    if (name == NULL || test == NULL)
    {
        return NULL;
    }

    Test t = (Test)malloc(sizeof(struct test));

    if (t == NULL)
    {
        return NULL;
    }

    t->unit_test = test;
    t->is_verbose = DEFAULT_VERBOSE_VALUE;
    t->condition_count = 0;
    t->condition_capacity = DEFAULT_CONDITION_TABLE_CAPACITY;

    size_t name_length = strlen(name);
    t->name = (char *)calloc(name_length + 1, sizeof(char));

    if (t->name == NULL)
    {
        free(t);
        return NULL;
    }

    memcpy(t->name, name, strlen(name));

    t->condition_table = (Condition *)malloc(sizeof(Condition) * t->condition_capacity);

    if (t->condition_table == NULL)
    {
        free(t->name);
        free(t);
        return NULL;
    }

    return t;
}

int TestRun(Test t)
{
    if (t == NULL)
    {
        return -1;
    }

    // Run and time the test
    clock_t t0 = clock();
    t->unit_test(t);
    clock_t t1 = clock();
    double duration = (double)(t1 - t0) / CLOCKS_PER_SEC;

    // Validate Condition Table
    int hasPassed = 1;
    for (int i = 0; i < t->condition_count; i++)
    {
        if (!ConditionGetValue(t->condition_table[i]))
        {
            hasPassed = 0;
            break;
        }
    }

    // Print Result
    if (t->is_verbose)
    {
        if (hasPassed)
        {
            s_logResult(t, hasPassed, duration);
        }
        else
        {
            printf(" ==================================\n\n");
            s_logResult(t, hasPassed, duration);
            printf("\n");
            printf("  Condition summary for failed test :\n\n");

            for (int i = 0; i < t->condition_count; i++)
            {
                ConditionLog(t->condition_table[i]);
            }

            printf("\n ==================================\n");
        }
    }

    return hasPassed;
}

void TestSetVerbose(Test t, int is_verbose)
{
    if (t == NULL)
    {
        return;
    }

    t->is_verbose = is_verbose;
}

int TestSetCondition(Test t, Condition c)
{
    if (t == NULL || c == NULL)
    {
        return 0;
    }

    if (t->condition_count == t->condition_capacity - 1)
    {
        int newCapacity = CONDITION_TABLE_GROWTH_FACTOR * t->condition_capacity;
        Condition *newMemory = (Condition *)realloc(t->condition_table, sizeof(Condition) * newCapacity);

        if (newMemory == NULL)
        {
            return 0;
        }

        t->condition_table = newMemory;
        t->condition_capacity = newCapacity;
    }

    t->condition_table[t->condition_count] = c;
    t->condition_count++;

    return 1;
}

int TestFree(Test t)
{
    if (t == NULL)
    {
        return 0;
    }

    for (int i = 0; i < t->condition_count; i++)
    {
        ConditionFree(t->condition_table[i]);
    }

    free(t->condition_table);
    free(t->name);

    free(t);

    return 1;
}

static void s_logResult(Test t, int result, double duration)
{
    printf(" ");
    if (result)
    {
        LOG_GREEN("PASSED")
    }
    else
    {
        LOG_RED("FAILED");
    }
    printf(GREEN"PASSED"NORM" | %s | ( %fms )\n", t->name, duration);

    left("┃", "┃", GREEN"PASSED"NORM" | %s | ( %fms )", t->name, duration);

}

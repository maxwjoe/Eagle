#include "EagleCondition.h"
#include "stdlib.h"
#include "string.h"
#include "EagleMacros.h"

typedef struct condition
{
    char *name;
    int condition_value;
} *Condition;

Condition ConditionNew(char *condition_name, int condition_value)
{
    if (condition_name == NULL)
    {
        return NULL;
    }

    Condition c = (Condition)malloc(sizeof(struct condition));

    if (c == NULL)
    {
        return NULL;
    }

    size_t name_length = strlen(condition_name);
    c->name = (char *)calloc(name_length + 1, sizeof(char));
    memcpy(c->name, condition_name, name_length);

    if (c->name == NULL)
    {
        free(c);
        return NULL;
    }

    c->condition_value = condition_value;

    return c;
}

int ConditionGetValue(Condition c)
{
    if (c == NULL)
    {
        return -1;
    }

    return c->condition_value;
}

void ConditionLog(Condition c)
{
    if (c == NULL)
    {
        return;
    }
    printf("  ");
    if (c->condition_value == 1)
    {
        LOG_GREEN("PASS");
    }
    else
    {
        LOG_RED("FAIL");
    }
    printf(" | %s\n", c->name);
}

int ConditionFree(Condition c)
{
    if (c == NULL)
    {
        return 0;
    }

    free(c->name);
    free(c);

    return 1;
}

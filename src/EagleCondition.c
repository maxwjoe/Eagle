#include "EagleCondition.h"
#include "stdlib.h"
#include "string.h"

typedef struct condition
{
    const char *name;
    int condition_value;
} *Condition;

Condition ConditionNew(const char *condition_name, int condition_value)
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
    c->name = (const char *)malloc(sizeof(char) * name_length);

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

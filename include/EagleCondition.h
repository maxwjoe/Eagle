#ifndef EAGLE_CONDITION_H
#define EAGLE_CONDITION_H

// Condition : ADT to define a test condition
typedef struct condition *Condition;

// ConditionNew : Creates a new condition
Condition ConditionNew(const char *condition_name, int condition_value);

// ConditionGetValue : Returns the value of a condition
int ConditionGetValue(Condition c);

// ConditionFree : Frees a condition
int ConditionFree(Condition c);

#endif
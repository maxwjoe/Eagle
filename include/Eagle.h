#ifndef EAGLE_H
#define EAGLE_H

#include "EagleTypes.h"

// Eagle : ADT to interact with the Eagle Testing API
typedef struct eagle *Eagle;

// EagleNew : Creates a new eagle instance
Eagle EagleNew();

// EagleSetVerbose : Sets output level (Verbose is detailed)
int EagleSetVerbose(Eagle e, int is_verbose);

// EagleAddCollection : Adds a new collection
int EagleAddCollection(Eagle e, char *collection_name);

// EagleAddTest : Adds a test to a specified collection
int EagleAddTest(Eagle e, char *collection_name, char *test_name, unitTestPtr test);

// EagleRunAll : Runs all tests
int EagleRunAll(Eagle e);

// EagleRunCollection : Runs all tests in a given collection
int EagleRunCollection(Eagle e, char *collection_name);

// EagleFree : Frees all memory associated with an Eagle instance
int EagleFree(Eagle e);

#endif
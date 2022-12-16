#ifndef EAGLE_MACROS_H
#define EAGLE_MACROS_H

// EAGLE_INIT : Performs all setup tasks
#define EAGLE_INIT(__VERBOSE__)         \
    Eagle *__EAGLE_PTR__ = new Eagle(); \
    __EAGLE_PTR__->SetVerbose(__VERBOSE__)

// EAGLE_EXIT : Cleans up all memory
#define EAGLE_EXIT() delete __EAGLE_PTR__

// TEST : Defines a new unit test
#define TEST(__TEST_NAME__) void __TEST_NAME__(Test *__EAGLE_TEST_CLASS_REFERENCE__)

// ADD_TEST : Adds a test of a given name to the given collection
#define ADD_TEST(__COLLECTION_NAME__, __TEST_NAME__) \
    __EAGLE_PTR__->AddTest(#__COLLECTION_NAME__, #__TEST_NAME__, &__TEST_NAME__)

// RUN_ALL_TESTS : Runs all tests across all collections
#define RUN_ALL_TESTS() __EAGLE_PTR__->RunAll()

// RUN_COLLECTION : Runs a given collection
#define RUN_COLLECTION(__COLLECTION_NAME__) __EAGLE_PTR__->RunCollection(#__COLLECTION_NAME__)

// CHECK_TRUE : Checks if the given condition is true
#define CHECK_TRUE(__BOOLEAN_EXPRESSION__) __EAGLE_TEST_CLASS_REFERENCE__->SetCondition(#__BOOLEAN_EXPRESSION__, __BOOLEAN_EXPRESSION__)

// CHECK_FALSE : Checks if the given condition is false
#define CHECK_FALSE(__BOOLEAN_EXPRESSION__) CHECK_TRUE(!(__BOOLEAN_EXPRESSION__))

// CHECK_GREATER : Checks if A is Strictly Greater than B
#define CHECK_GREATER(__VARIABLE_A__, __VARIABLE_B__) CHECK_TRUE((__VARIABLE_A__ > __VARIABLE_B__))

// CHECK_LESS : Checks if A is Strictly Less than than B
#define CHECK_LESS(__VARIABLE_A__, __VARIABLE_B__) CHECK_TRUE((__VARIABLE_A__ < __VARIABLE_B__))

// CHECK_EQ : Checks if two values are equal
#define CHECK_EQ(__VARIABLE_A__, __VARIABLE_B__) CHECK_TRUE((__VARIABLE_A__ == __VARIABLE_B__))

// CHECK_NEQ : Checks if two variables are not equal
#define CHECK_NEQ(__VARIABLE_A__, __VARIABLE_B__) CHECK_TRUE((__VARIABLE_A__ != __VARIABLE_B__))

// RUN_TEST : Runs a single test in a given collection
#define RUN_TEST(__COLLECTION_NAME__, __TEST_NAME__) __EAGLE_PTR__->RunTest(#__COLLECTION_NAME__, #__TEST_NAME__)

// LOG_GREEN : Logs green text
#define LOG_GREEN(TEXT) std::cout << "\e[0;32m" << TEXT << "\x1b[0m"

// LOG_RED : Logs red text
#define LOG_RED(TEXT) std::cout << "\e[0;31m" << TEXT << "\x1b[0m"

// LOG_HEAVY : Logs to the console in bold and underline
#define LOG_HEAVY(TEXT) std::cout << "\x1B[1m\x1B[4m" << TEXT << "\x1b[0m";

// LOG_GREEN_HEAVY : Logs green text that is both bold and underlined
#define LOG_GREEN_HEAVY(TEXT) std::cout << "\e[0;32m\x1B[1m\x1B[4m" << TEXT << "\x1b[0m"

// LOG_RED_HEAVY : Logs red text that is both bold and underlined
#define LOG_RED_HEAVY(TEXT) std::cout << "\e[0;31m\x1B[1m\x1B[4m" << TEXT << "\x1b[0m"

#endif
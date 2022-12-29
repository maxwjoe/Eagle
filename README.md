# Eagle : Simple C/C++ Unit Testing

## About

Eagle provides a simple solution for unit testing both C and C++ code. It is written entirely in C and has no dependencies outside of the C standard library. Eagle features an easy to use API and a minimal setup process making it quick and easy to start testing.

## Setup

To use Eagle you must include "Eagle.h". Ensure that you have built the library, this can be done by simply typing "make" in the root of this repository after cloning which will generate a Library that you can link against. The current makefile is setup to use gcc, if you would like to use C++ you can simply change this to whatever compiler you require.

## Writing a Unit Test

> **Note : All code presented in this document can be found in the examples folder in this repository**

To write a unit test, use the TEST() macro. This takes the test name as a parameter, then define your testing logic between the curly braces. Eagle enables you to make assertions with its built in assertion macros. An example of Eagle unit tests are shown below. 

```C
TEST(T_ADD)
{
    int a = 5;
    int b = 4;

    int sum = addNumbers(a, b);

    CHECK_EQ(sum, 9);
}

TEST(T_MULT)
{
    int a = 6;
    int b = -2;

    int prod = multNumbers(a, b);

    CHECK_TRUE(prod < 0);
    CHECK_EQ(prod, -12);
}

TEST(T_FAIL)
{
    int a = 5;
    a++;

    CHECK_TRUE(a > 0);
    CHECK_FALSE(a % 5 == 1);
    CHECK_EQ(a, 6);
}
```

All unit tests in Eagle are void, so there is no need to return anything from them. Simply use the built in macros to check any conditions you need. Also note that by default tests will pass if you do not set any conditions.

## Assertion Macros

The above example uses assertions inside the TEST() definition to check conditions within your tests. The assertions available in Eagle are defined below.

* CHECK_TRUE(A) : Checks that A is true
* CHECK_FALSE(A) : Checks that A is false
* CHECK_GREATER(A, B) : Checks that A is strictly greater than B
* CHECK_LESS(A, B) : Checks that A is strictly less than B
* CHECK_EQ(A, B) : Checks that A is equal to B
* CHECK_NEQ(A, B) : Checks that A is not equal to B

You can use as many assertions as you like within a single unit test, there is no limit.

## Running Tests

Eagle requires an entry point in the form of a main() function. Below is an example of how to run the tests that you have defined. 

```C
int main()
{
    EAGLE_INIT();

    ADD_TEST(SIMPLE_MATH, T_ADD);
    ADD_TEST(SIMPLE_MATH, T_FAIL);
    ADD_TEST(SIMPLE_MATH, T_MULT);

    RUN_ALL();

    EAGLE_END();
}
```

The above program will run all unit tests. An explanation can be found below.

* EAGLE_INIT() : Performs all necessary setup tasks for Eagle to work properly
* ADD_TEST(CollectionName, TestName) : Adds a unit test to a collection. You must use the same test name as u did when calling TEST()
* RUN_ALL() : Runs all unit tests across all collections
* EAGLE_END() : Frees up memory (Optional)

## Collections

The previous section called a function ADD_TEST(CollectionName, TestName). This involved adding tests to a collection. In Eagle, Collections are a way to group your tests together. In the above example there is only one collection "SIMPLE_MATH". However, there is no limit on how many collections you can have. An example below shows how you can define multiple collections and run them individually.

```C
int main()
{
    EAGLE_INIT();
    
    ADD_TEST(COLLECTION_ONE, T_ONE);
    ADD_TEST(COLLECTION_ONE, T_TWO);
    ADD_TEST(COLLECTION_ONE, T_THR);
    
    ADD_TEST(COLLECTION_TWO, T_FOU);
    ADD_TEST(COLLECTION_TWO, T_FIV);
    
    RUN_COLLECTION(COLLECTION_TWO);
    
    EAGLE_END();
}
```

The above snippet has two collections, "COLLECTION_ONE" and "COLLECTION_TWO". The function RUN_COLLECTION(CollectionName) is called on COLLECTION_TWO. This will run all unit tests in COLLECTION_TWO, in this case T_FOU and T_FIV. If you wanted to run all tests across all collections you could simply just call RUN_ALL().

## Console Output

Eagle allows you to control the level of output you see in the console. If you want to see the result of every individual test you can set the verbose variable to true (this is on by default). If you only want to see a summary of all tests at the end, then you can set this to false. This is done through the EAGLE_SET_VERBOSE(0) Macro. Ideally, you should call this after calling EAGLE_INIT() in your main function. 

An example verbose output for running the SIMPLE_MATH collection can be seen below.

![image](https://user-images.githubusercontent.com/76637128/210017352-bc61a2a2-7bfd-4380-94a8-139cc702c205.png)

Note that each failed test has a condition breakdown where all set conditions inside the unit test are displayed with their status, either pass or fail. In this case (a % 5 == 1) happens to be true, meaning that the assertion that its false will fail. Showing this breakdown in combination with the passed conditions can make debugging your code easier. If you wish to hide these outputs, call EAGLE_SET_VERBOSE(0) inside of main(), this will generate the following simple output for the same collection of tests.

![image](https://user-images.githubusercontent.com/76637128/210017801-d7330235-fb74-4483-b0b2-c5220ba85c01.png)

## Future Features

1. Test timeouts





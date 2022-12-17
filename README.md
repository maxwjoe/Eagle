# Eagle : Simple C/C++ Unit Testing

## About

Eagle provides a simple solution for testing C and C++ code.

## Example API Usage

### Writing Unit Tests

Create tests using TEST, pass the test name as a parameter and define the logic within the curly braces. Below is an example on how to use the 
TEST API to declare your unit tests. Notice that all assertions are handled using built in macros.

**Assertion Macro Definitions**
* CHECK_EQ(A, B) : Checks if A and B are the same
* CHECK_NEQ(A, B) : Checks if A is not Equal to B
* CHECK_TRUE(A) : Checks if Expression A is True
* CHECK_FALSE(A) : Checks if Expression A is False
* CHECK_GREATER(A, B) : Checks if A is strictly greater than B
* CHECK_LESS(A, B) : Checks if A is strictly less than B

#### Example Unit Tests

```C++

TEST(T_POS_ADDITION)
{
    int a = 5;
    int b = 4;

    int result = addition(a, b);

    CHECK_EQ(result, 9);
}

TEST(T_NEG_ADDITION)
{
    int a = 5;
    int b = -4;

    int result = addition(a, b);

    CHECK_EQ(result, 1);
}

TEST(T_POS_MULTIPLY)
{
    int a = 5;
    int b = 4;

    int result = multiplication(a, b);
    CHECK_EQ(result, 20);
}

TEST(T_COMPOUND_TEST)
{
    int a = 5;
    int b = -7;

    int sum = addition(a, b);

    CHECK_EQ(sum, -2);

    int square = multiplication(sum, sum);

    CHECK_TRUE(square > 0);
}

TEST(T_WILL_FAIL)
{
    int a = 5;
    int b = 4;

    CHECK_NEQ(a, b);
    CHECK_EQ(a, b);
    CHECK_LESS(a, b);
    CHECK_GREATER(a, b);
}

TEST(T_WILL_PASS)
{
    CHECK_TRUE(true);
}

TEST(T_ANOTHER_PASS)
{
    CHECK_NEQ(5, 6);
}

```

### Running Unit Tests

#### Setup

To run tests you must give Eagle an entry point in the form of a function main(), which calls EAGLE_INIT(verbose). Passing true will set the output 
mode to verbose, which shows individual test summaries. Passing false will minimise the information shown in the console. 

#### Collections and Adding Tests

Eagle groups tests into collections so that you can test related components together. Collections are automatically handled behind the scenes, all that you need to do is call ADD_TEST(COLLECTION_NAME, TEST_NAME) using whatever COLLECTION_NAME you like and the same TEST_NAME as you used when calling TEST() to define the test. 

#### Running Tests

There are three ways to run tests in Eagle

1. RUN_ALL_TESTS() : This will run every test across every collection
2. RUN_COLLECTION(COLLECTION_NAME) : This will run every test in COLLECTION_NAME
3. RUN_TEST(COLLECTION_NAME, TEST_NAME) : This will run a single test in the specified collection


```C++
int main()
{
    // === SETUP ===
    EAGLE_INIT(true);

    // === Add Tests ===
    ADD_TEST(EXAMPLE, T_POS_ADDITION);
    ADD_TEST(EXAMPLE, T_NEG_ADDITION);
    ADD_TEST(EXAMPLE, T_POS_MULTIPLY);
    ADD_TEST(EXAMPLE, T_COMPOUND_TEST);
    ADD_TEST(EXAMPLE, T_WILL_FAIL);
    ADD_TEST(EXAMPLE, T_WILL_PASS);
    ADD_TEST(EXAMPLE, T_ANOTHER_PASS);

    // === RUN ===
    RUN_ALL_TESTS();

    EAGLE_EXIT();
}
```

### Example Output

Below is the testing output from the example shown

![eagleoutput](https://user-images.githubusercontent.com/76637128/208039787-ad6fae16-1e76-4209-9b0c-390cfc9333fd.png)


## Comments

Eagle is still being developed and improved upon.

#### 


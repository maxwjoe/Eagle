# Eagle : Simple C/C++ Testing

### About

Eagle provides a simple solution for testing C and C++ code. Below is an example of how to use Eagle's API.

### Example API Usage

#### Creating Unit Tests

Create tests using TEST. Then add any required assertions with CHECK.

```C++

TEST(T_MATH_ONE)
{
  int sum = 5 + 5;
  CHECK_EQ(sum, 5);
}

TEST(T_MATH_TWO)
{
  int value = 5;
  int result = makeSmaller(value);
  
  CHECK_LESS(result, value);
}

TEST(T_STRING_ONE)
{
  MyStringClass s = GetString();
  
  CHECK_FALSE((S == NULL));
}

```

#### Running Your Tests

The following code snippet demonstrates how to run the tests defined above.

```C++



int main()
{
  
  // Runs setup tasks
  EAGLE_INIT(true);
  
  // Add tests to a collection (Collection creation is automatic)
  ADD_TEST(MATH_COLLECTION, T_MATH_ONE);
  ADD_TEST(MATH_COLLECTION, T_MATH_TWO);
  ADD_TEST(STRING_COLLECTION, T_STRING_ONE);
  
  // Run all tests across all collections
  RUN_ALL_TESTS();
  
  // Cleanup tasks
  EAGLE_EXIT();
}

```

### Example Output

![image](https://user-images.githubusercontent.com/76637128/207509854-e6040262-daa2-4b4b-b3ff-0999a4b474a2.png)


### Comments

Eagle is still being developed and improved upon.

#### 

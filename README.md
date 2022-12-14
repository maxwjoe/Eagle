# Eagle : Simple C/C++ Testing

### About

Eagle provides a simple solution for testing C and C++ code. Below is an example of how to use Eagle's API.

### API Usage

#### Creating a Unit Test

Unit tests must return an integer and take no parameters, an example unit test is shown below.

```C++

int T_MY_ADD_FUNCTION()
{
  int x = 5;
  int y = 4;
  
  int result = myAddFunction(x, y);
  
  return (result == 9);
}

```

#### Collections

Eagle groups your tests into collections. You then have the option to either run a test individually, run a collection individually, or run all tests.
Collections are useful as they allow you to test related aspects of your code together, an example is shown below. 

```C++

#define MATH_COL "Mathematics"
#define STRING_COL "String Operations"

int main()
{
  
  // Create an eagle testing object
  Eagle *e = new Eagle();
  
  // SetVerbose : When true, will show all test details in console upon execution
  e->SetVerbose(true);
  
  // Add tests, collection creation handled behind the scenes
  e->AddTest(MATH_COL, "Simple Addition", &T_MY_ADD_FUNCTION);
  e->AddTest(MATH_COL, "Simple Multiplication", &T_MY_MULT_FUNCTION);
  e->AddTest(MATH_COL, "Simple Division", &T_MY_DIV_FUNCTION);
  e->AddTest(MATH_COL, "Simple Subtraction", &T_MY_SUB_FUNCTION);
  
  e->AddTest(STRING_COL, "Simple Concatenation", &T_MY_CONCAT_FUNCTION);
  e->AddTest(STRING_COL, "Simple Copy", &T_MY_COPY_FUNCTION);
  
  e->RunAll(); // Will run all tests across all collections
  
  e->RunCollection(MATH_COL) // Runs all tests within the Mathematics collection
  e->RunCollection(STRING_COL) // Runs all tests within the String Operations collection
  
  e->RunTest(MATH_COL, "Simple Addition") // Runs only the Simple Addition Test Case
  
  // Memory cleanup
  delete e;
  
}

```

### Example Output

![image](https://user-images.githubusercontent.com/76637128/207509854-e6040262-daa2-4b4b-b3ff-0999a4b474a2.png)


### Comments

Eagle is still being developed and improved upon.

#### 

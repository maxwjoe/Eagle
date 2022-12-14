#include "EagleTestClass.h"
#include <iostream>
#include <chrono>

// Test::Test : Default Constructor
Test::Test()
    : m_unit_test(nullptr), m_test_name({})
{
}

// Test::Test : Constructor for Test Class
Test::Test(std::string test_name, testFuncPtr func)
    : m_unit_test(func), m_test_name(test_name)
{
}

// Test::~Test : Destructor for Test Class
Test::~Test() {}

// Test::GetTestName : Returns the name of a test
std::string Test::GetTestName()
{
    return m_test_name;
}

// Test::SetVerbose : Set verbose value (Detailed test output)
void Test::SetVerbose(bool is_verbose)
{
    m_verbose = is_verbose;
}

// Test::Run : Runs a test, returns the result
bool Test::Run()
{
    if (!m_unit_test)
    {
        return false;
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    bool result = m_unit_test();

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> time_passed = end_time - start_time;
    double time_elapsed = time_passed.count();

    if (m_verbose)
    {
        m_LogResult(result, time_elapsed);
    }

    return result;
}

// Test::m_LogResult : Logs test result to console
void Test::m_LogResult(const bool &result, const double &time_passed) const
{

    std::cout << " " << (result ? "\e[0;32mPASSED" : "\e[0;31mFAILED") << "\x1b[0m | ";

    std::cout << m_test_name << " | ( " << time_passed << "ms )" << std::endl;
}
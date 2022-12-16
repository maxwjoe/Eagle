#include "EagleTestClass.h"
#include <iostream>
#include <chrono>

// Test::Test : Default Constructor
Test::Test()
    : m_unit_test(nullptr), m_test_name({}), m_condition_table({}), m_verbose(false)
{
}

// Test::Test : Constructor for Test Class
Test::Test(std::string test_name, testFuncPtr func)
    : m_unit_test(func), m_test_name(test_name), m_condition_table({}), m_verbose(false)
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

// Test::SetCondition : Sets a condition into the condition table
void Test::SetCondition(std::string condition_name, bool condition_value)
{
    m_condition_table.push_back({condition_name, condition_value});
}

// Test::Run : Runs a test, returns the result
bool Test::Run()
{
    if (!m_unit_test)
    {
        return false;
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    bool result = m_unit_test(this);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> time_passed = end_time - start_time;
    double time_elapsed = time_passed.count();

    // Check all conditions against condition table
    for (int i = 0; i < m_condition_table.size(); i++)
    {
        if (!m_condition_table[i].value)
        {
            // TODO: Change to a logging function
            std::cout << "CONDITION FAILED : " << m_condition_table[i].description << std::endl;
            result = false;
        }
    }

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
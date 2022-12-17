#include "EagleTestClass.h"
#include "EagleMacros.h"
#include <iostream>
#include <thread>
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

    // --- Run and time the test ---
    bool result = true;

    auto start_time = std::chrono::high_resolution_clock::now();

    m_unit_test(this);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> time_passed = end_time - start_time;
    double time_elapsed = time_passed.count();

    // --- Check all conditions in condition table are true ---
    size_t condition_count = m_condition_table.size();

    for (int i = 0; i < condition_count; i++)
    {
        if (!m_condition_table[i].value)
        {
            result = false;
            break;
        }
    }

    // --- Show output ---
    if (m_verbose)
    {

        // Print Failed Conditions
        if (!result)
        {
            std::cout << "\n ==================================\n"
                      << std::endl;
            m_LogResult(result, time_elapsed);
            std::cout << "\n Condition Summary For Failed Test :\n"
                      << std::endl;
            for (int i = 0; i < condition_count; i++)
            {
                std::cout << "   ";
                if (!m_condition_table[i].value)
                {
                    LOG_RED("FAIL");
                }
                else
                {
                    LOG_GREEN("PASS");
                }
                std::cout << " | " << i + 1 << ". " << m_condition_table[i].description << std::endl;
            }
            std::cout << std::endl;
            std::cout << " ==================================\n"
                      << std::endl;
        }
        else
        {
            m_LogResult(result, time_elapsed);
        }
    }

    return result;
}

// Test::m_LogResult : Logs test result to console
void Test::m_LogResult(const bool &result, const double &time_passed) const
{
    std::cout << " ";

    if (result)
    {
        LOG_GREEN("PASSED");
    }
    else
    {
        LOG_RED("FAILED");
    }

    std::cout << " | " << m_test_name << " | ( " << time_passed << "ms )" << std::endl;
}

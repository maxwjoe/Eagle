#include <iostream>
#include <chrono>
#include "EagleTestClass.h"

Test::Test(std::string &testName, testPtr testFunction)
{
    if (testFunction == NULL)
    {
        std::cout << "TEST CREATE ERROR : Invalid Test Params" << std::endl;
        exit(EXIT_FAILURE);
    }

    m_name = std::string(testName);
    m_pointer = testFunction;
};

Test::~Test(){};

bool Test::run(bool showOutput)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    int result = m_pointer();
    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> time_passed = t2 - t1;
    double timeElapsed = time_passed.count();

    if (showOutput)
    {
        m_logResult(result, timeElapsed);
    }

    return result;
};

std::string Test::getName()
{
    return m_name;
}

void Test::m_logResult(bool hasPassed, double timeElapsed)
{

    if (hasPassed)
    {
        std::cout << "\e[0;32mPASSED\x1b[0m\t";
    }
    else
    {
        std::cout << "\e[0;31mFAILED\x1b[0m\t";
    }

    std::cout << m_name << " | ( " << timeElapsed << "ms )" << std::endl;
};
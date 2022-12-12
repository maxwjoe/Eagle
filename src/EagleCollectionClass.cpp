#include <iostream>
#include "EagleCollectionClass.h"

Collection::Collection(std::string &collectionName)
    : m_testCount(0), m_numPassed(0), m_numRun(0), m_tests({})
{
    m_name = std::string(collectionName);
}

Collection::~Collection() {}

// Collection::addTest : Adds a test to a collection
void Collection::addTest(std::string &testName, testPtr testFunction)
{
    if (testFunction == NULL)
    {
        std::cout << "COLLECTION ADD TEST ERROR : Invalid Test Params" << std::endl;
        exit(EXIT_FAILURE);
    }

    m_tests.push_back(Test(testName, testFunction));
    m_testCount++;
}

// Collection::runTest : Runs a single test in a collection
bool Collection::runTest(std::string &testName, bool showOutput)
{
    bool hasPassed = false;
    for (int i = 0; i < m_testCount; i++)
    {
        std::string name = m_tests[i].getName();

        if (testName == name)
        {
            hasPassed = m_tests[i].run(showOutput);
        }
    }

    return hasPassed;
}

std::string Collection::getName()
{
    return m_name;
}

// Collection::runAll : Runs all tests in a collection
void Collection::runAll(bool showOutput)
{

    if (showOutput)
    {
        std::cout << "\n--- Running Collection : " << m_name << " ---\n"
                  << std::endl;
    }

    for (int i = 0; i < m_testCount; i++)
    {
        m_tests[i].run(showOutput);
    }
}
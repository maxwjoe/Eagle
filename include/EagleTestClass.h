#ifndef EAGLE_TEST_CLASS_H
#define EAGLE_TEST_CLASS_H

#include <string>
#include <vector>
#include "EagleCommon.h"

class Test
{
public:
    Test(std::string &testName, testPtr testFunction);
    // Test(Test &) = delete;
    ~Test();

    // Test::run : Runs test and returns result (Prints result if bool = true)
    bool run(bool showOutput);

    // Test::getName : Returns name of test
    std::string getName();

private:
    void m_logResult(bool hasPassed, double timeElapsed);

private:
    std::string m_name;
    testPtr m_pointer;
};

#endif
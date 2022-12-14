#ifndef EAGLE_TEST_CLASS_H
#define EAGLE_TEST_CLASS_H

#include <string>
#include "EagleTypes.h"

// === Eagle Test Class : Defines a Test Object ===

// GOAL: See if you can track variable values

class Test
{
public:
    Test();
    Test(std::string test_name, testFuncPtr func);
    ~Test();

    std::string GetTestName();
    void SetVerbose(bool is_verbose);

    bool Run();

private:
    void m_LogResult(const bool &result, const double &time_passed) const;

private:
    testFuncPtr m_unit_test;
    std::string m_test_name;
    bool m_verbose;
};

#endif
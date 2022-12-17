#ifndef EAGLE_TEST_CLASS_H
#define EAGLE_TEST_CLASS_H

#include <string>
#include <vector>
#include "EagleTypes.h"

// === Condition : Holds information for Condition Table Entry ===
struct Condition
{
    std::string description;
    bool value;
};

// === Eagle Test Class : Defines a Test Object ===

class Test
{
public:
    Test();
    Test(std::string test_name, testFuncPtr func);
    ~Test();

    std::string GetTestName();
    void SetVerbose(bool is_verbose);

    void SetCondition(std::string condition_name, bool condition_value);

    bool Run();

private:
    void m_LogResult(const bool &result, const double &time_passed) const;

private:
    testFuncPtr m_unit_test;
    std::string m_test_name;
    std::vector<Condition> m_condition_table;
    bool m_verbose;
    int m_timeout_seconds;
};

#endif
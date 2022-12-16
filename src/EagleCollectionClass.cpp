#include "EagleCollectionClass.h"
#include "EagleMacros.h"
#include <iostream>

// Collection::Collection : Default Constructor for Collection Class
Collection::Collection()
    : m_collection_name({}), m_tests({}), m_num_tests(0), m_verbose(false)
{
}

// Collection::Collection : Constructor for Collection Class
Collection::Collection(std::string collection_name)
    : m_collection_name(collection_name), m_tests({}), m_num_tests(0), m_verbose(false)
{
}

// Collection::~Collection : Destructor for Collection Class
Collection::~Collection() {}

// Collection::SetVerbose : Sets verbose output mode
void Collection::SetVerbose(bool is_verbose)
{
    if (is_verbose == m_verbose)
    {
        return;
    }

    m_verbose = is_verbose;

    for (int i = 0; i < m_num_tests; i++)
    {
        m_tests[i].SetVerbose(is_verbose);
    }
}

// Collection::GetCollectionName : Returns name of collection
std::string Collection::GetCollectionName()
{
    return m_collection_name;
}

// Collection::AddTest : Adds a new test to the collection
void Collection::AddTest(const std::string test_name, const testFuncPtr func)
{
    Test newTest(test_name, func);
    newTest.SetVerbose(m_verbose);
    m_tests.push_back(newTest);
    m_num_tests++;
}

// Collection::RunTest : Runs a single test in collection, returns result (also false if not found)
bool Collection::RunTest(const std::string test_name)
{
    for (int i = 0; i < m_num_tests; i++)
    {
        if (m_tests[i].GetTestName() == test_name)
        {
            return m_tests[i].Run();
        }
    }

    return false;
}

// Collection::RunAll : Runs all tests in a collection and returns number passed
int Collection::RunAll()
{
    if (m_num_tests == 0)
    {
        std::cout << "\n--- Collection : " << m_collection_name << " IS EMPTY ---\n"
                  << std::endl;
        return 0;
    }

    int pass_count = 0;

    if (m_verbose)
    {
        LOG_HEAVY("\n COLLECTION : ");
        LOG_HEAVY(m_collection_name);
        std::cout << "\n"
                  << std::endl;
    }

    for (int i = 0; i < m_num_tests; i++)
    {
        pass_count += m_tests[i].Run();
    }

    LOG_HEAVY("\n COLLECTION SUMMARY : ");
    LOG_HEAVY(pass_count);
    LOG_HEAVY(" OF ");
    LOG_HEAVY(m_num_tests);
    LOG_HEAVY(" TESTS PASSED\n");
    std::cout << std::endl;

    return pass_count;
}

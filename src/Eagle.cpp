#include "Eagle.h"
#include <iostream>

// Eagle::Eagle : Constructor for Eagle Class
Eagle::Eagle()
    : m_collections({}), m_num_collections(0), m_num_tests(0), m_verbose(false)
{
}

// Eagle::~Eagle :: Destructor for Eagle Class
Eagle::~Eagle()
{
}

// Eagle::SetVerbose : Sets Log Level to Verbose (Detailed) or Simple
void Eagle::SetVerbose(const bool is_verbose)
{
    if (is_verbose == m_verbose)
    {
        return;
    }

    m_verbose = is_verbose;

    for (int i = 0; i < m_num_collections; i++)
    {
        m_collections[i].SetVerbose(is_verbose);
    }
}

// Eagle::AddTest : Adds a new test to a collection
void Eagle::AddTest(std::string collection_name, std::string test_name, testFuncPtr func)
{
    m_num_tests++;

    for (int i = 0; i < m_num_collections; i++)
    {
        if (m_collections[i].GetCollectionName() == collection_name)
        {
            m_collections[i].AddTest(test_name, func);
            return;
        }
    }

    Collection new_collection(collection_name);
    new_collection.AddTest(test_name, func);

    m_collections.push_back(new_collection);
    m_num_collections++;
}

// Eagle::RunTest : Runs an individual test (Always in verbose mode)
bool Eagle::RunTest(const std::string collection_name, const std::string test_name)
{
    for (int i = 0; i < m_num_collections; i++)
    {
        if (m_collections[i].GetCollectionName() == collection_name)
        {
            m_collections[i].SetVerbose(true);
            bool result = m_collections[i].RunTest(test_name);
            m_collections[i].SetVerbose(m_verbose);
            return result;
        }
    }

    return false;
}

// Eagle::RunCollection : Runs all tests in a given collection
void Eagle::RunCollection(const std::string collection_name)
{
    for (int i = 0; i < m_num_collections; i++)
    {
        if (m_collections[i].GetCollectionName() == collection_name)
        {
            m_collections[i].RunAll();
            return;
        }
    }

    std::cout << "\n=== Collection : " << collection_name << " Does Not Exist ===\n"
              << std::endl;
}

// Eagle::RunAll : Runs all tests across all collections
void Eagle::RunAll()
{
    int pass_count = 0;

    std::cout << "\n=== RUNNING ALL TESTS ===\n"
              << std::endl;

    for (int i = 0; i < m_num_collections; i++)
    {
        pass_count += m_collections[i].RunAll();
    }

    std::cout << "\n=== SUMMARY : " << pass_count << " of " << m_num_tests << " Test Cases Passed ===\n"
              << std::endl;
}

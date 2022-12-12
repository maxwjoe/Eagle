#include <iostream>
#include "Eagle.h"

Eagle::Eagle()
    : m_collections({}), m_verbose(false), m_numTests(0), m_numTestsRun(0), m_numTestsPassed(0)
{
}

Eagle::~Eagle() {}

void Eagle::addTest(std::string collectionName, std::string testName, testPtr testFunction)
{
    // Check for existing collection, add test to collection if found
    for (int i = 0; i < m_collections.size(); i++)
    {
        if (m_collections[i].getName() == collectionName)
        {
            m_collections[i].addTest(testName, testFunction);
            return;
        }
    }

    // Create a new collection and add the test
    Collection newCollection(collectionName);
    newCollection.addTest(testName, testFunction);

    m_collections.push_back(newCollection);
}

void Eagle::runTest(std::string collectionName, std::string testName)
{
    bool hasPassed = false;
    for (int i = 0; i < m_collections.size(); i++)
    {
        if (m_collections[i].getName() == collectionName)
        {
            hasPassed = m_collections[i].runTest(testName, m_verbose);
            break;
        }
    }
}

void Eagle::verbose(bool value)
{
    m_verbose = value;
}

void Eagle::runCollection(std::string collectionName)
{
    for (int i = 0; i < m_collections.size(); i++)
    {
        if (m_collections[i].getName() == collectionName)
        {
            m_collections[i].runAll(m_verbose);
            break;
        }
    }
}

void Eagle::runAll()
{
    for (int i = 0; i < m_collections.size(); i++)
    {
        m_collections[i].runAll(m_verbose);
    }
}

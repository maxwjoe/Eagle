#ifndef EAGLE_COLLECTION_CLASS_H
#define EAGLE_COLLECTION_CLASS_H

#include "EagleTestClass.h"

class Collection
{

public:
    Collection(std::string &collectionName);
    // Collection(Collection &) = delete;
    ~Collection();

    // Collection::addTest : Adds a test to a collection
    void addTest(std::string &testName, testPtr testFunction);

    // Collection::runTest : Runs a single test in a collection
    bool runTest(std::string &testName, bool showOutput);

    // Collection::runAll : Runs all tests in a collection
    void runAll(bool showOutput);

    // Collection::getName : Returns name of collection
    std::string getName();

private:
    std::string m_name;
    int m_testCount;
    int m_numPassed;
    int m_numRun;
    std::vector<Test> m_tests;
};

#endif
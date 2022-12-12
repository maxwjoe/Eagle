#ifndef EAGLE_H
#define EAGLE_H

#include <string>
#include <vector>
#include "EagleCommon.h"
#include "EagleCollectionClass.h"

class Eagle
{
public:
    Eagle();
    // Eagle(Eagle &) = delete;
    ~Eagle();

    void addTest(std::string collectionName, std::string testName, testPtr test);
    void runTest(std::string collectionName, std::string testName);
    void runCollection(std::string collectionName);
    void runAll();
    void verbose(bool value);

private:
    std::vector<Collection> m_collections;

    bool m_verbose;
    int m_numTests;
    int m_numTestsRun;
    int m_numTestsPassed;
};

#endif
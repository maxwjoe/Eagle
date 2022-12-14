#ifndef EAGLE_H
#define EAGLE_H

#include "EagleCollectionClass.h"
#include "EagleTypes.h"
#include <vector>
#include <string>

class Eagle
{
public:
    Eagle();
    Eagle(const Eagle &) = delete;
    ~Eagle();

    void SetVerbose(const bool is_verbose);

    void AddTest(std::string collection_name, std::string test_name, testFuncPtr func);

    bool RunTest(const std::string collection_name, const std::string test_name);
    void RunCollection(const std::string collection_name);
    void RunAll();

private:
    std::vector<Collection> m_collections;

    int m_num_collections;
    int m_num_tests;

    bool m_verbose;
};

#endif
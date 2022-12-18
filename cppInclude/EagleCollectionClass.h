#ifndef EAGLE_COLLECTION_CLASS_H
#define EAGLE_COLLECTION_CLASS_H

#include "EagleTestClass.h"
#include "EagleTypes.h"
#include <vector>
#include <string>

class Collection
{
public:
    Collection();
    Collection(std::string collection_name);
    ~Collection();

    int RunAll();
    bool RunTest(const std::string test_name);
    void AddTest(const std::string test_name, const testFuncPtr func);

    void SetVerbose(bool is_verbose);
    std::string GetCollectionName();

private:
    std::string m_collection_name;
    std::vector<Test> m_tests;

    int m_num_tests;
    bool m_verbose;
};

#endif
#include "Eagle.h"
#include "mymathfuncs.h"

#include "unitTests.cpp"

#define MATH_COL "Mathematics"

int main()
{
    // === SETUP ===
    Eagle *e = new Eagle();

    e->SetVerbose(true);

    // === Add Tests ===
    e->AddTest(MATH_COL, "Addition", &T_MY_ADDER);
    e->AddTest(MATH_COL, "Multiplication", &T_MY_MULT);
    e->AddTest(MATH_COL, "Equality", &T_MY_EQUAL);

    // === RUN ===
    e->RunAll();

    delete e;
}
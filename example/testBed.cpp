#include "Eagle.h"
#include "cases.cpp"

#define COL_MATH "SIMPLE_MATH"
#define COL_ALGO "SIMPLE_ALGO"

int main()
{
    Eagle *e = new Eagle();

    e->SetVerbose(true);

    e->AddTest(COL_MATH, "ADDITION", &T_ADD_NUMBERS);
    e->AddTest(COL_MATH, "SUBTRACTION", &T_SUB_NUMBERS);
    e->AddTest(COL_MATH, "MULTIPLICATION", &T_MULT_NUMBERS);
    e->AddTest(COL_MATH, "DIVISION", &T_DIV_NUMBERS);
    e->AddTest(COL_MATH, "MODULO", &T_MOD_NUMBERS);

    e->AddTest(COL_ALGO, "O(n)", &T_O_OF_N_ALGO);
    e->AddTest(COL_ALGO, "O(n^2)", &T_O_OF_NSQ_ALGO);
    e->AddTest(COL_ALGO, "O(n^3)", &T_O_OF_NCUB_ALGO);

    e->RunAll();

    delete e;
}
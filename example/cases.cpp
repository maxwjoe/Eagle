// CASES.CPP : DEFINES TEST CASES

int T_ADD_NUMBERS()
{
    int x = 5;
    int y = 4;
    return x + y == 9;
}

int T_SUB_NUMBERS()
{
    int x = 5;
    int y = 4;

    // This should fail
    return x - y == 99;
}

int T_MULT_NUMBERS()
{
    int x = 5;
    int y = 4;
    return x * y == 20;
}

int T_DIV_NUMBERS()
{
    int x = 20;
    int y = 5;
    return x / y == 4;
}

int T_MOD_NUMBERS()
{
    int x = 20;
    int y = 8;

    return x % y == 4;
}

int T_O_OF_N_ALGO()
{
    int n = 5;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
    }

    return count == n;
}

int T_O_OF_NSQ_ALGO()
{
    int n = 5;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count++;
        }
    }

    return count == n * n;
}

int T_O_OF_NCUB_ALGO()
{
    int n = 5;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {

                count++;
            }
        }
    }

    return count = n * n * n;
}
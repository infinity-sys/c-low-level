int same(int *a, int *b)
{
    *a = 1;
    *b = 2;
    return *a;
}

int other(int *a, float *b)
{
    *a = 1;
    *b = 2.0f;
    return *a;
}

int noalias(int *restrict a, int *restrict b)
{
    *a = 1;
    *b = 2;
    return *a;
}

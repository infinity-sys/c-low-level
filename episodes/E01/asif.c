int plain(void)
{
    int x = 1;
    x = 2;
    return x;
}

int keep(void)
{
    volatile int x = 1;
    x = 2;
    return x;
}

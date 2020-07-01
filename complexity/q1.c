int Q1(int n)
{
    int r = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            r += 1;
        }
    }

    return r;
}

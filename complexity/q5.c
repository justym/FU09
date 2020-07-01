int Q1(int n)
{
    int r = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                r += 1;
            }
        }
    }

    return r;
}

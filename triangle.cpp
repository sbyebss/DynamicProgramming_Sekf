#include <iostream>
// #include <cstdio>
// #include <algorithm>
using namespace std;
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    int d[101][100] = {0};
    // Read the numbers from scanf
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (j <= i)
            {
                scanf("%d", &d[i][j]);
                if (i != 0)
                {
                    if (j == 0)
                        d[i][j] += d[i - 1][j];
                    else if (i == j)
                        d[i][j] += d[i - 1][j - 1];
                    else
                        d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
                }
            }
        }
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        ans = max(ans, d[n - 1][i]);
    }
    printf("%d\n", ans);
}
// Refer to http://eppsnet.com/2018/05/competitive-programming-poj-1159-palindrome/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, a1[5001], a2[5001];
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    char s[5001];
    scanf("%d", &n);
    scanf("%s", s);
    int *dp = a1, *prev = a2;
    // j-- is because compare the reverse with the origin
    // j is only used for the index of the string
    // when i grows, the column becomes bigger
    //
    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            dp[i + 1] = max(dp[i], prev[i + 1]);
            if (s[i] == s[j])
                // dp[i + 1] = max(dp[i + 1], prev[i] + 1);
                dp[i + 1] = prev[i] + 1;
        }
        swap(prev, dp);
    }
    // dp is always the current column, so when it's over,
    // prev is always the last "current" column
    // so we need to use the prev all the time
    printf("%d\n", n - prev[n]);
    // int m;
    // scanf("%d", &m);
    // int n = m;
    // int i, j;
    // int D[m + 1][m + 1];
    // char x[m], y[m];
    // scanf("%s", x);
    // scanf("%s", y);
    // for (i = 0; i <= n; i++)
    //     D[i][0] = 0;
    // for (j = 0; j <= m; j++)
    //     D[0][j] = 0;
    // for (i = 1; i <= n; i++)
    // {
    //     for (j = 1; j <= m; j++)
    //     {
    //         if (x[i] == y[j])
    //             D[i][j] = D[i - 1][j - 1] + 1;
    //         else
    //             D[i][j] = max(D[i - 1][j], D[i][j - 1]);
    //     }
    // }
}

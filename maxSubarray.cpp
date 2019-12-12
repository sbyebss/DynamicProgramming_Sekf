// for(int i=1;i<=n;i++){
//    for(int j=1;j<=n;j++){
//       caculate the biggest sum of continuous column;
//    }
// }
// #include <cstdio>
// #include <iostream>
// #include <cstring>
// // #include <algorithm>
// using namespace std;

// Below is my previous failed try
// int n = 0;
// int a[100][100], sum[100][100] = {0};

// int main()
// {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &a[i][j]);
//             sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
//         }
//     }
//     int max, D_nm, D_n_1_m1, D_n_1_m2, D_n_m_11, D_n_m_12;
//     int i1 = 0, j1 = 0, i2 = n - 1, j2 = n - 1;
//     while (1)
//     {
//         D_nm = sumij(i1, i2, j1, j2);
//         D_n_1_m1 = sumij(i1 + 1, i2, j1, j2);
//         D_n_1_m2 = sumij(i1, i2 + 1, j1, j2);
//         D_n_m_11 = sumij(i1, i2, j1 + 1, j2);
//         D_n_m_12 = sumij(i1, i2, j1, j2 + 1);
//         // if (D_nm < D_n_1_m1)
//         // {
//         //     D_nm = D_n_1_m1;
//         //     i1++;
//         // }
//         // if (D_nm > D_n_1_m2)
//         // {
//         //     D_nm = D_n_1_m2;
//         //     i1++;
//         // }
//         if (i1 == i2 || j1 == j2)
//             break;
//     }
//     printf("%d", &max);
// }

// int Dnm_new(int ){}
// int sumij(int i1, int i2, int j1, int j2)
// {
//     return sum[i2 + 1][j2 + 1] - sum[i1 + 1][j2 + 1] - sum[i2 + 1][j1 + 1] + sum[i1 + 1][j1 + 1];
// }

#include <cstdio>
int a[100][100], sum[101][101], dp[101][101][101];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            dp[i][j][1] = sum[j][1] - sum[i - 1][1];
            for (int k = 1; k <= n; k++)
            {
                // 从第i行到第j行所有第k列元素的和保存在dp[i][j][k]里面。这个数组做好以后我们把所有纵向的可能都枚举出来了。
                dp[i][j][k] = sum[j][k] - sum[i - 1][k] - sum[j][k - 1] + sum[i - 1][k - 1];
                // 之后对于横向部分做 DP .然后找出最大和。
                if (dp[i][j][k - 1] > 0)
                    dp[i][j][k] += dp[i][j][k - 1];
                if (dp[i][j][k] > ans)
                    ans = dp[i][j][k];
            }
        }
    // if (ans == 0)
    // {
    //     ans = -1000000000;
    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < n; j++)
    //             if (ans < a[i][j])
    //                 ans = a[i][j];
    // }
    printf("%d\n", ans);
}

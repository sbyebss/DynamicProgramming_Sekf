// 状态转移：当 s1[i-1]!=s2[j-1]时,按照lcs可知由2个状态转移过来,dp[i-1][j],dp[i][j-1],因为dp[i][j]是以s2[j]为结尾构成的LCIS的长度。
// 所以s2[j-1]一定会包含在里面，所以舍去dp[i][j-1],只由dp[i-1][j] 转移过来。
// 当s1[i-1]==s2[j-1]，这时肯定要找前面s1[ii-1]==s2[jj-1]的最长且比s2[j-1]小的状态转移过来。
#include <stdio.h>
#include <string.h>
#define maxn 505
#define clr(x) memset(x, 0, sizeof(x))
int a[maxn];
int b[maxn];
int dp[maxn][maxn];
int path[maxn][maxn];
int ans[maxn];
int main()
{
    int l1, l2, i, j, ai, aj, mx, mj, res, tmp;
    while (scanf("%d", &l1) != EOF)
    {
        res = 0;
        clr(dp);
        clr(path);
        for (i = 1; i <= l1; i++)
            scanf("%d", &a[i]);
        scanf("%d", &l2);
        //  use l1 and l2 are much greater than n and m!!!
        for (i = 1; i <= l2; i++)
            scanf("%d", &b[i]);
        //  from the left side to the right side of a[];
        for (i = 1; i <= l1; i++)
        {
            // mx is the biggest length for the current i
            mx = 0;
            // for each i, find the LCIS through the whole b[];
            for (j = 1; j <= l2; j++)
            {
                dp[i][j] = dp[i - 1][j];
                // path records the same i, last number(in LCIS)'s j
                path[i][j] = -1;
                if (b[j] < a[i] && dp[i - 1][j] > mx)
                {
                    mx = dp[i - 1][j];
                    mj = j;
                }
                else if (a[i] == b[j])
                {
                    dp[i][j] = mx + 1;
                    path[i][j] = mj;
                }
                //  res is the LCIS that we first met
                if (res < dp[i][j])
                {
                    res = dp[i][j];
                    // this ai and aj must refer to a[ai]==b[aj]
                    // because structure could only be entered after max++;
                    ai = i;
                    aj = j;
                }
            }
        }
        printf("%d\n", res);
        tmp = res;
        while (tmp)
        {
            if (path[ai][aj] > -1)
            {
                ans[tmp--] = b[aj];
                aj = path[ai][aj];
            }
            ai--;
        }
        for (i = 1; i <= res; i++)
            printf("%d%c", ans[i], i == res ? '\n' : ' ');
    }
    return 0;
}

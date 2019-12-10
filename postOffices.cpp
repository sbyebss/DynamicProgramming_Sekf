#include <iostream>
// #include <cstdio>
#include <cstring>
// #include <algorithm>
using namespace std;
const int maxV = 301;
// const int maxP = 31;
const int INF = 1 << 20;
int main()
{
    // v=the number of villages,1 <= V <= 300
    // p=the number of post offices,1 <= P <= 30, P <= V
    int v, p, s = 0;
    int vilg[maxV] = {0};
    // ijBest[i][j]=the minimum distance when setting j post office among
    // the first i villages
    // Initialization: ijBest[i][1]=ijOne[1][i],ijBest[i][i]=0;
    // Recurrence:ijBest[i][j]=min(ijBest[i][j],ijBest[k][j-1]+ijOne[k+1][j])
    // (i>j),j-1<=k<i
    int ijBest[maxV][maxV] = {0};
    // ijOne[i][j]=the minimum distance for setting a post office between
    // i and j village
    // Recurrence:ijOne[i][j]=ijOne[i][j-1]+vilg[j]-vilg[(i+j)/2];
    int ijOne[maxV][maxV] = {0};
    while (scanf("%d %d", &v, &p) == 2)
    {
        int vilg[maxV] = {0};
        for (int i = 1; i <= v; i++)
        {
            scanf("%d", &vilg[i]);
        }
        // memset(ijOne, 0, sizeof(ijOne));
        // Caculate the ijOne for preparation
        for (int i = 1; i <= v; i++)
        {
            for (int j = i + 1; j <= v; j++)
            {
                // This fomula is quite interesting, you could just write from 3->4->5 points to prove
                ijOne[i][j] = ijOne[i][j - 1] + vilg[j] - vilg[(i + j) / 2];
                // cout << ijOne[i][j] << endl;
            }
        }
        // Initialize the ijBest
        for (int i = 1; i <= v; i++)
        {
            ijBest[i][i] = 0;
            ijBest[i][1] = ijOne[1][i];
            // cout << ijBest[i][1] << endl;
        }
        // Recurrence
        // From analyzing inseting two post offices. Because inserting one post
        // office has been analyzed 
        for (int j = 2; j <= p; j++)
        {
            // For the recurrence, insert n posts into n villages has no discussion meaning
            for (int i = j + 1; i <= v; i++)
            {
                ijBest[i][j] = INF;
                for (int k = j - 1; k < i; k++)
                {
                    // On the base of having inserted j-1 post offices into k villages 
                    ijBest[i][j] = min(ijBest[i][j], ijBest[k][j - 1] + ijOne[k + 1][i]);
                }
                // cout<<ijBest[i][j]<<endl;
            }
        }
        printf("%d\n", ijBest[v][p]);
    }
    return 0;
}

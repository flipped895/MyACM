//海贼王之伟大航路：http://bailian.openjudge.cn/practice/4124
#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=20;
const int INF=1e6;
int n;
int mapp[MAX][MAX];
int dp[1<<MAX][MAX];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mapp[i][j]);
        }
    }
    for(int i=0;i<(1<<MAX);i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++)
    {
        dp[(1<<i)+1][i]=mapp[0][i];
    }
    for(int i=1;i<(1<<n);i++)
    {
        if(i&1)
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            for(int k=0;k<n;k++)
            {
                if((i&(1<<k))&&(k!=j))
                {
                    dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+mapp[k][j]);
                }
            }
        }
    }
    printf("%d\n",dp[(1<<n)-1][n-1]);
    return 0;
}
/*
4
0 10 20 999
5 0 90 30
99 50 0 10
999 1 2 0
*/
/*
5
0 18 13 98 8
89 0 45 78 43
22 38 0 96 12
68 19 29 0 52
95 83 21 24 0
*/
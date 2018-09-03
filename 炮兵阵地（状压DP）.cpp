//炮兵阵地：http://poj.org/problem?id=1185
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX=110;
int status[MAX],top;
int mapp[MAX];
int num[MAX];
int dp[MAX][MAX][MAX];//第i行在状态j时且i-1行为k时最大值
bool check(int a)
{
    if(a&(a<<1)) return false;
    if(a&(a<<2)) return false;
    return true;
}
int found(int a)
{
    int cnt=0;
    while(a)
    {
        a&=(a-1);
        cnt++;
    }
    return cnt;
}
void init(int n,int m)
{
    top=0;
    for(int i=0;i<(1<<m);i++)
    {
        if(check(i))
        {
            status[top]=i;
            num[top++]=found(i);
        }
    }
}
int main()
{
    memset(status,0,sizeof status);
    memset(mapp,0,sizeof mapp);
    memset(dp,0,sizeof dp);
    int n,m;
    scanf("%d %d",&n,&m);
    init(n,m);
    for(int i=0;i<n;i++)
    {
        getchar();
        for(int j=0;j<m;j++)
        {
            char c=getchar();
            if(c=='H')
            {
                mapp[i]|=(1<<j);
            }
        }
    }
    for(int i=0;i<top;i++)//初始化第0行
    {
        if(!(status[i]&mapp[0]))
        {
            dp[0][i][0]=num[i];
        }
    }
    for(int i=1;i<n;i++)//第i行
    {
        for(int j=0;j<top;j++)//在状态j
        {
            if(!(status[j]&mapp[i]))
            for(int k=0;k<top;k++)//且i-1行为状态k时
            {
                if(!(status[k]&status[j]))
                for(int l=0;l<top;l++)
                {
                    /*
                    if(status[j]&status[l]) continue;
                    if(status[k]&status[l]) continue;
                    if(dp[i-1][k][l])
                    */
                    if(!(status[j]&status[l])&&!(status[k]&status[l])&&dp[i-1][k][l])
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+num[j]);
                    //cout<<dp[i][j][k]<<endl;
                }
            }
        }
    }
    int ans=0;
    //for(int i=0;i<n;i++)
    for(int j=0;j<top;j++)
    {
        for(int k=0;k<top;k++)
        {
            ans=max(ans,dp[n-1][j][k]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

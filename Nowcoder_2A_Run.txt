#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+5;
ll dp[maxn][2]={0};
//0表示最后一步是走的,1表示最后一步是跑的
ll sum[maxn]={0};
int main()
{
    int q,k,l,r;
    cin >> q >> k;
    for(int i=0;i<k;i++)
    {
        dp[i][0]=1;//全程走
        dp[i][1]=0;//全程跑
    }
    for(int i=k;i<=maxn;i++)//跑到i有多少种方法
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        //最后一步是走的 = 上一种情况 走的+跑的
        dp[i][1]=dp[i-k][0];
        //最后一步是跑的(即：0~(i-k)最后一步为走 + (k+1,i)为跑) 等价于 0~(i-k)最后一步为走
    }
    sum[0]=0;
    for(int i=1;i<=maxn;i++)
        sum[i]=(sum[i-1]+dp[i][0]+dp[i][1])%mod;
        //总和=之前的和 + 这次的
    while(q--)
    {
        cin >> l >> r;
        printf("%lld\n",(sum[r]-sum[l-1]+mod)%mod);
    }
}

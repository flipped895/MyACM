/*
	题目链接：https://www.nowcoder.com/acm/contest/140/A
	题意：一个人可以选择一次走1m或者选择一次跑k m，问从L跑到R有多少种方法；
	思路：dp推导，dp[i][0]表示走i米的方法数，dp[i][1]表示跑到第i米所表示的方法数，
	那么到第i米走着来的所用的方法数可以由第i-1米走着来的和跑着来的方法数得到，
	那么第i米跑着来的方法数可以由第i-k米的方法数得到，这样就得到一个递推式：
	dp[i][0]=dp[i-1][0]+dp[i-1][1],dp[i][1]=dp[i-k];
*/
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

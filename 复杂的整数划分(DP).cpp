//  复杂的整数划分问题 2018-08-27 HZY

//  对于每组测试数据，输出以下三行数据:
//  第一行: N划分成K个正整数之和的划分数目
//  第二行: N划分成若干个不同正整数之和的划分数目
//  第三行: N划分成若干个奇正整数之和的划分数目

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
int n,k;
int dp1[N][N];//N划分成K个正整数之和的划分数目
int dp2[N][N];//N划分成若干个不同正整数之和的划分数目
int dp3[N][N];//N划分成若干个奇正整数之和的划分数目
void q1()//N划分成K个正整数之和的划分数目
{
    for(int i=1;i<N;i++)
    {
        dp1[i][1]=1;//把i划分1方案数为1
        for(int j=2;j<N;j++)
        {
            //分为两类划分
            //划分中不包含1的方案数+划分中至少包含一份1的方案数
            //dp1[i-j][j]+dp1[i-1][j-1];
            if(j<i)
            {
                dp1[i][j]=dp1[i-j][j]+dp1[i-1][j-1];
            }
            else if(i==j)//i=j时方案数为1
            {
                dp1[i][j]=1;
            }
            else//j>i时方案数为0
            {
                dp1[i][j]=0;
            }
        }
    }
}
void q2()//N划分成若干个不同正整数之和的划分数目
{
    for(int i=1;i<N;i++)
    {
        dp2[i][1]=0;//划分i为不同数的最大值为1的方案数为0
        if(i==1) dp2[i][1]=1;//i=1特例
        for(int j=2;j<N;j++)
        {
            //新状态的方案数(最大值为j的方案数=i-j划分最大为j-1的方案数)+旧状态的方案数(最大值为j-1的方案数)
            //dp2[i-j][j-1]+dp2[i][j-1];
            if(j<i)
            {
                dp2[i][j]=dp2[i-j][j-1]+dp2[i][j-1];
            }
            else if(i==j)//i=j时方案数为旧方案数+1
            {
                dp2[i][j]=dp2[i][j-1]+1;
            }
            else//j>i时方案数为旧方案数+0
            {
                dp2[i][j]=dp2[i][i];
            }
        }
    }
}
void q3()//N划分成若干个奇正整数之和的划分数目
{
    for(int i=1;i<N;i++)
    {
        dp3[i][1]=1;//划分i的最大值为1的方案数为1
        for(int j=2;j<N;j++)
        {
            if(i==j)//当i=j时分奇偶对方案数+1
            {
                dp3[i][j]=j%2?dp3[i][i-1]+1:dp3[i][i-1];
            }
            else if(j>i)//当j>i时分奇偶对方案数+0
            {
                dp3[i][j]=j%2?dp3[i][i]:dp3[i][i-1];
            }
            else
                if(j%2==0)
                {
                    dp3[i][j]=dp3[i][j-1];//j为偶数时旧方案数+0
                }
                else
                {
                    dp3[i][j]=dp3[i-j][j]+dp3[i][j-2];//j为奇数时旧方案数+新方案数
                }
            }
        }
    }
}
int main()
{
    //初始化
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    memset(dp3,0,sizeof dp3);
    //预存
    q1();
    q2();
    q3();
    while(~scanf("%d %d",&n,&k))
    {
        cout<<dp1[n][k]<<endl;
        cout<<dp2[n][n]<<endl;
        cout<<dp3[n][n]<<endl;
    }
    return 0;
}

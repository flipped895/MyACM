/*
	题目链接：https://www.nowcoder.com/acm/contest/141/A
	
    背包有四个约束P,A,C,M（相当于四种容量），
    每个物品有对应的四种体积p,a,c,m，同时还有一个价值g，
    问选哪些物品使得不超容量的情况下价值最大。
    即一个四个约束条件的01背包，适当修改一下01背包模板即可。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 40;
struct node
{
    int p;
    int a;
    int c;
    int m;
    int g;
}group[N];//group结构体
int n, p, a, c, m;
int dp[N][N][N][N];
bool path[N][N][N][N][N];//路径标记
int main()
{
    memset(dp,0,sizeof dp);
    memset(path,false,sizeof path);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>group[i].p>>group[i].a>>group[i].c>>group[i].m>>group[i].g;
    }
    cin>>p>>a>>c>>m;
    /*多维01背包*/
    for(int i=1; i<=n; i++)//考虑到第几个队伍
    {
        for(int j=p; j>=group[i].p; j--)
        {
            for(int k=a; k>=group[i].a; k--)
            {
                for(int l=c; l>=group[i].c; l--)
                {
                    for(int q=m; q>=group[i].m; q--)
                    {
                        if(dp[j][k][l][q]<dp[j-group[i].p][k-group[i].a][l-group[i].c][q-group[i].m]+group[i].g)
                        {
                            dp[j][k][l][q]=dp[j-group[i].p][k-group[i].a][l-group[i].c][q-group[i].m]+group[i].g;
                            path[i][j][k][l][q]=true;//此处更新标记
                        }
                    }
                }
            }
        }
    }
    /*以下部分 大佬们都用STL 本菜鸡用数组*/ 
    int cnt=0;
    int ans[N]={0};
    //根据路径标记从最终状态往回依次找对应状态的i，并保存
    for(int i=n; i>=1&&p>=0&&a>=0&&c>=0&&m>=0; i--)
    {
        if(path[i][p][a][c][m])
        {
            ans[cnt++]=i-1;
            p-=group[i].p;
            a-=group[i].a;
            c-=group[i].c;
            m-=group[i].m;
        }
    }
    cout<<cnt<<endl;
    //逆序输出
    for(int i=cnt-1; i>=0; i--)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

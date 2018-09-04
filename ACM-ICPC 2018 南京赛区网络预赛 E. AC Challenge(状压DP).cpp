//AC Challenge：https://nanti.jisuanke.com/t/30994
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
ll a[22],b[22];
ll dp[1<<21];
ll p[22];
int _count(int a)
{
    int cnt=0;
    while(a)
    {
        a&=(a-1);
        cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    int s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>s;
        p[i]=0;
        while(s--)
        {
            int t;
            cin>>t;
            p[i]|=(1<<(t-1));
        }
    }
    for(int i=0;i<(1<<21);i++)
    {
        dp[i]=-inf;
    }
    dp[0]=0;
    ll ans=0;
    for(int i=0;i<(1<<21);i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i&(1<<(j-1))) continue;
            int l=i|(1<<(j-1));
            if((p[j]==0)||(i&p[j]))
            {
                dp[l]=max(dp[l],dp[i]+a[j]*_count(l)+b[j]);
                ans=max(ans,dp[l]);
                //cout<<ans<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

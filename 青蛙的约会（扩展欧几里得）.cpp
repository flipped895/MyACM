//青蛙的约会 2018-08-26 HZY

//设青蛙A的出发点坐标是x，青蛙B的出发点坐标是y。
//青蛙A一次能跳m米，青蛙B一次能跳n米，两只青蛙跳一次所花费的时间相同。
//纬度线总长L米。现在要你求出它们跳了几次以后才会碰面。

//根据题意列式：(x + m * t) - (y + n * t) = lk;
//实则解：(m - n) * t + lk = (y - x);

//裴蜀等式：ax + by = gcd(a,b);
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll exgcd(ll a,ll b,ll &x,ll &y)//扩展欧几里得
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main()
{
    ll x,y,m,n,l;
    scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l);
    if(m<n)
    {
        swap(m,n);
        swap(x,y);
    }
    ll a=(m-n);
    ll b=l;
    ll t,k;
    ll d=exgcd(a,b,t,k);//d最大公约数;t,k,为满足(m - n) * t + lk = gcd((m-n),l)的解
    if((y-x)%d)//无解
    {
        printf("Impossible\n");
    }
    else
    {
        ll t0=(t*(y-x)/d)/d;
        //t的通解为t0+k(b/d);
        ll c=b/d;
        //求t最小值
        t=(t0%c+c)%c;
        cout<<t<<endl;
    }
    return 0;
}

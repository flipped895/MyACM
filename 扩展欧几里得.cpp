/*
扩展欧几里得算法（英语：Extended Euclidean algorithm）是欧几里得算法（又叫辗转相除法）的扩展。
已知整数a、b，扩展欧几里得算法可以在求得a、b的最大公约数的同时，能找到整数x、y（其中一个很可能是负数），使它们满足贝祖等式ax + by = gcd(a,b);
通常谈到最大公约数时，我们都会提到一个非常基本的事实：给予二个整数a、b，必存在整数x、y使得ax + by = gcd(a,b)
*/
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

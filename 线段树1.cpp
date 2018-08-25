#include <bits/stdc++.h>

using namespace std;
const int MAX = 100100;
int sum[MAX<<2]={0};
int mark[MAX<<2]={0};

void pushup(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int l, int r, int rt)
{
    if(mark[rt])
    {
        mark[rt<<1]+=mark[rt];
        mark[rt<<1|1]+=mark[rt];
        int m = (l + r) >> 1;
        sum[rt<<1]+=mark[rt]*(m-l+1);
        sum[rt<<1|1]+=mark[rt]*(r-m);
        mark[rt]=0;
    }
}
void build(int l,int r,int rt)
{
	if(l==r)
    {
        scanf("%d", &sum[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    pushup(rt);
}
void update1(int i, int c, int l, int r, int rt)
{
    if(l==r)
    {
        sum[rt]+=c;
        return ;
    }
    int m = (l + r) >> 1;
    if(i <= m) update1(i, c, l, m, rt<<1);
    else update1(i, c, m+1, r, rt<<1|1);
    pushup(rt);
}
void update2(int _l, int  _r, int c, int l, int r, int rt)
{
    if(_l <= l && _r >= r)
    {
        mark[rt]+=c;
        sum[rt]+=c*(r-l+1);
        return ;
    }
    pushdown(l, r, rt);
    int m = (l + r)>>1;
    if(m >= _l) update2(_l, _r, c, l, m, rt<<1);
    if(m < _r) update2(_l, _r, c, m + 1, r, rt<<1|1);
    pushup(rt);
}
int query(int _l, int _r, int l, int r, int rt)
{
    if(_l <= l && _r >= r)
    {
        return sum[rt];
    }
    pushdown(l, r, rt);
    int m = (l + r)>>1;
    int ans = 0;
    if(m >= _l) ans+=query(_l, _r, l, m, rt<<1);
    if(m < _r) ans+=query(_l, _r, m+1, r, rt<<1|1);
    return ans;
}

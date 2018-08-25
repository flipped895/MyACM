#include <bits/stdc++.h>

using namespace std;
const int MAX = 100100;
int sum[MAX<<2];
int mark[MAX<<2];

void pushup(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int l, int r, int rt)
{
    if(mark[rt]>-1)
    {
        mark[rt<<1]=mark[rt];
        mark[rt<<1|1]=mark[rt];
        int m = (l + r) >> 1;
        sum[rt<<1]=mark[rt]*(m-l+1);
        sum[rt<<1|1]=mark[rt]*(r-m+1);
        mark[rt]=-1;
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
void update2(int _l, int  _r, int c, int l, int r, int rt)
{
    if(_l <= l && _r >= r)
    {
        mark[rt]=c;
        sum[rt]=c*(r-l+1);
        return ;
    }
    pushdown(l, r, rt);
    int m = (l + r)>>1;
    if(m >= _l) update2(_l, _r, c, l, m, rt<<1);
    if(m < _r) update2(_l, _r, c, m + 1, r, rt<<1|1);
    pushup(rt);
}
long long query(int _l, int _r, int l, int r, int rt)
{
    if(_l <= l && _r >= r)
    {
        return sum[rt];
    }
    pushdown(l, r, rt);
    int m = (l + r)>>1;
    long long ans = 0;
    if(m >= _l) ans+=query(_l, _r, l, m, rt<<1);
    if(m < _r) ans+=query(_l, _r, m+1, r, rt<<1|1);
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        memset(mark,-1,sizeof(mark));
        printf("case #: %d\n", i+1);
        int n, q;
        scanf("%d %d", &n, &q);
        build(1, n, 1);
        while(q--)
        {
            int num;
            int l, r, c;
            scanf("%d", &num);
            if(num == 1)
            {
                scanf("%d %d %d", &l, &r, &c);
                update2(l, r, c, 1, n, 1);
            }
            if(num == 0)
            {
                scanf("%d %d", &l, &r);
                printf("%lld\n", query(l, r, 1, n, 1));
            }
        }
    }
    return 0;
}

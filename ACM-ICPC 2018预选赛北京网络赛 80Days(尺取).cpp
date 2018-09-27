//80 Days 原题链接：http://hihocoder.com/problemset/problem/1831
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll a[N],b[N],d[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        ll sum=0;
        cin>>n>>c;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        for(int i=0; i<n; i++)
        {
            d[i]=a[i]-b[i];
            sum+=d[i];
        }
        int l,r;
        ll ans=c;
        l=r=0;
        while(l<n&&r<n+l)
        {
            ans+=d[r%n];
            r++;
            while(ans<0)
            {
                ans-=d[l%n];
                l++;
            }
        }
        if(l>r%n) cout<<-1<<endl;
        else cout<<l+1<<endl;
    }
    return 0;
}

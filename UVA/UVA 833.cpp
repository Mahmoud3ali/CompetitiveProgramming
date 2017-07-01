#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cp(pair<ll,ll> v1, pair<ll,ll> v2)
{
    return v1.first*v2.second - v1.second*v2.first;
}
ll dp(pair<ll,ll> v1, pair<ll,ll> v2)
{
    return v1.first*v2.first + v1.second*v2.second;
}
ll norm(pair<ll,ll> v1)
{
    return dp(v1,v1);
}
ll ccw(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> x)
{
    pair<ll,ll> v1 = {b.first-a.first, b.second-a.second};
    pair<ll,ll> v2 = {x.first-a.first, x.second-a.second};
    if(cp(v1,v2) > 0) return 1;
    if(cp(v1,v2) < 0 ) return -1;
    if(v1.first*v2.first < 0 || v1.second*v2.second < 0) return -1;
    if(norm(v1) < norm(v2)) return 1;
    return 0;
}
bool intersect(pair<ll,ll> x, pair<ll,ll> y, pair<ll,ll> a, pair<ll,ll> b)
{
    if(x == y && a == b) return (x == a);
    if(x == y) return (ccw(a,b,x) == 0);
    return (ccw(x,y,a)*ccw(x,y,b) <= 0 && ccw(a,b,x)*ccw(a,b,y) <= 0) ;
}
bool ss(pair<pair<int,int>,pair<int,int> > x, pair<pair<int,int>,pair<int,int> > y)
{
    return x.first.second > y.first.second ;
}
int main()
{
    int t ;
    cin >> t;
    while(t--)
    {
        int n, m ;
        cin >> n ;
        vector < pair<pair<int,int>,pair<int,int> > > v;
        for(int i = 0 ; i < n ; i++)
        {
            int a, b, x, y ;
            cin >> a>>b>>x>>y;
            if(y > b) v.push_back({{x,y},{a,b}});
            else v.push_back({{a,b},{x,y}});
        }
        sort(v.begin(),v.end(),ss);
        cin >> m;
        while(m--)
        {
            int x, y ;
            cin >> x >> y ;
            for(int i = 0 ; i < v.size() ; i++)
            {
                if(intersect({x,y}, {x,y-1e8},v[i].first,v[i].second))
                {
                    x = v[i].second.first;
                    y = v[i].second.second;
                }
            }
            cout << x << "\n";
        }
        if(t) cout << "\n";
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cp(pair<ll,ll> v1 , pair<ll,ll> v2)
{
    return v1.first*v2.second - v1.second*v2.first;
}
ll dp(pair<ll,ll> v1 , pair<ll,ll> v2)
{
    return v1.first*v2.first + v1.second*v2.second;
}
ll norm(pair<ll,ll> v1)
{
    return dp(v1,v1);
}
ll ccw(pair<ll,ll> a , pair<ll,ll> b , pair<ll,ll> x)
{
    pair<ll,ll> v1 = {b.first-a.first , b.second-a.second};
    pair<ll,ll> v2 = {x.first-a.first , x.second-a.second};
    if(cp(v1,v2) > 0) return 1;
    if(cp(v1,v2) < 0 ) return -1;
    if(v1.first*v2.first < 0 || v1.second*v2.second < 0) return -1;
    if(norm(v1) < norm(v2)) return 1;
    return 0;
}
bool intersect(pair<ll,ll> x , pair<ll,ll> y , pair<ll,ll> a , pair<ll,ll> b)
{
    if(x == y && a == b) return (x == a);
    if(x == y) return (ccw(a,b,x) == 0);
    return (ccw(x,y,a)*ccw(x,y,b) <= 0 && ccw(a,b,x)*ccw(a,b,y) <= 0) ;
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        pair<ll,ll> a , b ,q,w,e,r;
        ll s , ss ,sss ,ssss ;
        cin >> a.first >> a.second >> b.first >> b.second;
        cin >> s >> ss >> sss >> ssss;
        q = {min(s,sss) , max(ss,ssss)};
        w = {max(s,sss) , max(ss,ssss)};
        e = {max(s,sss) , min(ss,ssss)};
        r = {min(s,sss) , min(ss,ssss)};
        if(a.first >= q.first && a.first <= w.first && a.second >= e.second && a.second <= w.second) cout << "T";
        else if(b.first >= q.first && b.first <= w.first && b.second >= e.second && b.second <= w.second) cout << "T";
        else if(intersect(q,w,a,b) || intersect(w,e,a,b)|| intersect(e,r,a,b)|| intersect(q,r,a,b)) cout << "T";
        else cout << "F";
        cout << "\n";
    }
}

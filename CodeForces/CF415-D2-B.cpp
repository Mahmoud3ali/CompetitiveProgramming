#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
bool ss(pair<ll,ll> x , pair<ll,ll> y)
{
    ll a = min(x.first*2,x.second)-min(x.first,x.second);
    ll b = min(y.first*2,y.second)-min(y.first,y.second);
    return a > b ;
}
int main()
{
    ll n , f;
    cin >> n >> f;
    vector<pair<ll,ll> > vec;
    for(ll i = 0 ; i < n ; i++)
    {
        ll x ,y ;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end() , ss);
    ll ans = 0;
    for(ll i = 0 ; i < vec.size() ; i++)
    {
        if(i < f)
        {
            ans+= min(vec[i].first*2,vec[i].second);
        }
        else
        {
            ans+= min(vec[i].first,vec[i].second);
        }
    }
    cout << ans << "\n";
}

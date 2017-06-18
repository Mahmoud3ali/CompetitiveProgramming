#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> get_vec(ll x1 , ll y1 , ll x2 , ll y2)
{
    pair<ll,ll> ret;
    ret.first = x2-x1 , ret.second = y2-y1;
    return ret;
}
ll dotprod(pair<ll,ll> v1 , pair<ll,ll> v2)
{
    return v1.first*v2.first + v1.second*v2.second;
}
ll crossprod(pair<ll,ll> v1 , pair<ll,ll> v2)
{
    return v1.first*v2.second - v1.second*v2.first;
}
ll norm_sq(pair<ll,ll> v)
{
    return dotprod(v,v);
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        double x1,y1,u1,v1,x2,y2,u2,v2;
        cin >>x1>>y1>>u1>>v1>>x2>>y2>>u2>>v2;
        pair<ll,ll> hero = get_vec(x1,y1,u1,v1);
        pair<ll,ll> heroine = get_vec(x2,y2,u2,v2);
        double dot_hero_hh = dotprod(get_vec(x1,y1,u1,v1) , get_vec(x1,y1,x2,y2));
        double dot_heroine_hh = dotprod(get_vec(x2,y2,u2,v2) , get_vec(x2,y2,x1,y1));
        dot_heroine_hh /= sqrt(norm_sq(heroine));
        dot_hero_hh /= sqrt(norm_sq(hero));
        if(dot_heroine_hh < 1e-11 && dot_hero_hh < 1e-11)
        {
            if(abs(dot_heroine_hh-dot_hero_hh) < 1e-11) cout << "0\n";
            else if(abs(dot_heroine_hh) - abs(dot_hero_hh) > 1e-11) cout << "Hero\n";
            else cout << "Heroine\n";
        }
        else if(dot_heroine_hh > 1e-11 && dot_hero_hh > 1e-11)
        {
            if(abs(dot_heroine_hh-dot_hero_hh) < 1e-11) cout << "0\n";
            else if(dot_heroine_hh - dot_hero_hh > 1e-11) cout << "Heroine\n";
            else cout << "Hero\n";
        }
        else if(dot_heroine_hh > 1e-11)
        {
            cout << "Heroine\n";
        }
        else if(dot_hero_hh > 1e-11)
        {
            cout << "Hero\n";
        }
        else assert(0);
    }
}

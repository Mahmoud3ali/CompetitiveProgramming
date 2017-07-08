#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll go(ll f)
{
    return f*(f+1)*0.5;
}
int main()
{
    double m , b ;
    ll t;
    cin >> m >> b;
    m = -1.000/m;
    ll ans = 0;
    for(ll i = 0 ;  (ll) i*m +b >= 0 ; i++)
    {
        t = i*m + b;
        ans = max(ans,go(i)* (t+1) + go(t)*(i+1));
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n , x1 , x2;
    cin >> n >>x1>>x2;
    vector<pair<ll,ll> > y;
    for(int i = 0 ; i < n ; i++)
    {
        ll a , b ;
        cin >> a >> b;
        y.push_back({a*x1+b , a*x2+b});
    }
    sort(y.begin(),y.end());
    ll ymin = y[0].second;
    for(int i = 1 ; i < y.size() ; i++)
    {
        if(ymin > y[i].second)
        {
            cout << "YES\n";
            return 0;
        }
        ymin = y[i].second;
    }
    cout << "NO\n";
}

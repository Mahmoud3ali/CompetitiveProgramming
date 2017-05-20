#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
bool fit(ll a , ll b , ll x , ll y)
{
    return (x<=a && y<=b);
}
int main()
{
    ll a , b , a1,b1,a2,b2;
    cin >> a >> b >> a1>>b1>>a2>>b2;
    if(fit(a,b,a1,b1) && (fit(a,b-b1,a2,b2)||fit(a-a1,b,a2,b2)||fit(a,b-b1,b2,a2)||fit(a-a1,b,b2,a2))) cout << "YES\n";
    else if(fit(a,b,b1,a1) && (fit(a,b-a1,a2,b2)||fit(a-b1,b,a2,b2)||fit(a,b-a1,b2,a2)||fit(a-b1,b,b2,a2))) cout << "YES\n";
    else if(fit(a,b,a2,b2) && (fit(a,b-b2,a1,b1)||fit(a-a2,b,a1,b1)||fit(a,b-b2,b1,a1)||fit(a-a2,b,b1,a1))) cout << "YES\n";
    else if(fit(a,b,b2,a2) && (fit(a,b-a2,a1,b1)||fit(a-b2,b,a1,b1)||fit(a,b-a2,b1,a1)||fit(a-b2,b,b1,a1))) cout << "YES\n";
    else cout << "NO\n";
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll mod = 1000000007 ;
long long fast_power(long long base, long long power)
{
    if(power == 1) return base%mod ;
    else if(power&1) return (base*fast_power((base*base)%mod,power/2))%mod;
    else return (fast_power((base*base)%mod,power/2))%mod;
}
int main()
{
    ll x = 3;
    int n ;
    cin >> n ;
    mod--;
    ll p = fast_power(3,n);
    mod++;
    cout << fast_power(3,p) << endl;
}

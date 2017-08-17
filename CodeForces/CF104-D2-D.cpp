#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n , k , p ;
    cin >> n >> k >> p;
    ll even = (n/2)*2 , odd = (n/2)*2+1;
    if(odd > n) ----odd;
    if(n&1)
    {
        if(k) ----odd , k--;
        if(k) ----even , k--;
        ll f = even/2;
        even = max(0LL,even-(k*2));
        k-=f;
        if(k > 0)
        {
            odd -= k*2;
        }
    }
    else
    {
        even = max(0LL,n-k*2);
        k-=n/2;
        if(k > 0)
        {
            odd = max(0LL,(n-1)-k*2);
        }
    }
    while(p--)
    {
        ll x ;
        cin >> x;
        if(x&1)
        {
            if(x <= odd) cout << ".";
            else cout << "X";
        }
        else
        {
            if(x <= even) cout << ".";
            else cout << "X";
        }
    }
}

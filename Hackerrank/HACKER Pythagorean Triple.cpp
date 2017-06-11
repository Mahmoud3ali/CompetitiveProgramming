#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x ;
    cin >> x;
    if(x&1)
    {
        cout << x << " " << (x*x)/2 << " " << ((x*x)/2)+1 << endl ;
    }
    else
    {
        ll p = x*x / 4 ;
        cout << x << " " << p-1 << " " << p+1 << endl;
    }
}

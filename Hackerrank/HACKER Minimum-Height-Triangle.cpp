#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a , b;
    cin >>b  >> a;
    a = 2*a;
    int s = 0 , e = 1e8 , ans =0;
    while(s <= e)
    {
        ll mid = s+(e-s)/2;
        if(b*mid >= a) ans = mid , e = mid-1;
        else s = mid+1;
    }
    cout << ans << endl;
}

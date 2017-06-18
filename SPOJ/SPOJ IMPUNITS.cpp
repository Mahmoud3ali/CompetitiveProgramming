#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    while(cin >> n && n != -1)
    {
        pair<ll,ll> arr[n+5];
        for(int i = 0 ; i < n-1; i++) cin >> arr[i].first >> arr[i].second ;
        ll up = 1 , down = 1 ;
        for(int i = n-2 ; i >= 0 ; i--)
        {
            up*= arr[i].second;
            down *= arr[i].first;
            int f = __gcd(up,down);
            down/=f;
            up/=f;
        }
        cout << down << " " << up << endl;
    }
}

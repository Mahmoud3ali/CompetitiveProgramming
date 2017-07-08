#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n ;
        cin >> n ;
        ll ans = 0 ;
        for(int i = 1 ; i < n/2 ; i++) ans += 2*i;
        if(n%2)
            ans+= n/2;
        cout << ans << endl;
    }
}

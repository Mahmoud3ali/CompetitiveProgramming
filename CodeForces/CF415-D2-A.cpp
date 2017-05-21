#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    double tot = 0 ;
    int n , k;
    cin >> n >> k ;
    double target =(double) k-0.5 ;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        tot+=x;
    }
    int ans = 0;
    while(target - (tot/n) >= 1e-6)
    {
        tot+= k;
        n++;
        ans++;
    }
    cout << ans << endl ;
}

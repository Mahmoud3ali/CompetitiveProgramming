#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll arr[(int) 1e6+5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 4 ; i <= 1e6 ; i++)
    {
        ll f = (i-2)/2;
        if(i%2 == 0)
            arr[i] = arr[i-1]+ f*f;
        else
            arr[i] = arr[i-1]+ f*(f+1) ;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        cout << arr[x] << endl ;
    }
}

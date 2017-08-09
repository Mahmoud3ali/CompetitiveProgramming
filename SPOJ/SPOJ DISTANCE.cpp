#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n , d;
    cin >> n >> d;
    vector< vector<ll> > a;
    for(int i = 0 ; i < n ; i++)
    {
        vector<ll> f;
        int arr[10];
        for(int j = 0; j < d; j++)
            cin >> arr[j];
        for(int j = 0  ;j < 1<<(d-1) ; j++)
        {
            ll nw = arr[0];
            for(int i = 0 ; i < d-1 ; i++)
            {
                if((j&(1<<i))) nw+= arr[i+1];
                else nw-=arr[i+1];
            }
            f.push_back(nw);
        }
        a.push_back(f);
    }
    ll anss =  -1e9;
    for(int i = 0 ; i < a[0].size() ; i++)
    {
        ll maxi = -1e9 , mini = 1e9;
        for(int j = 0 ; j < a.size() ; j++)
        {
            maxi = max(maxi,a[j][i]);
            mini = min(mini,a[j][i]);
        }
        anss = max(anss,maxi-mini);
    }
    cout << anss  << endl;
}
 

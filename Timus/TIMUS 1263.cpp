#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    int n , m ;
    cin >> n >> m ;
    int arr[n+5] ;
    memset(arr,0,sizeof(arr));
    for(int i = 0 ; i < m ; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        double f = arr[i];
        f/=m;
        f*=100;
        cout << fixed << setprecision(2) << f << "%\n";
    }
}

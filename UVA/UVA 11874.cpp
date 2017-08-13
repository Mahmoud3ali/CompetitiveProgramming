#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-12;
pair<int,int> go(pair<int,int> x, pair<int,int> y)
{
    double a = (double) x.first/x.second;
    double b = (double) y.first/y.second;
    if(a <= b) return x;
    else return y;
}
int main()
{
    int t, T = 1;
    cin >> t;
    while(t--)
    {
        int arr[105][105];
        for(int i = 0 ; i < 105 ; i++) for(int j = 0 ; j < 105 ; j++) arr[i][j] = 1e9;
        int n, r ;
        double p;
        cin >> n >> r >> p;
        for(int i = 0 ; i < r ; i++)
        {
            int a, b, l, e;
            cin>> a >> b >> l >> e ;
            arr[a][b] = e*p - l;
        }
        for(int k = 0 ; k < n ; k++)
        {
            /*
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    cout << arr[i][j].first << "," << arr[i][j].second << "  " ;
                }
                cout << endl;
            }
            cout << "----\n";*/
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                {
                    arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
                }
        }
        bool ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i][i] < 0) ans = 1;
        }
        cout << "Case " << T++ << ": ";
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

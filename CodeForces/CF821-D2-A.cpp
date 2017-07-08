#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n ;
    cin >> n;
    bool ans = 1;
    int arr[n+5][n+5];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < n ; j++) cin >> arr[i][j];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            bool bebe = 0;
            if(arr[i][j] == 1) continue;
            set<int> row, col, all;
            for(int k = 0 ; k < n ; k++) row.insert(arr[i][k]);
            for(int k = 0 ; k < n ; k++) col.insert(arr[k][j]);
            int f = arr[i][j];
            for(auto i = row.begin() ; i != row.end() ; i++)
                for(auto j = col.begin() ; j != col.end() ; j++)
                    if(*i+*j == f) bebe = 1;
            ans &= bebe;
        }
    }
    if(ans) cout << "Yes\n";
    else cout << "No\n";
}

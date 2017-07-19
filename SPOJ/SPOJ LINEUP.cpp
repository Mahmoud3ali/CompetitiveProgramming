#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int dp[15][1<<11];
int arr[15][15];
int solve(int mask , int idx)
{
    if(idx == 11 && mask == (1<<11)-1) return 0;
    if(idx == 11) return -1e8;
    if(dp[idx][mask] != -1) return dp[idx][mask];
    int ret = -1e8;
    for(int i = 0 ; i < 11 ; i++)
    {
        if(!(mask & (1<<i)) && arr[idx][i])
        {
            ret = max(ret,arr[idx][i]+solve(mask|(1<<i),idx+1));
        }
    }
    return dp[idx][mask] = ret;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < 11 ; i++)
            for(int j = 0 ; j < 11 ; j++)
                cin >> arr[i][j];
        cout << solve(0,0) << endl;
    }
}

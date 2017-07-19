#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
string s ;
int m , n;
ll dp[1<<18][102];
ll solve(int mask , short sum )
{
    if(mask == (1<<n)-1) return !sum;
    if(dp[mask][sum] != -1) return dp[mask][sum];
    ll ret = 0;
    bool f ;
    f = __builtin_popcount(mask);
    bool arr[12] = {};
    for(int i = 0 ; i < n ; i++)
    {
        if(!f && s[i] == '0') continue;
        if(!(mask & (1<<i)) && !arr[s[i]-'0'])
        {
            arr[s[i]-'0'] = 1;
            short o = (sum == -1);
            ret+= solve(mask|(1<<i),((sum+o)*10 + s[i]-'0')%m) ;
        }
    }
    return dp[mask][sum] = ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >>s >> m;
    n = s.size();
    cout << solve(0,0) << "\n";
}

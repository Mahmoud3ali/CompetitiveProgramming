#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[(int) 5e6+6];
int p[(int) 5e6+5];
int mod = 1e9+7;
ll solve(ll x)
{
    if(x == 1) return 0;
    if(dp[x] != -1) return dp[x];
    ll ret = x*(x-1)*0.5;
    int tmp = x;
    while(tmp > 1)
    {
        ll f = solve(x/p[tmp]);
        f+= x/p[tmp]*p[tmp]*(p[tmp]-1)*0.5;
        ret = min(ret,f);
        tmp/=p[tmp];
    }
    return dp[x] = ret%mod;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i <= 5e6 ; i++) p[i] = i;
    for(int i = 2 ; i <= 5e6 ; i++)
    {
        if(p[i] == i)
        {
            for(int j = i ; j <= 5e6 ; j+=i) p[j] = min(p[j],i);
        }
    }
    ll t, l, r, ans = 0, tmp = 1;
    solve(2);
    cin >> t >> l >> r;
    for(int i = l ; i <= r ; i++)
    {
        ans+= tmp*solve(i);
        if(ans >= mod)
            ans%=mod;
        tmp*=t;
        if(tmp >= mod)
            tmp%=mod;
    }
    cout << ans << endl;
}

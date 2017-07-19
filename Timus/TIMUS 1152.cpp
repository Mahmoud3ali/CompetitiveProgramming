#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int  n ;
int a[20], dp[1<<20];
int cost(int msk)
{
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(!(msk & (1<<i)))
            ans+=a[i];
    }
    return ans;
}
int solve(int msk)
{
    if(msk  == (1<<n)-1) return 0;
    if(dp[msk] != -1) return dp[msk];
    int ret = 1e9, tmp = cost(msk);
    for(int i = 0 ; i < n ; i++)
    {
        int f = 0 ;
        int A = i, b = i+1, c = i+2, u = msk;
        A%=n;
        b%=n;
        c%=n;
        u = u|(1<<A)|(1<<b)|(1<<c);
        if(!(msk & (1<<A)))f+=a[A];
        if(!(msk & (1<<b)))f+=a[b];
        if(!(msk & (1<<c)))f+=a[c];
        if(u != msk)
            ret = min(ret,solve(u)+tmp-f);
    }
    return dp[msk] = ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    cout << solve(0);
}

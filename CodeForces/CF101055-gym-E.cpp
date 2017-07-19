#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int n , k , mod = 1e9+7;
int dp[205][1<<13];
int solve(int idx , int mask)
{
    if(!(mask&1))
    {
        //cout << "first\n";
        return 0;
    }
    /*cout << idx << " " ;
    for(int i = 20 ; i >= 0 ; i--)
    {
        if(mask & (1<<i)) cout << '1';
        else cout << '0';
    }
    cout << " -> " ;*/
    mask >>= 1;
    /*for(int i = 20 ; i >= 0 ; i--)
    {
        if(mask & (1<<i)) cout << '1';
        else cout << '0';
    }
    cout << "\n";*/
    if(idx == 0 && __builtin_popcount(mask) == k)
        return 1;
    if(idx <= 0)
    {
        //cout << "H\n";
        return 0;
    }
    if(dp[idx][mask] != -1) return dp[idx][mask];
    ll ret = 0;
    for(int i = k , c = 0 , ind = idx+k-1 ; i >= -k && ind >= 0 ; i-- , ind-- , c++)
    {
        if(ind >= n) continue;
        if(!(mask & (1<<c)))
        {
            ret += solve(idx-1,mask|(1<<c));
            ret%=mod;
        }
    }
    return dp[idx][mask] = ret;
}
int main()
{
    cin >> k ;
    memset(dp,-1,sizeof(dp));
    for(int i = 1 ; i <= 200 ; i++)
    {
        n = i;
        //cout << i << "\n--------------------------\n";
        int msk = 0;
        for(int i = 0 ; i < k+1 ; i++) msk|=(1<<i);
        cout <<  solve(i,msk) << "\n";
    }
}

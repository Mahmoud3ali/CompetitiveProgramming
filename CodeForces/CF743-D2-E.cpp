#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int dp[1002][1<<8], arr[1002], n;
vector<int> a[10];
int solve(int k, int idx, int msk)
{
    if(msk == (1<<8)-1) return 0;
    if(idx == n) return -1e8;
    if(dp[idx][msk] != -1) return dp[idx][msk];
    int ret = -1e8;
    if(!(msk & (1<<arr[idx])))
    {
        int s = 0, e = a[arr[idx]].size() -1, ans = -1;
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            if(a[arr[idx]][mid] >= idx) e = mid-1, ans = mid;
            else s = mid+1;
        }
        if(ans != -1 && ans+k-1 < a[arr[idx]].size())
        {
            if(!k)
                ret = max(ret, solve(k,idx,msk|(1<<arr[idx])));
            else
                ret = max(ret, k+solve(k,a[arr[idx]][ans+k-1]+1,msk|(1<<arr[idx])));
        }
        if(ans != -1 && ans+k < a[arr[idx]].size())
            ret = max(ret,k+1+solve(k,a[arr[idx]][ans+k]+1,msk|(1<<arr[idx])));
    }
    ret = max(ret,solve(k,idx+1,msk));
    return dp[idx][msk] = ret;
}
bool go(int k, int &t)
{
    memset(dp,-1,sizeof(dp));
    int msk = 0;
    if(!k)
    {
        for(int i = 0 ; i < 8 ; i++)
            if(a[i].size() == 0) msk|=(1<<i);
    }
    t = solve(k,0,msk);
    //cout << t << " " << k << endl;
    return t >= 8*k;
}
int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
        arr[i]--;
        a[arr[i]].push_back(i);
    }
    int s = 0, e = 1000, as = -1, t;
    while(s <= e)
    {
        int tmp;
        int mid = s+(e-s)/2;
        if(go(mid,tmp)) as = mid, s = mid+1, t = tmp;
        else e= mid-1;
    }
    cout << t << endl;
}

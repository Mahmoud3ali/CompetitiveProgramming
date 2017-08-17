#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n ;
    ll arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    sort(arr,arr+n);
    reverse(arr,arr+n);
    ll accum[n+5];
    accum[0] = 0;
    for(int i = 0 ; i < n ; i++) accum[i+1] = accum[i]+arr[i];
    ll ans[(int) 1e5+5];
    memset(ans,-1,sizeof(ans));
    int q;
    cin >> q;
    while(q--)
    {
        int k ;
        cin >> k;
        if(ans[k] != -1) cout << ans[k] << " ";
        else
        {
            ans[k] = 0;
            int beg = 1;
            ll pow = k, cnt = 1;
            for(ll i = min(n,k+1) ;;)
            {
                pow*=k;
                ans[k] += (accum[i]-accum[beg])*cnt;
                cnt++;
                beg = i ;
                if(i < n)
                {
                    i+=pow;
                    i = min(i,(ll)n);
                }
                else break;
            }
            cout << ans[k] << " ";
        }
    }
}

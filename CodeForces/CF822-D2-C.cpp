#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[(int)1e6];
int main()
{
    int  n, x ;
    cin >> n >> x;
    vector< pair< pair<int,int>,pair<int,int> > > v;
    for(int i = 0 ; i < n ; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        v.push_back({{l,-1},{r,c}});
        v.push_back({{r,0},{l,c}});
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i < 1e6 ; i++) c[i] = 1e16;
    ll ans = 1e15;
    for(int i = 0 ; i < v.size() ; i++)
    {
        //cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << " " << v[i].second.second << endl;
        if(v[i].first.second == -1)
        {
            int len = v[i].second.first-v[i].first.first+1;
            ll tmp = v[i].second.second;
            if(x-len >= 0)
                ans = min(ans,tmp+c[x-len]);
        }
        else
        {
            int len = v[i].first.first-v[i].second.first+1;
            ll tmp = v[i].second.second;
            c[len] = min(c[len],tmp);
        }
    }
    if(ans == 1e15) cout << "-1\n";
    else cout << ans << endl;
}

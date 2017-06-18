#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005];
string f;
map<string,vector<string> > mp;
vector<string> ans;
int solve(int idx)
{
    if(idx >= f.size()) return 1;
    if(dp[idx] != -1) return dp[idx];
    string s ;
    ll ret = 0 ;
    for(int i = idx ; i < idx+150 ; i++)
    {
        s+= f[i];
        string p = s;
        if(p.size() >=2)
        sort(p.begin()+1,p.begin()+p.size()-1);
        if(mp[p].size())
        {
            int q = solve(i+1);
            if(q) ans.push_back(p);
            q*=mp[p].size();
            ret += q;
        }
        ret = min(10LL,ret);
    }
    return dp[idx] = ret;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        mp.clear();
        ans.clear();
        cin >> f;
        int n ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
        {
            string s;
            cin >> s;
            string p = s;
            if(s.size() >= 2) sort(s.begin()+1 , s.begin()+s.size()-1);
            mp[s].push_back(p);
        }
        int x = solve(0);
        if(x == 0) cout << "impossible";
        else if(x > 1) cout << "ambiguous";
        else
        {
            vector<string> v;
            int maxi = 0 ;
            for(int i = 0 ; i < ans.size() ; i++)
            {
                maxi = max(maxi,(int)mp[ans[i]].size());
                v.push_back(mp[ans[i]][0]);
            }
            if(maxi != 1) cout << "ambiguous";
            else
            {
                for(int i = v.size()-1 ; i >= 0 ; i--)
                {
                    cout << v[i];
                    if(i != 0) cout << " ";
                }
            }
        }
         cout << "\n";
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
map<int,vector<int> > v;
map<int,bool> mp;
void dfs(int idx)
{
    mp[idx] = 1;
    for(int i = 0 ; i < v[idx].size() ; i++)
    {
        int u = v[idx][i];
        if(mp[u] != 1) dfs(u);
    }
}
int main()
{
    int n , m ;
    cin >> n >> m;
    set<int> p ;
    for(int i = 0 ; i < m ; i++)
    {
        int x,y;
        cin>>x>>y;
        p.insert(x);
        p.insert(y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = 0;
    for(auto i = p.begin() ; i != p.end() ; i++)
    {
        if(mp[*i] == 0)
        {
            dfs(*i);
            ans++;
        }
    }
    cout << n-p.size()+ans << endl;
}

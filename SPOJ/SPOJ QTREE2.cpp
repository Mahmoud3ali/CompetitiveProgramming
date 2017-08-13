#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< vector<pair<int,int> > > v;
vector<int> cost ;
int level[(int) 1e4+5];
int par[(int) 1e4+5];
int dp[20][(int) 1e4+5] ;
void dfs(int node, int lvl, int w)
{
    cost[node] = w;
    level[node] = lvl;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int u = v[node][i].first;
        if(level[u] != -1) continue;
        par[u] = node;
        dfs(u,lvl+1,w+v[node][i].second);
    }
}
int LCA(int x, int y)
{
    if(x== y) return x;
    if(level[x] > level[y]) swap(x,y); // x must be in lower level than y or equal
    int diff = level[y]-level[x]; // can be 0
    for(int i = 19 ; i >= 0 ; i--)
    {
        if(diff&(1<<i)) y = dp[i][y];
    }
    if(x == y) return x;
    for(int i = 19 ; i >= 0 ; i--)
    {
        if(dp[i][x] != dp[i][y])
        {
            y = dp[i][y];
            x = dp[i][x];
        }
    }
    return dp[0][x];
}
int gett(int node, int diff)
{
    for(int i = 19 ; i >= 0 ; i--)
    {
        if(diff&(1<<i)) node = dp[i][node];
    }
    return node;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        v.clear();
        cost.clear();
        int n ;
        cin >> n ;
        v.resize(n+5);
        cost.resize(n+5);
        memset(level,-1,sizeof(level));
        for(int i = 0 ; i < n-1 ; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            assert(a <= n && b <= n);
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        par[1] = 1;
        dfs(1,0,0);
        for(int i = 1 ; i <= n ; i++) dp[0][i] = par[i];
        for(int i = 1 ; i < 20 ; i++)
            for(int j = 1 ; j <= n ; j++)
                dp[i][j] = dp[i-1][dp[i-1][j]];
        string s;
        while(cin >> s && s != "DONE")
        {
            if(s == "DIST")
            {
                int x, y;
                cin >> x >> y;
                int lca = LCA(x,y);
                cout << cost[x]+cost[y]-2*cost[lca] << "\n";
            }
            else
            {
                int x, y, k;
                cin >> x >> y >> k ;
                int lca = LCA(x,y);
                if(k-1 <= level[x]-level[lca]) //root or first half of the path
                {
                    cout << gett(x,k-1) << "\n";
                }
                else
                {
                    cout << gett(y,level[y]+level[x]-2*level[lca]-(k-1)) << "\n" ;
                }
            }
        }
        cout << "\n";
    }
}

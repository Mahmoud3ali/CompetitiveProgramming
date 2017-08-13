#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int level[(int) 1e5+5];
int par[(int) 1e5+5];
map<int,map<int,int> > mp;
int dp[18][(int) 1e5+5] ;
int dp_max[18][(int) 1e5+5] ;
int dp_min[18][(int) 1e5+5] ;
void dfs(int node, int lvl)
{
    level[node] = lvl;
    for(auto i = mp[node].begin() ; i != mp[node].end() ; i++)
    {
        int u = i->first;
        if(level[u] == -1)
        {
            par[u] = node;
            dfs(u,lvl+1);
        }
    }
}
int LCA(int x , int y)
{
    if(x == y) return x;
    if(level[x] > level[y]) swap(x,y);
    int diff = level[y]-level[x];
    for(int i = 17 ; i >= 0 ; i--)
    {
        if(diff&(1<<i))
        {
            y = dp[i][y];
        }
    }
    if(x == y) return x;
    for(int i = 17 ; i >= 0 ; i--)
    {
        if(dp[i][x] != dp[i][y])
        {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}
int edge(int x , int diff)
{
//    diff--;
    int ans = 0;
    for(int i = 17 ; i >= 0 ; i--)
    {
        if(diff&(1<<i))
        {
            ans = max(ans,dp_max[i][x]);
            x = dp[i][x];
        }
    }
    return ans;
}
int edge1(int x , int diff)
{
//    diff--;
    int ans = 1e9;
    for(int i = 17 ; i >= 0 ; i--)
    {
        if(diff&(1<<i))
        {
            ans = min(ans,dp_min[i][x]);
            x = dp[i][x];
        }
    }
    return ans;
}
pair<int,int> solve(int x, int y)
{
    int lca = LCA(x,y);
    int mini = min(edge1(x,level[x]-level[lca]),edge1(y,level[y]-level[lca]));
    int maxi = max(edge(x,level[x]-level[lca]),edge(y,level[y]-level[lca]));
    return {mini,maxi};
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n ;
    memset(level,-1,sizeof(level));
    for(int i = 0 ; i < n-1 ; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        mp[x][y] = z ;
        mp[y][x] = z ;
    }
    par[1] = 1;
    dfs(1,0);
    for(int i = 1 ; i <= n ; i++)
    {
        dp[0][i] = par[i];
        if(i == 1)
        {
            dp_max[0][i] = 0;
            dp_min[0][i] = 1e9;
            continue;
        }
        dp_max[0][i] = mp[par[i]][i];
        dp_min[0][i] = dp_max[0][i];
    }
    for(int i = 1 ; i < 18 ; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            dp[i][j] = dp[i-1][dp[i-1][j]];
            dp_max[i][j] = max(dp_max[i-1][j],dp_max[i-1][dp[i-1][j]]);
            dp_min[i][j] = min(dp_min[i-1][j],dp_min[i-1][dp[i-1][j]]);
        }
    int m;
    cin >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        pair<int,int> ans = solve(x,y);
        cout << ans.first << " " << ans.second << "\n";
    }
}


// tree diameter is the largest distance on a tree , so if at any time distance asked for is bigger then the answer is 0 .
// we can consider all paths out from one node , but this gets TLE 
// so we need to replace this with one path we know that if there's an answer it will be on it
// in other words we need to replace it with the largest path out from the given node
// looking at the tree diameter any node want to reach the largest path it has must join the diameter at some point
// so we just need to look on the largest path from two paths each start at the given node and end at a different end of the diameter
// in this way we are sure that if there's an answer it will be in this path.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int level[(int) 2e4+5];
int par[(int) 2e4+5];
int dp[16][(int) 2e4+5];
vector< vector<int> > v;
int l = 1 , r = 1;
void dfs(int node, int &f , int dep)
{
    level[node] = dep;
    if(level[f] < dep) f = node;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int u = v[node][i] ;
        if(level[v[node][i]] != -1) continue;
        par[u] = node;
        dfs(v[node][i],f,dep+1);
    }
}
int LCA(int x , int y)
{
    if(x == y) return x;
    if(level[x] > level[y]) swap(x,y);
    int diff = level[y]-level[x];
    for(int i = 15 ; i >= 0 ; i--)
    {
        if(diff&(1<<i)) y= dp[i][y];
    }
    if(x == y) return x;
    for(int i = 15 ; i >= 0 ; i--)
    {
        if(dp[i][x] != dp[i][y])
        {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}
int dist(int x , int y)
{
    int lca = LCA(x,y);
    return level[x]+level[y]-2*level[lca];
}
int go(int node , int d)
{
    for(int i = 15 ; i >= 0 ; i--)
    {
        if(d&(1<<i))
        {
            node = dp[i][node];
        }
    }
    return node;
}
int solve(int node , int d)
{
    if(d > max(dist(node,l),dist(node,r))) return 0;
    if(dist(node,l) > dist(node,r))
    {
        int lca = LCA(node,l);
        if(dist(lca,node) >= d) return go(node,d);
        d-=dist(lca,node);
        return go(l,dist(lca,l)-d);
    }
    else
    {
        int lca = LCA(node,r);
        if(dist(lca,node) >= d) return go(node,d);
        d-=dist(lca,node);
        return go(r,dist(lca,r)-d);
    }
}
int main()
{
    int n , q;
    cin >> n >> q;
    v.resize(n+5);
    for(int i = 0 ; i < n-1 ; i++)
    {
        int x , y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(level,-1,sizeof(level));
    dfs(1,l,0);
    memset(level,-1,sizeof(level));
    dfs(l,r,0);
    memset(level,-1,sizeof(level));
    par[1] = 1;
    dfs(1,par[0],0);
    for(int i = 1 ; i <= n ; i++) dp[0][i] = par[i];
    for(int i = 1 ; i < 16 ; i++) for(int j = 1; j <= n ; j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    while(q--)
    {
        int x , d;
        cin >> x >> d;
        cout << solve(x,d) << "\n";
    }
}

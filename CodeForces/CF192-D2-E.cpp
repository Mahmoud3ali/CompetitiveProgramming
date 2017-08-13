#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int level[N];
int par[N];
int dp[18][N];
int arr[N];
int ans[N];
vector< vector<int> > v;
void dfs(int node, int lvl)
{
    level[node] = lvl;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int u = v[node][i];
        if(level[u] != -1) continue;
        par[u] = node;
        dfs(u,lvl+1);
    }
}
int LCA(int x, int y)
{
    if(x == y) return x;
    if(level[x] > level[y]) swap(x,y);
    int diff = level[y]-level[x];
    for(int i = 17 ; i >= 0 ; i--)
    {
        if(diff&(1<<i)) y = dp[i][y];
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
void accum(int x, int y)
{
    int lca = LCA(x,y);
//    cout << x << "~" << y << "~" << lca << endl;
    if(level[x] > level[y]) swap(x,y);
    if(lca == x)
    {
        arr[y]++;
//        cout << "increased " << y << "\n";
        arr[lca]--;
//        cout << "decreased " << par[lca] << "\n";
    }
    else
    {
        arr[y]++;
//        cout << "increased " << y << "\n";
        arr[x]++;
//        cout << "increased " << x << "\n";
        arr[lca]-=2;
//        cout << "decreased " << lca << "\n";
//        cout << "decreased " << lca << "\n";
    }
}
int dfs1(int node)
{
    int ret = arr[node] ;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int u = v[node][i];
        if(par[u] == node)
        {
            ret+= dfs1(u);
        }
    }
    return ans[node] = ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n ;
    v.resize(n+5);
    memset(level, -1,sizeof(level));
    memset(dp, -1,sizeof(dp));
    vector<pair<int,int> > edgs;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int x, y;
        cin >> x >> y;
        edgs.push_back({x,y});
        v[x].push_back(y);
        v[y].push_back(x);
    }
    par[1] = 1;
    dfs(1,0);
    for(int i = 1 ; i <= n ; i++) dp[0][i] = par[i];
    for(int i = 1 ; i < 18 ; i++)
        for(int j = 1; j <= n ; j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];
    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >>x  >> y;
        accum(x,y);
    }
    dfs1(1);
    for(int i = 0 ; i < edgs.size() ; i++)
    {
//        cout << edgs[i].first << " " << edgs[i].second << " " ;
        if(par[edgs[i].first] == edgs[i].second)
            cout << ans[edgs[i].first] << " ";
        else
            cout << ans[edgs[i].second] << " ";
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cost[(int) 1e5+5];
int par[(int) 1e5+5];
int level[(int) 1e5+5];
int dp[20][(int) 1e5+5];
vector< vector<int> > v;
int LCA(int x, int y)
{
    if(x == y) return x;
    if(level[x] > level[y]) swap(x,y);
    int diff = level[y]-level[x];
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
int dist(int x , int y)
{
    return cost[x]+cost[y]-2*cost[LCA(x,y)];
}
int solve(int s , int f , int t)
{
    int LCAs_t = LCA(s,t);
    int LCAs_f = LCA(s,f);
    int LCAt_f = LCA(t,f);
    if(LCAs_f == f && LCAt_f != f) return 0;
    if(LCAs_f != f && LCAt_f == f) return 0;
    if(LCAs_f == f)
        return dist(LCAs_t,f);
    if(LCAs_f != LCAt_f)
        return min(dist(f,LCAs_f) , dist(f,LCAt_f));
    return dist(f,LCAs_t);
}
void dfs(int node , int lvl , int w)
{
    level[node] = lvl;
    cost[node] = w;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int u = v[node][i];
        if(level[u] != -1) continue;
        par[u] = node;
        dfs(u,lvl+1,w+1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ,q ;
    cin >> n >> q;
    v.resize(n+5);
    memset(level,-1,sizeof(level));
    for(int i = 2 ; i <= n ;i++)
    {
        int p ;
        cin >> p;
        v[i].push_back(p);
        v[p].push_back(i);
    }
    par[1] = 1;
    dfs(1,0,0);
    for(int i = 1 ; i <= n ; i++) dp[0][i] = par[i];
    for(int i = 1 ; i < 20 ; i++) for(int j = 1 ; j <= n ; j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    while(q--)
    {
        int arr[3];
        for(int i = 0 ; i < 3 ; i++) cin >> arr[i];
        sort(arr,arr+3);
        int ans = 0 ;
        do
        {
            int f = 1+solve(arr[0],arr[1],arr[2]);
//            cout << f << " " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
            ans = max(ans,f);
        }while(next_permutation(arr,arr+3));
        cout << ans << "\n";
    }
}

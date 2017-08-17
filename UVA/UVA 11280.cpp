#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector< vector<pair<int,int> > > adj;
map<string,int> mp;
struct s
{
    int node, cost, cnt;
    bool operator < (const s &o ) const
    {
        return cnt > o.cnt ;
    }
};
int cost[(int) 150];
int dijk(int maxi)
{
    priority_queue<s> pq;
    pq.push({0,0,0});
    while(pq.size())
    {
        s tp = pq.top();
        pq.pop();
//        cout << tp.cost << " " << tp.node << " " << tp.cnt << endl;
        if(tp.cnt > maxi) continue;
        for(int i = 0 ; i < adj[tp.node].size() ; i++)
        {
            int u = adj[tp.node][i].first;
            if(cost[u] > tp.cost+adj[tp.node][i].second)
            {
                cost[u] = tp.cost+adj[tp.node][i].second;
                pq.push({u,cost[u],tp.cnt+1});
            }
        }
    }
    return cost[n-1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t , T = 1;
    cin >> t;
    while(t--)
    {
        adj.clear();
        mp.clear();
        cin >> n;
        adj.resize(n);
        for(int i = 0 ; i < n ; i++)
        {
            string s;
            cin >> s;
            mp[s] = i;
        }
        int m ;
        cin >> m;
        for(int i = 0 ; i < m ; i++)
        {
            string x, y;
            int f;
            cin >> x >> y >> f;
            adj[mp[x]].push_back({mp[y],f});
        }
        if(T != 1) cout << "\n";
        cout << "Scenario #" << T++ << "\n";
        int q;
        cin >> q;
        while(q--)
        {
            for(int i = 0 ; i < 150 ; i++) cost[i] = 1e9;
            int x;
            cin >> x;
            int f = dijk(x);
            if(f == 1e9) cout << "No satisfactory flights";
            else cout << "Total cost of flight(s) is $" << f ;
            cout << "\n";
        }
    }
}

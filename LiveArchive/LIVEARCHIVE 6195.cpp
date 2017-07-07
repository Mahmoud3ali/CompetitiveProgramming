#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    while(cin >> n >> m && n+m != 0)
    {
        vector< vector<int> > adj;
        adj.resize(n+5);
        int c[n+5];
        memset(c,0,sizeof(c));
        for(int i = 0 ; i < m ; i++)
        {
            int x, y;
            cin >> x >> y;
            c[y]++;
            adj[x].push_back(y);
        }
        queue<int> q;
        for(int i = 1; i <= n ; i++) if(c[i] == 0) q.push(i);
        int ans = 0 ;
        bool good = 1;
        while(q.size())
        {
            int f = q.size();
            ans = max(ans,min(f,2));
            for(int i = 0 ; i < f ; i++)
            {
                int u = q.front();
                q.pop();
                for(int j = 0 ; j < adj[u].size() ; j++)
                {
                    c[adj[u][j]]--;
                    if(c[adj[u][j]] == 0) q.push(adj[u][j]);
                }
            }
        }
        for(int i = 1 ; i <= n ; i++) if(c[i]) good = 0;
        if(good) cout << ans << endl;
        else cout << 0 << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
bool vis[1005][1005];
vector<pair<int,int> > v;
bool bfs(int sx, int sy, int ex, int ey, int r, int &sp, int x, int y)
{
    for(int i = 1 ; i <= x ; i++)
        for(int j = 1; j <= y ; j++) vis[i][j] = 0;
    queue< pair<int,pair<int,int> > > q ;
    for(int i = 0 ; i < v.size() ; i++) q.push({0,v[i]});
    while(q.size())
    {
        pair<int,pair<int,int> > tmp = q.front();
        q.pop();
        if(vis[tmp.second.first][tmp.second.second] == 1 || tmp.first >= r) continue;
        vis[tmp.second.first][tmp.second.second] = 1;
        q.push({tmp.first+1,{tmp.second.first+1,tmp.second.second}});
        q.push({tmp.first+1,{tmp.second.first-1,tmp.second.second}});
        q.push({tmp.first+1,{tmp.second.first,tmp.second.second+1}});
        q.push({tmp.first+1,{tmp.second.first,tmp.second.second-1}});
    }
    bool iffff = 0;
    q.push({0,{sx,sy}});
    while(q.size())
    {
        pair<int,pair<int,int> > tmp = q.front();
        q.pop();
        if(vis[tmp.second.first][tmp.second.second] == 1) continue;
        if(make_pair(ex,ey) == tmp.second)
        {
            sp = tmp.first;
            iffff = 1;
            break;
        }
        vis[tmp.second.first][tmp.second.second] = 1;
        q.push({tmp.first+1,{tmp.second.first+1,tmp.second.second}});
        q.push({tmp.first+1,{tmp.second.first-1,tmp.second.second}});
        q.push({tmp.first+1,{tmp.second.first,tmp.second.second+1}});
        q.push({tmp.first+1,{tmp.second.first,tmp.second.second-1}});
    }
    return iffff;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(vis,1,sizeof(vis));
    int t;
    cin >> t;
    while(t--)
    {
        v.clear();
        int n, x, y;
        int sx,sy,ex,ey;
        cin >> n >> x >> y ;
        cin >> sx>>sy>>ex>>ey;
        sx++;
        sy++;
        ex++;
        ey++;
        while(n--)
        {
            int x,y;
            cin >> x >> y;
            x++;
            y++;
            v.push_back({x,y});
        }
        int s = 0, e = 1e6, ans = -1, o ;
        while(s <= e)
        {
            int sp = 1e9;
            int mid = s+(e-s)/2;
            if(bfs(sx,sy,ex,ey,mid,sp,x,y)) ans = mid, o = sp, s = mid+1;
            else
            {
                e = mid-1 ;
            }
        }
        cout << ans << " " << o << "\n";
    }
}

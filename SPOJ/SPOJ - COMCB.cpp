#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ans, vis[30][30];
string s, best;
int n, m ;
void go(int i, int j, int cnt)
{
    if(i < 1 || j < 1 || i > n || j > m || ans) return ;
    if(vis[i][j]) return ;
    vis[i][j] = 1 ;
    s+= ('A'-1+j);
    s+= ('0'+i);
    //cout << i << " " << j << " " << cnt+1 << endl;
    if(cnt+1 == n*m)
    {
        best = s;
        ans = 1;
        return ;
    }
    go(i-1,j-2,cnt+1);
    go(i+1,j-2,cnt+1);
    go(i-2,j-1,cnt+1);
    go(i+2,j-1,cnt+1);
    go(i-2,j+1,cnt+1);
    go(i+2,j+1,cnt+1);
    go(i-1,j+2,cnt+1);
    go(i+1,j+2,cnt+1);
    s.pop_back();
    s.pop_back();
    vis[i][j] = 0;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        memset(vis,0,sizeof(vis));
        cin >> n >> m ;
        for(int j = 1 ; j <= m && ! ans; j++)
        {
            for(int i = 1 ; i <= n && !ans ; i++)
            {
                s.clear();
                go(i,j,0);
            }
        }
        if(ans)
            cout << best << "\n";
        else cout << "-1\n";
    }
}

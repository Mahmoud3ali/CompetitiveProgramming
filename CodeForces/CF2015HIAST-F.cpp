#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int  n ;
        cin >> n ;
        map<string,int> ans ;
        map<string,set<string> > mp ;
        for(int i = 0 ; i < n ; i++)
        {
            vector<string> ss;
            for(int j = 0 ; j < 3 ; j++)
            {
                string s;
                cin >> s;
                ss.push_back(s);
                ans[s] = 1e9;
            }
            for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 3 ; j++)
                {
                    if(i == j) continue;
                    mp[ss[i]].insert(ss[j]);
                }
            }
        }
        int lvl = 0 ;
        queue<string> q ;
        ans["Ahmad"] = 0;
        q.push("Ahmad");
        cout << ans.size() << "\n";
        while(q.size())
        {
            int f = q.size() ;
            vector<string> level;
            for(int i = 0 ; i < f ; i++)
            {
                level.push_back(q.front());
                string u = q.front();
                q.pop();
                for(auto j = mp[u].begin() ; j != mp[u].end() ; j++)
                {
                    if(ans[*j] != 1e9) continue;
                    ans[*j] = lvl+1;
                    q.push(*j);
                }
            }
            sort(level.begin(),level.end());
            for(int i = 0 ; i < level.size() ; i++)
                cout << level[i] << " " << lvl << "\n";
            lvl++;
        }
        for(auto i = ans.begin() ; i != ans.end() ; i++)
            if(i-> second == 1e9) cout << i->first << " " << "undefined\n";
    }
}

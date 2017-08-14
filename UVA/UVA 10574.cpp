#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int T = 1 ; T <= t ; T++)
    {
        int n ;
        cin >> n;
        set<pair<int,int> > st;
        for(int i = 0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            st.insert({x,y});
        }
        int ans = 0 ;
        for(auto i = st.begin() ; i != st.end() ; i++)
        {
            int a = i->first, b = i->second;
            for(auto j = i ; j != st.end() ; j++)
            {
                int x = j->first,y = j->second;
                if(a == x || b == y || x < a || y < b) continue;
                if(st.find({a,y}) != st.end() && st.find({x,b}) != st.end()) ans++;
            }
        }
        cout << "Case " << T << ": " << ans << "\n";
    }
}

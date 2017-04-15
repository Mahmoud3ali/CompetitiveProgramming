#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    int t ;
    cin >> t;
    while(t--)
    {
        int n ;
        cin >> n ;
        map<int,deque<int> > mp;
        for(int i = 0 ; i < n ; i++)
        {
            int x , y ;
            cin >> x >> y ;
            mp[y].push_back(x);
        }
        bool ans = 1 ;
        int median = -1e9 ;
        for(auto i = mp.begin() ; i != mp.end() ; i++)
        {
            sort(i->second.begin(),i->second.end());
            while(i->second.size() >= 2)
            {
                int x1 = i->second[0] ;
                int x2 = i->second[i->second.size()-1] ;
                int nw = x2-x1; nw/=2;
                nw+= x1;
                if(median == -1e9) median = nw;
                else if(median != nw) ans = 0 ;
                i->second.pop_front();
                i->second.pop_back();
            }
            if(i->second.size())
            {
                if(median == -1e9) median = i->second[0];
                else if(median != i->second[0]) ans = 0 ;
            }
        }
        if(ans) cout << "YES\n" ;
        else cout << "NO\n" ;
    }
}

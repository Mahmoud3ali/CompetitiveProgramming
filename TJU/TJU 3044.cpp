#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int t = 1;
    while( getline(cin,s) && !(s[0] == '-' && s[1] == '-'))
    {
        vector< pair<int,int> > v;
        if(1)
        {
            stringstream ss;
            ss << s;
            int x, y ;
            ss >> x >> y;
            v.push_back({x,y});
        }
        while( getline(cin,s) && !(s[0] == '-' && s[1] == '-'))
        {
            stringstream ss;
            ss << s;
            int x, y ;
            ss >> x >> y;
            v.push_back({x,y});
        }
        sort(v.begin(), v.end());
        int ans = 0 ;
        map<pair<int,int>,int> mp;
        for(int i = 0 ; i < v.size() ; i++)
        {
            mp.clear();
            for(int j = i+1 ; j < v.size() ; j++)
            {
                if(i == j) continue;
                int x = v[i].first-v[j].first;
                int y = v[i].second-v[j].second;
                int g = __gcd(x,y);
                if(g != 0) x/=g , y/=g;
                mp[make_pair(x,y)]++;
                ans = max(mp[make_pair(x,y)]+1,ans);
            }
        }
        cout << t++ << ". " << ans << '\n';
    }
}

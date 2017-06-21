#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int,int> get_vec(pair<int,int> a, pair<int,int> b)
{
    int x = b.first - a.first, y = b.second-a.second;
    int t = __gcd(x,y); y/=t; x/=t;
    return {x,y};
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, f = 0;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--)
    {
        vector<pair<int,int> > arr;
        string s;
        while(getline(cin,s) && s.size())
        {
            stringstream ss;
            ss << s;
            int x,y ;
            ss >> x >> y;
            arr.push_back({x,y});
        }
        int ans = min((int) arr.size(), 2);
        for(int i = 0 ; i < arr.size() ; i++)
        {
            map<pair<int,int>, int> mp;
            for(int j = 0 ; j < arr.size() ; j++)
            {
                if(i != j)
                ans = max(ans,++mp[get_vec(arr[i],arr[j])]+1);
            }
        }
        cout << ans << "\n";
        if(t) cout << "\n";
    }
}

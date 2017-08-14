#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double dist(double x , double y)
{
    x*=x;
    x+= y*y;
    return sqrt(x);
}
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
        vector<pair<int,int> > v;
        for(int i = 0 ; i < n ; i++)
        {
            int x , y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        int h = 0;
        double ans= 0;
        for(int i = v.size()-1 ; i >= 0 ; i--)
        {
            int curr = v[i].second-h;
//            cout << v[i].first << " " << v[i].second << " " << h << endl;
            if(curr <= 0) continue;
            h = v[i].second;
            double tp = curr;
            tp/= v[i].second-v[i+1].second;
            tp*=dist(v[i].second-v[i+1].second,v[i].first-v[i+1].first);
//            cout << tp << endl;
            ans+= tp;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
}

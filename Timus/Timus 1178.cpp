#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n ;
    cin >> n ;
    vector< pair<pair<int,int>,int> > v;
    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin >> x >> y;
        v.push_back({{x,y},i+1});
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i < v.size() ; i+=2)
    {
        cout << v[i].second << " "<< v[i+1].second << endl;
    }
}

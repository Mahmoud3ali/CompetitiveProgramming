#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
bool pr[(int) 2e7+5];
int main()
{
    memset(pr,1,sizeof(pr));
    for(ll i = 2 ; i <= 2e7 ; i++)
        if(pr[i])
            for(ll j = i*i ; j <= 2e7 ; j+=i) pr[j]= 0;
    vector<pair<int,int> > ans ;
    for(int i = 2 ; i < 2e7 ; i++)
    {
        if(pr[i] && pr[i+2]) ans.push_back({i,i+2});
    }
    int n ;
    while(cin >> n)
    {
        cout << "(" << ans[n-1].first << ", " << ans[n-1].second << ")\n" ;
    }
}

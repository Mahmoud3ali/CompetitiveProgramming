#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
unordered_map<short ,map<ll,short> > mp ;
short go(short idx , ll x)
{
    if(idx == 0) return 0;
    else if(idx < 0) return -100;
    if(mp[idx][x] != 0) return mp[idx][x] ;
    else
    {
        set<short> s ;
        for(int i = idx ; i > 0 ; i--)
        {
            if( (x&(1<<i)) == 0 )
                s.insert(go( idx-i , (x|(1<<i))));
        }
        int ret = 0 ;
        for(auto i = s.begin() ; i != s.end() ; i++)
        {
            if(ret == *i) ret++;
            else if(ret > *i) continue;
            else break;
        }
        return mp[idx][x] = ret ;
    }
}
int main()
{
    int dp[100] = {} ,n, ans = 0,  cnt = 2 , nw = 1;
    for(int i = 1 ; i <= 60 ; i++)
    {
        dp[i] = nw ;
        cnt--;
        if(cnt == 0) cnt = nw+2 , nw++;
    }
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
    {
        int x ;
        cin >> x;
        ans = (ans^dp[x]);
    }
    ans? cout << "NO\n" : cout << "YES\n" ;
}

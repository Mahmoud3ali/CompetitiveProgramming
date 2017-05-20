#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    string s;
    cin >> s;
    int a[40] = {};
    for(int i = 0 ; i < s.size() ; i++) a[s[i]-'a']++;
    double ans = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        ans+= (double) a[s[i]-'a']/s.size() ;
    }
    cout << fixed << setprecision(11) << ans << endl ;
}

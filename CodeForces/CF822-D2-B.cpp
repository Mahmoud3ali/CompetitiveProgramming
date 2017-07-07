#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m ;
    string s, x;
    cin >> n >> m >> s >> x;
    vector<int> ans;
    for(int i = 0 ; i < s.size() ; i++)
        ans.push_back(i+1);
    for(int i = 0 ; i < x.size() ; i++)
    {
        vector<int> tmp;
        bool good = 1 ;
        for(int j = i, c = 0 ; c < s.size() ; c++, j++)
        {
            if(s[c] != x[j]) tmp.push_back(c+1);
            if(j >= x.size()) good = 0;
        }
        if(good && tmp.size() < ans.size()) ans = tmp;
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << " " ;
}

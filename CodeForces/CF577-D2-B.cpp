#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    set<int> st;
    for(int i = 0 ;i < n ;i++)
    {
        vector<int> v;
        int x ;
        cin >> x;
        v.push_back(x%m);
        for(auto j = st.begin() ; j != st.end() ; j++) v.push_back((*j+x)%m);
        st.insert(v.begin(),v.end());
        if(st.find(0) != st.end())
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}

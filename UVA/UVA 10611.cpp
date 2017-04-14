#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    int n ;
    cin >> n ;
    set<int> st ;
    for(int i = 0 ; i < n ; i++)
    {
        int x ;
        cin >> x;
        st.insert(x);
    }
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x ;
        auto a = st.lower_bound(x+1);
        int ans1 = -1 , ans2 = -1;
        if(a != st.end()) ans2 = *a;
        bool duplicated = (st.find(x) != st.end());
        st.insert(x);
        a = st.find(x);
        if(a != st.begin())
        {
            a-- ;
            ans1 = *a;
        }
        if(!duplicated) st.erase(x);
        if(ans1 == -1) cout << "X ";
        else cout << ans1 << " ";
        if(ans2 == -1) cout << "X\n";
        else cout << ans2 << "\n" ;
    }
}

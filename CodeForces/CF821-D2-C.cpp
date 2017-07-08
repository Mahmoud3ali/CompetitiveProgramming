#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    stack<int> s ;
    set<int> st;
    int n ;
    cin >> n;
    n*=2;
    int nw = 1 , ans = 0;
    while(n--)
    {
        string sr ;
        int x;
        cin >> sr ;
        if(sr == "add")
        {
            cin >> x;
            s.push(x);
        }
        else
        {
            if(s.size() && s.top() != nw)
            {
                ans++;
                s = stack<int>();
                nw++;
            }
            else if(s.size() && s.top() == nw)
                nw++ , s.pop();
            else nw++;
        }
    }
    cout << ans << endl;
}

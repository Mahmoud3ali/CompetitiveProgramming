#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<char> s ;
    vector<deque<char> > strings;
    for(int i = 1;  i <= 200 ;i++)
    {
        vector<deque<char> > vec ;
        s.clear();
        for(int j = 1 ; j <= i ; j++) s.push_back('8');
        vec.push_back(s);
        for(int j = 1 ; j <= i ; j++)
        {
            s.pop_front();
            s.push_back('6');
            vec.push_back(s);
        }
        for(int j = vec.size()-1 ; j >= 0 ; j--)
        {
            strings.push_back(vec[j]);
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        bool ans = 0;
        for(int i = 0 ; i < strings.size() && !ans ; i++)
        {
            int nw = 0 , w = 1;
            for(int j = strings[i].size()-1 ; j >= 0 ; j--)
            {
                nw+= (strings[i][j]-'0')*w;
                w*=10;
                w%=x;
                nw%=x;
            }
            if(!nw)
            {
                ans = 1;
                for(int j = 0 ; j < strings[i].size() ; j++)
                    cout << strings[i][j] ;
                cout << "\n" ;
            }
        }
        if(!ans)
        {
            cout << "-1\n" ;
        }
    }
}

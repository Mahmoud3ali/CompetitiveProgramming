#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(getline(cin,s))
    {
        vector<pair<int,int> > needs;
        {
            int x = 0 , y = 0 ;
            s.pop_back();
            for(int i = 0 ; i < s.size() ; i+=2)
            {
                char b = s[i+1];
                char a = s[i];
                if(a == '+') x |= 1<<(b-'A') ;
                else y |= 1<<(b-'A');
            }
            needs.push_back({x,y});
        }
        while(getline(cin,s) && s[0] != '.')
        {
            int x = 0, y = 0;
            s.pop_back();
            for(int i = 0 ; i < s.size() ; i+=2)
            {
                char b = s[i+1];
                char a = s[i];
                if(a == '+') x |= 1<<(b-'A') ;
                else y |= 1<<(b-'A');
            }
            needs.push_back({x,y});
        }
        bool solved = 0;
        int f = (1<<16);
        for(int i = 0 ; i < f && !solved ; i++)
        {
            int cnt = 0 ;
            for(int j = 0 ; j < needs.size() ; j++)
            {
                if(i&needs[j].first || ((f-1)^i)&(needs[j].second)) cnt++;
            }
            if(cnt == needs.size())
            {
                vector<char> ans;
                solved = 1;
                cout << "Toppings: " ;
                for(int j = 0 ; j < 16 ; j++)
                {
                    if( (i>>j)&1) cout << (char) ('A'+j);
                }
                cout << "\n";
                break;
            }
        }
        if(!solved)
        {
            cout << "No pizza can satisfy these requests.\n";
        }
    }
}

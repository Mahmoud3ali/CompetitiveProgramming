#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    map<char,int> mp;
    map<int,char> rev;
    for(char i =  '0' ; i <= '9' ; i++)
    {
        mp[i] = i-'0';
        rev[i-'0'] = i ;
    }
    for(char i =  'A' ; i <= 'Z' ; i++)
    {
        mp[i] = i-'A'+10;
        rev[i-'A'+10] = i;
    }
    int a , b ;
    string s;
    cin >> a >> s;
    if(s == "R") b = -1;
    else b = stoi(s);
    cin >> s;
    reverse(s.begin(),s.end());
    while(s.back() == '0' && s.size() > 1) s.pop_back();
    reverse(s.begin(),s.end());
    ll given = 0 , base = 1;
    for(int i = s.size()-1 ; i >= 0 ; i--)
    {
        given+= mp[s[i]]*base;
        base*=a;
    }
    string ans;
    vector<pair<int,string> > v;
    v.push_back({1,"I"});
    v.push_back({4,"IV"});
    v.push_back({5,"V"});
    v.push_back({9,"IX"});
    v.push_back({10,"X"});
    v.push_back({40,"XL"});
    v.push_back({50,"L"});
    v.push_back({90,"XC"});
    v.push_back({100,"C"});
    v.push_back({400,"CD"});
    v.push_back({500,"D"});
    v.push_back({900,"CM"});
    v.push_back({1000,"M"});
    if(b == -1)
    {
        while(given)
        {
            for(int i= v.size()-1 ; i >= 0 ; i--)
            {
                if(given >= v[i].first)
                {
                    ans+= v[i].second;
                    given -= v[i].first;
                    break;
                }
            }
        }
    }
    else
    {
        while(given != 0)
        {
            ans+= rev[given%b];
            given/=b;
        }
        reverse(ans.begin(),ans.end());
    }
    cout << max(ans,"0") << endl;
}

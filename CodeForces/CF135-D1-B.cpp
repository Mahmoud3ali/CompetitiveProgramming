#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dot(pair<int,int> v , pair<int,int> u)
{
    return u.first*v.first + v.second*u.second;
}
bool checksq(vector<pair<int,int> > a)
{
    sort(a.begin(),a.end());
    do
    {
        int s1 = (a[0].first-a[1].first)*(a[0].first-a[1].first) + (a[0].second-a[1].second)*(a[0].second-a[1].second);
        int s2 = (a[1].first-a[2].first)*(a[1].first-a[2].first) + (a[1].second-a[2].second)*(a[1].second-a[2].second);
        int s3 = (a[2].first-a[3].first)*(a[2].first-a[3].first) + (a[2].second-a[3].second)*(a[2].second-a[3].second);
        int s4 = (a[0].first-a[3].first)*(a[0].first-a[3].first) + (a[0].second-a[3].second)*(a[0].second-a[3].second);
        pair<int,int> v1,v2,v3,v4;
        v1.first = (a[0].first-a[1].first) ; v1.second = (a[0].second-a[1].second);
        v2.first = (a[1].first-a[2].first) ; v2.second = (a[1].second-a[2].second);
        v3.first = (a[2].first-a[3].first) ; v3.second = (a[2].second-a[3].second);
        v4.first = (a[3].first-a[0].first) ; v4.second = (a[3].second-a[0].second);
        if(dot(v1,v2) == 0 && dot(v1,v4)== 0 &&  dot(v3,v2) == 0 && dot(v3,v4) == 0 && s1 == s2 && s2 == s3 && s3 == s4) return 1;
    }
    while(next_permutation(a.begin(),a.end()));
    return 0;
}
bool checkrec(vector<pair<int,int> > a)
{
    sort(a.begin(),a.end());
    do
    {
        int s1 = (a[0].first-a[1].first)*(a[0].first-a[1].first) + (a[0].second-a[1].second)*(a[0].second-a[1].second);
        int s2 = (a[1].first-a[2].first)*(a[1].first-a[2].first) + (a[1].second-a[2].second)*(a[1].second-a[2].second);
        int s3 = (a[2].first-a[3].first)*(a[2].first-a[3].first) + (a[2].second-a[3].second)*(a[2].second-a[3].second);
        int s4 = (a[0].first-a[3].first)*(a[0].first-a[3].first) + (a[0].second-a[3].second)*(a[0].second-a[3].second);
        pair<int,int> v1,v2,v3,v4;
        v1.first = (a[0].first-a[1].first) ; v1.second = (a[0].second-a[1].second);
        v2.first = (a[1].first-a[2].first) ; v2.second = (a[1].second-a[2].second);
        v3.first = (a[2].first-a[3].first) ; v3.second = (a[2].second-a[3].second);
        v4.first = (a[3].first-a[0].first) ; v4.second = (a[3].second-a[0].second);
        if(dot(v1,v2)== 0 &&  dot(v1,v4) == 0 && dot(v3,v2) == 0 && dot(v3,v4) == 0 && s1 == s3 && s2 == s4) return 1;
    }
    while(next_permutation(a.begin(),a.end()));
    return 0;
}
int main()
{
    vector<pair<int,int> > arr;
    for(int i = 0 ; i < 8 ; i++ )
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x,y});
    }
    for(int i = 0 ; i < 1<<8 ; i++)
    {
        if(__builtin_popcount(i) == 4)
        {
            vector<pair<int,int> > s1, s2;
            for(int j = 0 ; j < 8 ; j++)
            {
                if( (i>>j)&1 == 1)
                    s1.push_back(arr[j]);
                else
                    s2.push_back(arr[j]);
            }
            if(checksq(s1) && checkrec(s2))
            {
                cout << "YES\n";
                for(int j = 0 ; j < 8 ; j++)
                {
                    if(i>>j &1 == 1) cout << j+1 << " " ;
                }
                cout << endl ;
                for(int j = 0 ; j < 8 ; j++)
                {
                    if(i>>j &1 == 1) continue;
                    else cout << j+1 << " " ;
                }
                return 0;
            }
            else if(checksq(s2) && checkrec(s1))
            {
                cout << "YES\n";
                for(int j = 0 ; j < 8 ; j++)
                {
                    if(i>>j &1 == 1) continue;
                    else cout << j+1 << " " ;
                }
                cout << endl ;
                for(int j = 0 ; j < 8 ; j++)
                {
                    if(i>>j &1 == 1) cout << j+1 << " " ;
                }
                return 0;
            }
        }
    }
    cout << "NO";
}

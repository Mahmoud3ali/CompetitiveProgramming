#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unsigned long long dist(ll x, ll y, ll x1, ll y1)
{
    return ((x-x1)*(x-x1) + (y-y1)*(y-y1)) ;
}
pair<ll,ll> arr[2005];
ll  n,x1,x2, y1,y2 ;
int main()
{
    cin >> n >> x1>>y1>>x2>>y2;
    for(int i  =0 ;  i < n ; i++) cin >> arr[i].first >> arr[i].second ;
    vector<ll> r1,r2;
    for(int i = 0 ; i < n ; i++)
    {
        ll x = dist(arr[i].first,arr[i].second,x1,y1), y = dist(arr[i].first,arr[i].second,x2,y2);
        r1.push_back(x);
        r2.push_back(y);
    }
    ll R1 = 1e18 ,R2 = 1e18 ;
    for(int i = 0 ; i < r1.size() ; i++)
    {
        ll a = r1[i] , b = 0 ;
        for(int j = 0 ; j < n ; j++)
        {
            ll x = dist(arr[j].first,arr[j].second,x1,y1), y = dist(arr[j].first,arr[j].second,x2,y2);
            if(x > a) b = max(b,y);
        }
        if(R1+R2> a+b) R1 = a , R2 = b;
    }
    for(int i = 0 ; i < r2.size() ; i++)
    {
        ll a = 0 , b = r2[i] ;
        for(int j = 0 ; j < n ; j++)
        {
            ll x = dist(arr[j].first,arr[j].second,x1,y1), y = dist(arr[j].first,arr[j].second,x2,y2);
            if(y > b) a = max(a,x);
        }
        if(R1+R2> a+b) R1 = a , R2 = b;
    }
    cout << R1+R2 << endl;
}

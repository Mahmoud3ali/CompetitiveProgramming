#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
bool ss(pair<int,int> x,pair<int,int> y)
{
    return (x.second-x.first+1) < (y.second-y.first+1);
}
int main()
{
    int n , m;
    cin >> n >> m ;
    int a[n+1];
    deque< pair<int,int> > arr[2];
    int s = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        m-= (a[i]<0);
        if(( i )&& ((a[i] >= 0) != (a[i-1] >= 0)))
        {
            arr[a[s]>=0].push_back({s,i-1});
            s = i;
        }
    }
    if(m < 0)
    {
        cout << "-1\n" ;
        return 0;
    }
    arr[a[s]>=0].push_back({s,n-1});
    if(arr[1].size() && arr[1][0].first == 0) arr[1].pop_front();
    if(arr[1].size() && arr[1][arr[1].size()-1].second == n-1)arr[1].pop_back();
    sort(arr[1].begin(),arr[1].end(),ss);
    int cnt = arr[0].size()*2;
    for(int i = 0; i < arr[1].size() ; i++)
    {
        int s = arr[1][i].first , e = arr[1][i].second ;
        if(m-(e-s+1) >= 0)
        {
            ----cnt;
            m-=(e-s+1);
        }
    }
    if(a[n-1] < 0) cnt--;
    else
    {
        int k = 0 ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(a[i] >= 0) k++;
            else break;
        }
        if(k <= m) cnt-- ;
    }
    cout << max(0,cnt) << endl ;
}

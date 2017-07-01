#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dist(pair<int,int> a , pair<int,int> b)
{
    double x = a.first-b.first , y = b.second-a.second;
    return x*x + y*y;
}
double r ;
int go(pair<int,int> cntr, pair<int,int> a,pair<int,int>b,pair<int,int>c,pair<int,int>d)
{
    double arr[4] ;
    arr[0] = dist(cntr,a);
    arr[1] = dist(cntr,b);
    arr[2] = dist(cntr,c);
    arr[3] = dist(cntr,d);
    int cnt = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        if(arr[i] < r) cnt++;
    }
    if(cnt == 4) return 0;
    else if(cnt != 0) return 1;
    else return 2;
}
int main()
{
    int n ;
    bool first = 1;
    while(cin >> n)
    {
        if(!first) cout << "\n";
        r = (2*n-1)*(2*n-1)*0.25;
        int cx = n, cy = n ;
        int ans[3] = {};
        for(int i = 0 ; i <= 2*n ; i++)
        {
            for(int j = 0 ; j <= 2*n ; j++)
            {
                ans[go({cx,cy}, {i,j},{i+1,j},{i,j+1},{i+1,j+1})]++;
            }
        }
        cout << "In the case n = " << n << ", " << ans[1] << " cells contain segments of the circle.\n";
        cout << "There are " << ans[0] <<" cells completely contained in the circle.\n";
        first = 0;
    }
}

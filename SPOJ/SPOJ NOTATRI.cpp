#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n ;
    while(cin >> n && n)
    {
        int a[n+5] , ans = 0;
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        sort(a,a+n);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                int s = 0 , e = n-1 , t = a[i]+a[j] , as = -1;
                while(s <= e)
                {
                    int mid = s+(e-s)/2;
                    if(a[mid] > t) as = mid , e = mid-1;
                    else s = mid+1;
                }
                if(as != -1)
                ans+=n-as;
            }
        }
        cout << ans << endl;
    }
}

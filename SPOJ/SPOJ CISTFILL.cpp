#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, s[(int) 1e5], h[(int) 1e5], w[(int) 1e5], l[(int) 1e5];
double check(double mid)
{
    double ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        double x = h[i]+s[i];
        x = min(mid,x);
        x-=s[i];
        if(x < 0) continue;
        ans+= x*w[i]*l[i];
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n ;
        ll tot = 0;
        for(int i = 0; i < n ; i++)
        {
            cin >> s[i] >> h[i] >> w[i] >> l[i];
            tot+= (h[i]*w[i]*l[i]);
        }
        double f ;
        cin >> f;
        if(tot < (ll)f)
        {
            cout << "OVERFLOW\n";
            continue;
        }
        double s = 0, e = 1e7, ans = -1, cnt = 100;
        while(cnt--)
        {
            double mid = s/2+e/2;
            if(f-check(mid) >= 1e-9) s = mid , ans = mid;
            else e = mid;
        }
        cout << fixed << setprecision(2) << ans << endl ;
    }
}

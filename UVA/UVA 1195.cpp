#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int p[(int) 1e6];
int main()
{
    for(int i = 0 ; i < 1e6 ; i++) p[i] = i;
    vector<int> v;
    for(ll i = 2 ; i <= 1e5 ; i++)
    {
        if(p[i] == i)
        {
            for(ll j = 2*i ; j <= 1e5 ; j+=i) p[j] = i;
            v.push_back(i);
        }
    }
    ll m, a, b;
    while(cin >> m >> a >> b && m+a+b > 0)
    {
        ll ans = 0, q, w;
        for(int i = 0 ; i < v.size() ; i++)
        {
            ll d = v[i], k = m/v[i];
            int s = i , e = v.size()-1, as = -1 , as1 = -1;
            while(s <= e)
            {
                int mid = s+(e-s)/2;
                if(a*v[mid] <= d*b) as = mid , s = mid+1;
                else e = mid-1;
            }
            if(as == -1) continue;
            s = i , e = as;
            while(s <= e)
            {
                int mid = s+(e-s)/2;
                if((ll) v[mid]*d <= m) as1 = mid , s = mid+1;
                else e = mid-1;
            }
            if(as1 == -1) continue;
            k = v[as1];
            if(d*k > ans) q = d , w = k , ans = d*k;
        }
        cout << q << " " << w << endl;
    }
}

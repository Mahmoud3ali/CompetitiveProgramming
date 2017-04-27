#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int t[(int) 3e5+5][18] , accum[(int) 3e5+5];
int getnorm(int L, int R)
{
    int l = L, ans = 0;
    for(int i = 17 ; i >= 0 ; i--)
    {
        if(l+(1<<i)-1 <= R)
        {
            ans = __gcd(ans,t[l][i]);
            l+= (1<<i);
        }
    }
    int t = 0;
    if(L-1 >= 0) t = accum[L-1];
    if(ans == 1)
    {
        if(accum[R] - t == R-L+1) return ans;
        else return -1;
    }
    else return ans ;
}
int main()
{
    int n ;
    cin >> n ;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
        if(arr[i] == 1) accum[i]++;
        if(i != 0)
            accum[i] += accum[i-1];
    }
    for(int i = 0 ; i < n ; i++) t[i][0] = arr[i];
    for(int j = 1 ; j <= 17 ; j++)
    {
        for(int i = 0 ; i <= n-(1<<j) ; i++)
        {
            t[i][j] = __gcd(t[i][j-1], t[i+(1<<(j-1))][j-1]) ;
        }
    }
    set<int> ans ;
    int best = 0 ;
    for(int i  =0 ; i < n ; i++)
    {
        int s = 0, e = i, a = -1 , b = -1;
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            int tmp = getnorm(mid,i) ;
            if(tmp%arr[i] == 0 && tmp != 1) a = mid, e = mid-1;
            else s = mid+1;
        }
        s = i, e = n-1;
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            int tmp = getnorm(i,mid) ;
            if(tmp%arr[i] == 0 && tmp > 0) b = mid, s = mid+1;
            else e = mid-1;
        }
        if(arr[i] == 1)
        {
            a = 0 , b = n-1;
        }
        if(a != - 1 && b != -1)
        {
            if(b-a > best)
            {
                best = b-a;
                ans.clear();
                ans.insert(a+1);
            }
            else if(b-a == best)
                ans.insert(a+1);
        }
    }
    cout << ans.size() << " " << best << "\n" ;
    for(auto i = ans.begin() ; i != ans.end(); i++)
        cout << *i << " ";
}

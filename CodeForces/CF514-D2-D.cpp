#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int t[10][(int) 1e5+5][17] ;
vector<int> go(int L , int R)
{
    vector<int> nw;
    nw.resize(5);
    for(int i = 0 ; i < 5 ; i++)
    {
        int l = L ;
        int curr = 0;
        for(int j = 17 ; j >= 0 ; j--)
        {
            if(l+(1<<j)-1 <= R)
            {
                curr = max(curr,t[i][l][j]) ;
                l+= (1<<j);
            }
        }
        nw[i] = curr ;
    }
    return nw ;
}
int main()
{
    int n , m , k ;
    cin >> n >> m >> k ;
    int arr[n][m];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++) cin >> arr[i][j];
    for(int f = 0 ; f < m ; f++)
    {
        for(int i = 0 ; i < n ; i++)
            t[f][i][0] = arr[i][f];
        for(int j = 1 ; j <= 17  ; j++)
        {
            for(int i = 0 ; i <= n-(1<<j) ; i++)
            {
                t[f][i][j] = max(t[f][i][j-1] , t[f][i+(1<<(j-1))][j-1]);
            }
        }
    }
    int dist = 0 ;
    vector<int> ans ;
    ans.resize(5);
    for(int i = 0 ; i < n ; i++)
    {
        int s = i , e = n-1 , as = -1;
        vector<int> kk ;
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            vector<int> tmp = go(i,mid);
            int cnt = 0 ;
            for(int i = 0 ; i < tmp.size() ; i++) cnt+=tmp[i];
            if(cnt <= k)
            {
                kk = tmp;
                as = mid ;
                s = mid+1;
            }
            else e = mid-1;
        }
        if(dist <= as-i+1 && as != -1)
        {
            dist = as-i+1;
            ans = kk ;
        }
    }
    for(int i = 0 ; i < m ; i++)
        cout << ans[i] << " " ;
}

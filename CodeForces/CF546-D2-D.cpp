#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int a[(int) 6e6+5] ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2 ; i <= 6e6 ; i++)
    {
        if(a[i] != 0) continue;
        for(int j = i ; j <= 6e6 ; j+=i)
        {
            int cnt = 0 ;
            int t = j;
            while(t%i == 0) t/=i , cnt++;
            a[j]+=cnt;
        }
    }
    for(int i = 1 ; i <= 6e6 ; i++)
        a[i] +=a[i-1];
    int t;
    cin >> t;
    while(t--)
    {
        int A , b;
        cin >> A >> b;
        cout << a[A]-a[b] << "\n";
    }
}

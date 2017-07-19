#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll mod =  1073741824;
int arr[(int) 1e6+5];
int main()
{
    for(int i= 1 ; i <= 1e6 ; i++) arr[i] = 1;
    for(int i = 2 ; i <= 1e6 ; i++)
    {
        if(arr[i] != 1) continue;
        for(int j = i ; j <= 1e6 ; j+=i)
        {
            ll cnt = 0 ;
            int t = j;
            while(t%i == 0) cnt++ , t/=i;
            arr[j] *= (cnt+1);
            arr[j]%=mod;
            cnt++;
        }
    }
    int a, b, c;
    cin >> a >> b >> c;
    ll ans = 0 ;
    for(int i = 1 ; i <= a ; i++)
        for(int j = 1 ; j <= b; j++)
            for(int k = 1 ; k <= c ; k++)
            {
                ans+= arr[i*j*k];
                ans%=mod;
            }
            cout << ans << endl;
}

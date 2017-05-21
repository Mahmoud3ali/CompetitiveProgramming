#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int mod = 1e9+7;
int main()
{
    // consider u r given a sorted array
    // how many times does your arr[n-1] (max element) appears with positive coefficient ?
    // consider this case 1 2 3 4 5 , 5 will appear 4 times with subsequences with size 2 -> 4 choose 1
    // 5 will appear also 6 times in subsequences with size 3 -> 4 choose 2
    // how many times in total ? 4 choose i where i is integer belong to [1,4] , which is equal to (2^4) -1
    // so does every element in your array except the smallest one .
    // how many times will arr[i] appear with negative coefficient ?
    // e~z the same concept 1 will appear 4 choose i where i is integer belong to interval [1,4]
    // interestingly enough it's the reverse of the previous array , you can prove it using your pen , even though it makes sense if u take time to think about it.
    int n ;
    cin >> n ;
    ll twopow[n+5];
    twopow[0] = 1;
    for(int i = 1 ; i < n+2 ; i++) twopow[i] = (twopow[i-1]*2)%mod;
    ll ans = 0;
    ll arr[n+5];
    if(n == 1)
    {
        cout << 0 << endl ;
        return 0;
    }
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    sort(arr,arr+n);
    for(int i = 1 ; i < n ; i++) ans = (ans+((arr[i])*(twopow[i]-1)))%mod;
    for(int i = 0 ; i < n-1 ; i++) ans = (ans-(arr[i]*(twopow[n-i-1]-1)))%mod;
    if(ans < 0) ans+= mod;
    cout << ans << endl ;
}

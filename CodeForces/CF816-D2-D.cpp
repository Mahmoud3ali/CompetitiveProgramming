#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[(int) 1e5 + 5] , mod = 1e9+7;
ll fast_power(ll base , ll power)
{
    if(power == 1) return base%mod ;
    else if(power%2) return (base*fast_power((base*base)%mod,power/2))%mod;
    else return (fast_power((base*base)%mod,power/2))%mod;
}
ll ncr(int a , int b)
{
	if(a < 0  || b < 0) return 0;
	ll x = f[a];
	x%=mod;
	ll y = f[b]* f[a-b];
	y%=mod;
	x = x*fast_power(y,mod-2);
	x%=mod;
	return x;
}
int main()
{
	f[0] = 1;
	f[1] = 1;
	for(ll i = 2 ; i <= 1e5 ; i++)
	{
		f[i] = f[i-1]*i;
		f[i] %= mod;
	}
	int n ;
	cin >> n ;
	ll arr[n] , coff[n];
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	int tp = (n-1)/2;
	for(int i = 0 , j = 0 ; i <= tp && n%4 != 3 ; j+=2,i++)
	{
		coff[j] = coff[j+1] = ncr(tp,i);
	}
	if(n%4 == 1) for(int i = 1 ; i < n ; i+=2) coff[i] = 0;
	if(n%4 == 0) for(int i = 1 ; i < n ; i+=2) coff[i] *=-1;
	tp = (n-3)/2;
	if(n%4 == 3)
	{
		for(int i = 0 , j = 0 ; i <= tp ; j+=2,i++)
		{
			coff[j] = ncr(tp,i)-ncr(tp,i-1);
			coff[j+1] = 2*ncr(tp,i);
		}
		coff[n-1] = -1;
	}
	ll ans = 0 ;
	for(int i = 0 ; i < n ; i++)
	{
		ans+= coff[i]*arr[i];
		ans%=mod;
	}
	if(ans < 0) ans+= mod;
	cout << ans << endl;
}
/*
 * How i managed to solve it
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
map<char, char> mp;
vector<char> merge(vector<char> a, vector<char> b, bool eshara)
{
	if(eshara == 1)
	{
		for(int i = 0 ; i < b.size() ; i++)
		{
			b[i] = mp[b[i]];
		}
	}
	vector<char> beb;
	for(int i = 0; i < a.size() ; i++) beb.push_back(a[i]);
	for(int i = 0; i < b.size() ; i++) beb.push_back(b[i]);
	return beb;
}
int main()
{
	for(char i = 'a' , j = 'A' ; j <= 'Z' ; j++,i++)
	{
		mp[i] = j;
		mp[j] = i;
	}
	deque< vector<char> > s;
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		char f = 'a'+i;
		s.push_back({f});
	}
	bool eshara = 0;
	while(s.size() > 1)
	{
		int f = s.size();
		for(int i = 0 ; i < f-1 ; i++)
		{
			vector<char> dq = merge(s[0], s[1], eshara);
			s.pop_front();
			s.push_back(dq);
			eshara = !eshara;
		}
		s.pop_front();
	}
	pair<int,int> arr[26];
	for(int i = 0 ; i < s[0].size() ; i++)
	{
		if(s[0][i] <= 'z' && s[0][i] >= 'a') arr[s[0][i]-'a'].first++ ;
		else arr[mp[s[0][i]]-'a'].second-- ;
	}
	for(int i = 0 ; i < 26 ; i++)
		cout << (char) ('a'+i) << " " << arr[i].first + arr[i].second << endl;
}
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[150];
int solve(int n)
{
	if(dp[n] != -1) return dp[n];
	int ret = 0 ;
	for(int i = 1 ; i < n ; i++)
	{
		int f = solve(max(i,n-i));
		ret |= !f;
	}
	return dp[n] = ret;
}
int main()
{
	int n;
	cin >> n;
	int x = 0 ;
	for(int i = 0 ; i < n ; i++)
	{
		int f ;
		cin >> f;
		x = max(f,x);
	}
	for(int i = 0 ; i <= 35 ; i++)
	{
		ll k = 1<<i;
		k--;
		if(k == x)
		{
			cout << "Mike\n";
			return 0;
		}
	}
	cout << "Constantine\n";
}

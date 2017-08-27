#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int ncr(int n , int r)
{
	if(r == 0 || r == n) return 1;
	if(dp[n][r] != -1) return dp[n][r];
	return dp[n][r] = ncr(n-1,r-1)+ncr(n-1,r);
}
double blck ;
void solve(int w , int b , double prop)
{
	if(w+b == 1)
	{
		if(b) blck += prop;
		return ;
	}
	double f = ncr(w,2);
	f/= ncr(w+b,2);
	if(w >= 2)
		solve(w-1,b,prop*f);
	f = ncr(w,1)*ncr(b,1);
	f /= ncr(w+b,2);
	if(b >= 1 && w >= 1)
		solve(w-1,b,prop*f);
	f = ncr(b,2);
	f/= ncr(w+b,2);
	if(b >= 2)
		solve(w+1,b-2,prop*f);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		double ans;
		if (b % 2 == 0)
			ans = 0;
		else
			ans = 1;
		cout << fixed << setprecision(8) << ans << "\n";
	}
}

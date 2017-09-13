#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v, ans;
bool vis[30];
int m ;
void solve(int n , int m , int maxi)
{
	if (m == 0)
	{
		if (n == 0)
		{
			cout << ans[0];
			for (int i = 1; i < ans.size(); i++)
				cout << " " << ans[i];
			cout << "\n";
		}
		return;
	}
	for (int i = maxi; i <= n; i++)
	{
		bool good = 1;
		for (int j = 0; j < v.size() && good; j++)
		{
			if (i % v[j] == 0 && vis[j]) good = 0;
		}
		if (good)
		{
			for (int j = 0; j < v.size(); j++) if (i % v[j] == 0) vis[j] = 1;
			ans.push_back(i);
			solve(n - i , m-1 , max(maxi,i));
			ans.pop_back();
			for (int j = 0; j < v.size(); j++) if (i % v[j] == 0) vis[j] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 2; i <= 100; i++)
	{
		bool p = 1;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
				p = 0;
		}
		if (p)
			v.push_back(i);
	}
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++)
	{
		ans.clear();
		memset(vis, 0, sizeof vis);
		int n;
		cin >> n >> m;
		cout << "Case " << T << ":\n";
		solve(n,m,1);
	}
}

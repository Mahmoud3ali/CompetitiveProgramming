#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k ;
int solve(int n)
{
	if(n < k) return 0;
	int ret = (k == 1);
	for(int i = 2 ; i*i <= n ; i++)
	{
		if(n%i == 0)
		{
			int f = i , x = n/i;
			if (f >= k)
			{
				if (x & 1)
					ret |= !solve(f);
				else
					ret = 1;
			}
			if (x >= k)
			{
				if (f & 1)
					ret |= !solve(x);
				else
					ret = 1;
			}
		}
	}
	return ret;
}
int main()
{
	int n , m ;
	cin >> n >> m >> k;
	if(n%2 == 0) cout << "Marsel\n";
	else
	{
		int s = solve(m);
		if(s) cout << "Timur\n";
		else cout << "Marsel\n";

	}
}

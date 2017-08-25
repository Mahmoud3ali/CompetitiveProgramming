#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	while(cin >> n && n)
	{
		ll ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			ll x;
			cin >> x;
			ans = ans^x;
		}
		if(ans) cout << "Yes\n";
		else cout << "No\n";
	}
}

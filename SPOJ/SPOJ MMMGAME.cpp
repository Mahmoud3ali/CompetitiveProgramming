#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, ans = 0;
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			int x;
			cin >> x;
			x--;
			ans^=x;
		}
		if(ans) cout << "John\n";
		else cout << "Brother\n";
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n ;
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i++)
		{
			int x;
			cin >> x;
			if(x&1) ans^=x;
		}
		if(ans) cout << "Tom Wins\n";
		else cout << "Hanks Wins\n";
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	/*
	 * 0 -> 1
	 * 1 -> 0
	 * 2 -> 2
	 * 3 -> 3
	 * 4 -> 4
	 * only one special case if all are ones
	 * that's because 1 = 0 so it's not counted as a move
	 * so you need to make it a move yourself by counting it seperately.
	 */
	int t;
	cin >> t;
	while(t--)
	{
		int n, ans = 0, cnt= 0;
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			int x;
			cin >> x;
			ans^=x;
			cnt+=(x==1);
		}
		if(cnt == n)
		{
			if(cnt%2 == 0) cout << "John\n";
			else cout << "Brother\n";
		}
		else if(ans) cout << "John\n";
		else cout << "Brother\n";
	}
}

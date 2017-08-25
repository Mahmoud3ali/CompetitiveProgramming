#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	for(int T= 1 ; T <= t ; T++)
	{
		int n ;
		int ans = 0 , nw = 0;
		cin >> n ;
		string s;
		for(int i = 0 ; i < n ; i++)
		{
			char f;
			cin >> f;
			s+=f;
		}
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i] == 'W') ans = 0;
			else ans++;
			nw = i+1;
			if(ans == 3)
				break;
		}
		cout << "Case " << T << ": ";
		if(nw == n && ans != 3) cout << "Yay! Mighty Rafa persists!\n";
		else cout << nw << "\n";
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t, T = 1;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int sum  = 0 , moves = 0 ;
		for(int i = 0 ; i < s.size() ; i++) sum+= s[i]-'0';
		if (sum % 3)
		{
			for (int i = 0; i < s.size(); i++)
			{
				if( (sum-(s[i]-'0'))%3 == 0)
				{
					s[i] = '.';
					sum-= (s[i]-'0');
					moves++;
					break;
				}
			}
		}
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i] == '.') continue;
			if( (s[i]-'0')%3 == 0) moves++;
		}
		cout << "Case " << T++ << ": " ;
		if(moves%2) cout << "S\n";
		else cout << "T\n";
	}
}

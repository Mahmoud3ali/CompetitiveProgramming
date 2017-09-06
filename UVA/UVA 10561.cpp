#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[250];
int solve(int n)
{
	if(dp[n] != -1) return dp[n];
	set<int> st;
	for(int i = 1 ; i <= n ; i++)
	{
		st.insert(solve(max(i-3,0))^solve(max(n-i-2,0)));
	}
	int ret = 0;
	for(auto i = st.begin() ; i != st.end() && ret == *i ; i++) ret++;
	return dp[n] = ret;
}
int trip(string s)
{
	if(s.find("XX.") != -1) return 1;
	if(s.find("X.X") != -1) return 1;
	if(s.find(".XX") != -1) return 1;
	for(int i = 0 ;i < s.size() ; i++)
	{
		if(s[i] == 'X')
		{
			if(i-1 >= 0) s[i-1] = '?';
			if(i-2 >= 0) s[i-2] = '?';
			if(i+1 < s.size()) s[i+1] = '?';
			if(i+2 < s.size()) s[i+2] = '?';
			s[i] = '?';
		}
	}
	int nw = 0, ans = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '.') nw++;
		else
		{
			ans^= solve(nw);
			nw = 0;
		}
	}
	ans^= solve(nw);
	return ans;
}
int main()
{
	freopen("out.txt","w",stdout);
	freopen("in.txt","r",stdin);
	memset(dp,-1,sizeof dp);
	dp[0] = 0 ;
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		// search for .XX , X.X , XX.
		vector<int> ans;
		for (int i = 0; i < s.size() - 2; i++)
		{
			string f;
			f += s[i];
			f += s[i + 1];
			f += s[i + 2];
			if (f == ".XX")
			{
				ans.push_back(i + 1);
				continue;
			}
			if (f == "X.X")
			{
				ans.push_back(i + 2);
				i++;
				continue;
			}
			if (f == "XX.")
			{
				ans.push_back(i + 3);
				i +=2;
				continue;
			}
		}
		if (ans.size() == 0 && trip(s))
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '.')
				{
					s[i] = 'X';
					if (!trip(s))
					{
						ans.push_back(i + 1);
					}
					s[i] = '.';
				}
			}
		}
		if (ans.size())
		{
			cout << "WINNING\n";
			cout << *ans.begin();
			auto i = ans.begin();
			i++;
			for (; i != ans.end() ; i++)
				cout << " " << *i;
		}
		else
			cout << "LOSING\n";
		cout << "\n";
	}
}

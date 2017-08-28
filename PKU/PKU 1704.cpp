#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int solve(vector<int> v)
{
	int ret = 0 ;
	for(int i = 0 ; i < v.size() ; i++)
	{
		if(i+1 != v[i])
		{
			vector<int> cp = v;
			while(cp[i] != i+1)
			{
				cp[i]--;
				ret |= !solve(cp);
			}
		}
	}
	return ret;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n ;
		cin >> n ;
		vector<int> v;
		for(int i = 0 ; i < n ; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		v.push_back(0);
		sort(v.begin(),v.end());
		int ans = 0 , cnt = 1;
		for(int i = v.size()-1 ; i > 0 ; i--)
		{
			int diff = v[i]-v[i-1]-1;
			if(cnt&1)
			ans^=diff;
			cnt++;
		}
		if(ans == 0) cout << "Bob will win\n";
		else cout << "Georgia will win\n";
	}
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[25];
string f;
set<string> st;
void solve(int idx , string ans)
{
	if(idx == f.size())
	{
		if(ans[0] != '0') st.insert(ans);
		return;
	}
	ans.push_back(f[idx]);
	solve(idx+1,ans);
	ans.pop_back();
	reverse(ans.begin(),ans.end());
	ans+=f[idx];
	reverse(ans.begin(),ans.end());
	solve(idx + 1, ans);
}
int main()
{
	arr[0] = 1;
	for(int i = 1 ; i < 16 ; i++) arr[i] = arr[i-1]*10;
	cin >> f;
	string dum ;
	solve(0,dum);
	auto ans = *st.begin();
	cout << ans << endl;
	string sec ;
	int spec = f.size()-1;
	for(int i = f.size()-1; i >= 0 ; i--)
	{
		if(f[i] != '0' && ( (f[spec] > f[i]) || (f[spec] == '0') ))  spec = i;
	}
	for(int i = 0 ; i < f.size() ; i++)
	{
		if(i >  spec) sec+=f[i];
		else if(i == spec) sec.insert(sec.begin(), f[i]);
		else
		{
			if(f[i] <= sec[0]) sec.insert(sec.begin(), f[i]);
			else sec+=f[i];
		}
	}
	cout << sec << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int> > arr[(int) 1e5+5];
int tree[(int)5e5+5];
void update(int node , int s , int e , int idx , int val)
{
	if(s == e)
	{
		tree[node] = val;
		return;
	}
	int mid = (s+e)/2;
	if(s <= idx && mid >= idx) update(node*2,s,mid,idx,val);
	else update(node*2+1,mid+1,e,idx,val);
	tree[node] = tree[node*2]^tree[node*2+1];
}
int query(int node , int s , int e , int l , int r)
{
	if(s > r || e < l) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	int x = query(node*2,s,mid,l,r);
	x = x^query(node*2+1,mid+1,e,l,r);
	return x;
}
int dp[(int) 1e5+5];
int solve(int n)
{
	if(dp[n] != -1) return dp[n];
	int ret = 0 ;
	set<int> st;
	for(int i = 0 ; i < arr[n].size() ; i++)
	{
		int qq= query(1,0,1e5,arr[n][i].first,arr[n][i].second);
		st.insert(qq);
	}
	for(auto i = st.begin() ; i != st.end() && ret == *i ; i++) ret++;
	return dp[n] = ret;
}
int main()
{
	memset(dp,-1,sizeof dp);
	for(int i = 1 ; i <= 1e5 ; i++)
	{
		ll ans = i;
		for(int j = i+1 ; j <= 1e5 ; j++)
		{
			ans+=j;
			if(ans >= 1e5) break;
			arr[ans].push_back({i,j});
		}
	}
//	for(int i = 1 ; i <= 100 ; i++)
//		cout << i << " " << arr[i].size() << endl;
	for(int i = 1 ; i <= 1e5 ; i++)
	{
		int y = solve(i) ;
		update(1,0,1e5,i,y);
	}
	int n;
	cin >> n;
	int finl =  solve(n);
	if(finl)
	{
		int k = 1e9;
		for (int i = 0; i < arr[n].size(); i++)
			if(query(1,0,1e5,arr[n][i].first,arr[n][i].second) == 0)
				k = min(k,arr[n][i].second-arr[n][i].first+1);
		cout << k << endl;
	}
	else cout << "-1\n";
}

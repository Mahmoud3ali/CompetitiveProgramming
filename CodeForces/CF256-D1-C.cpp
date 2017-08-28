#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[(int) 1e6+5];
bool tree[5][(int) 5e6+5];
int hez(ll x)
{
	ll s = 0 , e = ceil(sqrt(x)) , ans = 0;
	while(s <= e)
	{
		ll mid = s+(e-s)/2;
		if(mid*mid*mid*mid >= x)
		{
			ans = mid;
			e = mid-1;
		}
		else s = mid+1;
	}
	return ans;
}
void update(int node , int s , int e , int idx , int val)
{
	if(s == e)
	{
		tree[val][node] = 1;
		return;
	}
	int mid= (s+e)>>1;
	if(s <= idx && mid >= idx) update(node*2,s,mid,idx,val);
	else update(node*2+1,mid+1,e,idx,val);
	tree[val][node] = tree[val][node*2]|tree[val][node*2+1];
}
bool query(int node , int s , int e , int l , int r , int val)
{
	if(s > r || e < l) return 0;
	if(l <= s && r >= e) return tree[val][node];
	int mid = (s+e)>>1;
	bool ret = query(node*2,s,mid,l,r,val);
	ret = ret|query(node*2+1,mid+1,e,l,r,val);
	return ret;
}
int solve(ll n)
{
	if(n <= 1e6 && dp[n] != -1) return dp[n];
	ll x = hez(n);
	ll y = floor(sqrt(n));
	int ret = 0 ;
	while(query(1,0,1e6,x,y,ret)) ret++;
	if(n <= 1e6) return dp[n] =  ret;
	else return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,-1,sizeof dp);
	for(int i = 1 ; i <= 1e6 ; i++) update(1,0,1e6,i,solve(i));
	int n;
	cin >> n ;
	ll ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		ll in;
		cin >> in;
		ans^=solve(in);
		in--;
	}
	if(ans) cout << "Furlo\n";
	else cout << "Rublo\n";
}

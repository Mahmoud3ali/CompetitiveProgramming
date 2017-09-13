#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[(int) 5e6] , t[(int) 5e6] , arr[(int) 1e6+5];
void build(int node , int s , int e)
{
	if(s == e)
	{
		t[node] = sum[node] = arr[s];
		return ;
	}
	int mid = (s+e)/2;
	build(node*2,s,mid);
	build(node*2+1,mid+1,e);
	t[node] = min(t[node*2],t[node*2+1]);
	sum[node] = sum[node*2]+sum[node*2+1];
}
void update(int node , int s , int e , int idx , int val)
{
	if(s == e)
	{
		t[node]+= val;
		sum[node]+=val;
		return;
	}
	int mid = (s+e)/2;
	if(s <= idx && mid >= idx) update(node*2,s,mid,idx,val);
	else update(node*2+1,mid+1,e,idx,val);
	t[node] = min(t[node*2],t[node*2+1]);
	sum[node] = sum[node*2]+sum[node*2+1];
}
ll q_min(int node , int s , int e , int l , int r)
{
	if(s > r || e < l) return 1e9+5;
	if(l <= s && e <= r) return t[node];
	int mid = (s+e)/2;
	return min(q_min(node*2,s,mid,l,r) , q_min(node*2+1,mid+1,e,l,r));
}
ll q_sum(int node , int s , int e , int l , int r)
{
	if(s > r || e < l) return 0;
	if(l <= s && e <= r) return sum[node];
	int mid = (s+e)/2;
	return q_sum(node*2,s,mid,l,r)+q_sum(node*2+1,mid+1,e,l,r);
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	build(1,0,n-1);
	int t;
	cin >> t;
	while(t--)
	{
		string s ;
		int a , b;
		cin >> s >> a>> b;
		if(s == "GROW") update(1,0,n-1,b,a);
		else if(s == "EAT") update(1,0,n-1,b,a*-1);
		else cout << q_sum(1, 0, n-1, a, b) - q_min(1, 0, n-1, a, b) << "\n";
	}
}

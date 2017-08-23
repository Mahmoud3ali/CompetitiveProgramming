#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<pair<int,int> > st;
int dp[1<<17] , code[4][4];
pair<int,int> rcode[17];
int solve(int n)
{
	if(dp[n] != -1) return dp[n];
	int ret = 0 ;
	set<int> grundy;
	for(int i = 0 ; i < 16 ; i++)
	{
		if(n&(1<<i))
		{
			for(auto j = st.begin() ; j != st.end() ; j++)
			{
				int curr = n;
				int bi = rcode[i].first , bj = rcode[i].second;
				int ei = bi-j->first , ej = bj-j->second;
				if(ei < 0 || ej < 0) continue;
				bool good = 1;
				for(; ei <= bi && good ; ei++)
				{
					for(int f = ej ; f <= bj && good ; f++)
					{;
						if(curr&(1<<code[ei][f])) curr -= (1<<code[ei][f]);
						else good = 0;
					}
				}
				if(good) grundy.insert(solve(curr));
			}
		}
	}
	for(auto i = grundy.begin() ; i != grundy.end() ; i++)
		if(ret == *i) ret++;
	return dp[n] = ret;
}
int t[(int) 5e5+5] , arr[(int) 1e5+5];
void build(int node , int s , int e)
{
	if(s == e)
	{
		t[node] = arr[s];
		return;
	}
	int mid = (s+e)/2;
	build(node*2,s,mid);
	build(node*2+1,mid+1,e);
	t[node] = t[node*2]^t[node*2+1];
}
int query(int node , int s , int e , int l , int r)
{
	if(s > r || e < l) return 0;
	if(l <= s && r >= e) return t[node];
	int mid = (s+e)/2;
	int left = query(node*2,s,mid,l,r);
	left = left^query(node*2+1,mid+1,e,l,r);
	return left;
}
void update(int node , int s , int e , int idx , int val)
{
	if(s == e)
	{
		arr[s] = val;
		t[node] = arr[s];
		return ;
	}
	int mid = (s+e)/2;
	if (s <= idx && idx <= mid) update(node * 2, s, mid, idx, val);
	else update(node*2+1, mid+1, e, idx , val);
	t[node] = t[node*2]^t[node*2+1];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for(int i = 0 , s = 15 ; i < 4 ; i++)
		for(int j = 0 ; j < 4 ; j++)
		{
			st.insert({ i, j });
			code[i][j] = s, rcode[s] = {i,j};
			s--;
		}
	for(int i = 1 ; i < (1<<16) ; i++)  solve(i) ;
	int q;
	cin >> q;
	while (q--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int nw = 0;
			for (int j = 15; j >= 0; j--)
			{
				char f;
				cin >> f;
				if (f == '1')
					nw |= (1 << j);
			}
			arr[i] = solve(nw);
		}
		build(1, 0, n - 1);
		while (m--)
		{
			int f;
			cin >> f;
			if (f == 1)
			{
				int l, r;
				cin >> l >> r;
				l--;
				r--;
				int sss = query(1, 0, n - 1, l, r) ;
				if(sss) cout << "Pishty\n";
				else cout << "Lotsy\n";
			}
			else
			{
				int nw = 0, pos;
				cin >> pos;
				for (int j = 15; j >= 0; j--)
				{
					char f;
					cin >> f;
					if (f == '1')
						nw |= (1 << j);
				}
				update(1,0,n-1,pos-1,solve(nw));
			}
		}
	}
}

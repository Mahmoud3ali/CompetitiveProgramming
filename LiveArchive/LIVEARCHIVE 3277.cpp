#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct MaximumMatching
{
	vector<int> m1, m2, seen;
	vector<vector<int> > g;
	int seen_id;
	MaximumMatching(int numNodesLeft, int numNodesRight)
	{
		g = vector<vector<int> >(numNodesLeft, vector<int>());
		m1 = vector<int>(numNodesLeft, -1);
		m2 = vector<int>(numNodesRight, -1);
		seen_id = 0;
		seen = vector<int>(numNodesRight, 0);
	}
	void addEdge(int leftNode, int rightNode)
	{
		assert(leftNode < int(m1.size()));
		assert(rightNode < int(m2.size()));
		g[leftNode].push_back(rightNode);
	}
	int getMaxMatching()
	{
		int ans = 0;
		for (int node = 0; node < int(m1.size()); node++)
		{
			seen_id++;
			if (dfs(node))
				ans++;
		}
		return ans;
	}
	bool dfs(int node)
	{
		for (int i = 0; i < int(g[node].size()); i++)
		{
			int child = g[node][i];
			// if the child is not matched yet, match it with me
			if (m2[child] == -1)
			{
				m2[child] = node;
				m1[node] = child;
				return true;
			}

			// if the child was seen before (some other node tried to take it), leave it
			if (seen[child] == seen_id)
				continue;
			seen[child] = seen_id;

			// if the child is already matched with some other node, try to match that other node is some other way
			int enemy = m2[child];
			// take the child for me
			m1[enemy] = -1;
			m1[node] = child;
			m2[child] = node;
			// try to match the enemy
			if (dfs(enemy))
				return true;
			// match the child with the enemy if not successful
			m1[enemy] = child;
			m1[node] = -1;
			m2[child] = enemy;
		}
		return false;
	}

};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n , m , trial = 1 ;
	while(cin >> n && n)
	{
		// people , duration .
		vector<pair<int,int>>v(n) , rom;
		for(int i = 0 ; i < n ; i++) cin >> v[i].first >> v[i].second;
		cin >> m;
		// seats , duration.
		rom.resize(m+5);
		for(int i = 0 ; i < m ; i++)
		{
			int s , h , mi ;
			char dum;
			cin >> s >> h >> dum >> mi;
			int f = (h-14)*60 + mi;
			rom[i].first = s;
			rom[i].second = f;
		}
		MaximumMatching ff(n+5,m+5);
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				if(v[i].first <= rom[j].first && v[i].second <= rom[j].second)
				{
					ff.addEdge(i,j);
				}
			}
		}
		ff.getMaxMatching();
		int tents = 0 , people = 0;
		vector< pair< pair<int,int> , int > > tmp;
		priority_queue< pair<int,int> > q;
		for(int i = 0 ; i < n ; i++)
		{
			if(ff.m1[i] != -1) tmp.push_back({{rom[ff.m1[i]].second,rom[ff.m1[i]].first},-1});
			q.push(v[i]);
		}
		sort(tmp.begin(),tmp.end());
		while(q.size())
		{
			pair<int,int> tp = q.top();
			q.pop();
			bool taken = 0 ;
			for(int i = 0 ; i < tmp.size() ; i++)
			{
				if(tmp[i].second != -1) continue;
				if(tp.first <= tmp[i].first.second && tp.second <= tmp[i].first.first)
				{
					taken = 1;
					tmp[i].second = 1;
					break;
				}
			}
			if(!taken)
			{
				tents++;
				people+=tp.first;
			}
		}
		cout << "Trial " << trial++ << ": " << tents << " " << people << "\n\n";
	}
}

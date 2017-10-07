//////////////////////////////////////////////// GRAPH ////////////////////////////////////////////////
// Dinic's Max Flow
// Complexity: O(V^2 * E)
const int INF = 2000000000;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) { }
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) { }

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *)NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while(head < tail)
        {
            int x = Q[head++];
            for(int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]) return 0;

        long long totflow = 0;
        for(int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if(!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if(amt == 0) continue;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};


// Edmond Karp's Max Flow
// Complexity: O(V * E^2)
const int INF = 1 << 30;
struct graph
{
    int n;
    struct edge
    {
        int src, dst;
        int capacity, residue;
        size_t rev;
    };
    edge &rev(edge e)
    {
        return adj[e.dst][e.rev];
    };

    vector<vector<edge>> adj;
    graph(int n) : n(n), adj(n) { }
    void add_edge(int src, int dst, int capacity)
    {
        adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
        adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
    }
    int max_flow(int s, int t)
    {
        for (int u = 0; u < n; ++u)
            for (auto &e: adj[u]) e.residue = e.capacity;
        int total = 0;
        while (1)
        {
            vector<int> prev(n, -1);
            prev[s] = -2;
            queue<int> que;
            que.push(s);
            while (!que.empty() && prev[t] == -1)
            {
                int u = que.front();
                que.pop();
                for (edge &e: adj[u])
                {
                    if (prev[e.dst] == -1 && e.residue > 0)
                    {
                        prev[e.dst] = e.rev;
                        que.push(e.dst);
                    }
                }
            }
            if (prev[t] == -1) break;
            int inc = INF;
            for (int u = t; u != s; u = adj[u][prev[u]].dst)
                inc = min(inc, rev(adj[u][prev[u]]).residue);
            for (int u = t; u != s; u = adj[u][prev[u]].dst)
            {
                adj[u][prev[u]].residue += inc;
                rev(adj[u][prev[u]]).residue -= inc;
            }
            total += inc;
        } // { u : visited[u] == true } is s-side
        return total;
    }
};

int main()
{
    for (int n, m; scanf("%d %d", &n, &m) == 2; )
    {
        graph g(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g.add_edge(u, v, w);
        }
        printf("%d\n", g.max_flow(0, n-1));
    }
}

// Ford Fulkerson's Max Flow
// Complexity: O(E * Max Flow)
const int INF = 1 << 30;
struct graph
{
    typedef long long flow_type;
    struct edge
    {
        int src, dst;
        flow_type capacity, flow;
        size_t rev;
    };
    int n;
    vector<vector<edge>> adj;
    graph(int n) : n(n), adj(n) { }
    void add_edge(int src, int dst, flow_type capacity)
    {
        adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
        adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
    }
    int max_flow(int s, int t)
    {
        vector<bool> visited(n);
        function<flow_type(int,flow_type)> augment = [&](int u, flow_type cur)
        {
            if (u == t) return cur;
            visited[u] = true;
            for (auto &e: adj[u])
            {
                if (!visited[e.dst] && e.capacity > e.flow)
                {
                    flow_type f = augment(e.dst, min(e.capacity - e.flow, cur));
                    if (f > 0)
                    {
                        e.flow += f;
                        adj[e.dst][e.rev].flow -= f;
                        return f;
                    }
                }
            }
            return flow_type(0);
        };
        for (int u = 0; u < n; ++u)
            for (auto &e: adj[u]) e.flow = 0;

        flow_type flow = 0;
        while (1)
        {
            fill(all(visited), false);
            flow_type f = augment(s, INF);
            if (f == 0) break;
            flow += f;
        }
        return flow;
    }
};

int main()
{
    for (int n, m; scanf("%d %d", &n, &m) == 2; )
    {
        graph g(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g.add_edge(u, v, w);
        }
        printf("%d\n", g.max_flow(0, n-1));
    }
}

// Hopcroft-carp bipartite matching
// Complexity: O(E * sqrt(V))

struct graph
{
    int L, R;
    vector<vector<int>> adj;
    graph(int L, int R) : L(L), R(R), adj(L+R) { }
    void add_edge(int u, int v)
    {
        adj[u].push_back(v+L);
        adj[v+L].push_back(u);
    }
    int maximum_matching()
    {
        vector<int> level(L), mate(L+R, -1);

        function<bool(void)> levelize = [&]()   // BFS
        {
            queue<int> Q;
            for (int u = 0; u < L; ++u)
            {
                level[u] = -1;
                if (mate[u] < 0)
                {
                    level[u] = 0;
                    Q.push(u);
                }
            }
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (int w: adj[u])
                {
                    int v = mate[w];
                    if (v < 0) return true;
                    if (level[v] < 0)
                    {
                        level[v] = level[u] + 1;
                        Q.push(v);
                    }
                }
            }
            return false;
        };
        function<bool(int)> augment = [&](int u)   // DFS
        {
            for (int w: adj[u])
            {
                int v = mate[w];
                if (v < 0 || (level[v] > level[u] && augment(v)))
                {
                    mate[u] = w;
                    mate[w] = u;
                    return true;
                }
            }
            return false;
        };
        int match = 0;
        while (levelize())
            for (int u = 0; u < L; ++u)
                if (mate[u] < 0 && augment(u))
                    ++match;
        return match;
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    graph flow(n+1, m+1);

    while(k--)
    {
        int a, b;
        cin >> a >> b;
        flow.add_edge(a, b);
    }

    cout << flow.maximum_matching() << endl;

    return 0;
}

// Maximum Bipartite Matching
// Complexity: O(N * M), N = nodes on left side, M = nodes on right side

/*
0 based node indices
left nodes are numbered from 0
right nodes are numbered from 0 as well
*/
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
            if (dfs(node)) ans++;
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
            if (seen[child] == seen_id) continue;
            seen[child] = seen_id;

            // if the child is already matched with some other node, try to match that other node is some other way
            int enemy = m2[child];
            // take the child for me
            m1[enemy] = -1;
            m1[node] = child;
            m2[child] = node;
            // try to match the enemy
            if (dfs(enemy)) return true;
            // match the child with the enemy if not successful
            m1[enemy] = child;
            m1[node] = -1;
            m2[child] = enemy;
        }
        return  false;
    }

};


// Minimum Cost Max Flow SPFA implementation
// Complexity: N/A

const int mxN = 110;
const int inf = 1000000010;
struct Edge
{
    int to, cost, cap, flow, backEdge;
};
struct MCMF
{
    int s, t, n;
    vector<Edge> g[mxN];
    MCMF(int _s, int _t, int _n)
    {
        s = _s, t = _t, n = _n;
    }
    void addEdge(int u, int v, int cost, int cap)
    {
        Edge e1 = { v, cost, cap, 0, g[v].size() };
        Edge e2 = { u, -cost, 0, 0, g[u].size() };
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
    pair<int, int> minCostMaxFlow()
    {
        int flow = 0, cost = 0;
        vector<int> state(n), from(n), from_edge(n), d(n);
        deque<int> q;
        while (true)
        {
            for (int i = 0; i < n; i++)
                state[i] = 2, d[i] = inf, from[i] = -1;
            state[s] = 1;
            q.clear();
            q.push_back(s);
            d[s] = 0;
            while (!q.empty())
            {
                int v = q.front();
                q.pop_front();
                state[v] = 0;
                for (int i = 0; i < (int) g[v].size(); i++)
                {
                    Edge e = g[v][i];
                    if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
                        continue;
                    int to = e.to;
                    d[to] = d[v] + e.cost;
                    from[to] = v;
                    from_edge[to] = i;
                    if (state[to] == 1) continue;
                    if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
                        q.push_front(to);
                    else q.push_back(to);
                    state[to] = 1;
                }
            }
            if (d[t] == inf) break;
            int it = t, addflow = inf;
            while (it != s)
            {
                addflow = min(addflow,
                              g[from[it]][from_edge[it]].cap
                              - g[from[it]][from_edge[it]].flow);
                it = from[it];
            }
            it = t;
            while (it != s)
            {
                g[from[it]][from_edge[it]].flow += addflow;
                g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
                cost += g[from[it]][from_edge[it]].cost * addflow;
                it = from[it];
            }
            flow += addflow;
        }
        return {cost,flow};
    }
};

// Tarjan's SCC
// Complexity: O(V + E)

int n, m, _time, SCC_num;
vvi node;
vb visited;
vi in_time, num, st, component;

void SCC(int v)
{
    in_time[v] = num[v] = ++_time;
    visited[v] = true;
    st.push_back(v);
    for(auto i : node[v])
    {
        if (num[i] == -1) SCC(i);
        if (visited[i]) in_time[v] = min(in_time[v], in_time[i]);
    }
    if (in_time[v] == num[v])
    {
        while(true)
        {
            int hoba = st.back();
            st.pop_back();
            component[hoba] = SCC_num;
            visited[hoba] = false;
            if (hoba == v) break;
        }
        SCC_num++;
    }
}

void init()
{
    SCC_num = 0;
    node = vvi(n+1);
    visited = vb(n+1);
    in_time = vi(n+1);
    _time = 0;
    num = vi(n+1, -1);
    component = vi(n+1);
    st.clear();
}

int main()
{
    cin >> n >> m;
    init();
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
    }
    erep(i, 1, n)
    {
        if (num[i] == -1) SCC(i);
    }
    return 0;
}

//////////////////////////////////////////////// DS ////////////////////////////////////////////////

// Implicit Segment tree
struct Node
{
    Node* l, *r;
    int sum;

    Node()
    {
        l = NULL;
        r = NULL;
        sum = 0;
    }
};

void update(Node* root, int st, int en, int idx, int val)
{
    if (st > en || st > idx || en < idx) return;

    if (st == en)
    {
        root->sum += val;
        return;
    }

    int mid = (st+en)/2;
    if (root->l == NULL) root->l = new Node();
    if (root->r == NULL) root->r = new Node();
    update(root->l, st, mid, idx, val);
    update(root->r, mid+1, en, idx, val);

    root->sum = root->l->sum + root->r->sum;
}

ll query(Node* root, int st, int en, int shemal, int yemeen)
{
    if (st > en || st > yemeen || en < shemal || root == NULL) return 0;

    if (shemal <= st && en <= yemeen) return root->sum;

    int mid = (st+en)/2;

    return query(root->l, st, mid, shemal, yemeen) + query(root->r, mid+1, en, shemal, yemeen);
}

vector< Node* > arr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    arr = vector< Node* > (t);
    rep(i, 0, t) arr[i] = new Node();

    update(arr[compress[val[i]]], 0, 1e9, time[i], -1);
    cout << query(arr[compress[val[i]]], 0, 1e9, 0, time[i]) << endl;

    return 0;
}

// Persistent segment tree
// Maximum logN nodes created in a new copy

struct Node
{
    int cnt, left, right;
};

int n, m, mx = 1, cnt;
const int lg = 19, last = 123455;
mapii mp, rev;
vi vec;
vvi node;

Node tree[123456 * lg];
int parent[123456][lg], depth[123456], root[123456];

int insert(int prev, int st, int en, int idx)
{
    int curr = ++cnt; // number of node
    tree[curr] = tree[prev];

    tree[curr].cnt++;

    int mid = (st+en)/2;

    if (st < en)
    {
        if (idx <= mid)
            tree[curr].left = insert(tree[prev].left, st, mid, idx);
        else
            tree[curr].right = insert(tree[prev].right, mid + 1, en, idx);
    }

    return curr;
}

int query(int u, int v, int lca, int plca, int st, int en, int k)
{
    if (st == en)
        return st;

    int cnt = tree[ tree[u].left ].cnt;
    cnt += tree[ tree[v].left ].cnt;
    cnt -= tree[ tree[lca].left ].cnt;
    cnt -= tree[ tree[plca].left ].cnt;

    int mid = (st+en)/2;

    if (k <= cnt)
        return query(tree[u].left, tree[v].left, tree[lca].left, tree[plca].left, st, mid, k);
    else
        return query(tree[u].right, tree[v].right, tree[lca].right, tree[plca].right, mid + 1, en, k - cnt);
}

void dfs(int v, int p)
{
    parent[v][0] = p;
    depth[v] = depth[p] + 1;

    int idx = mp[vec[v]];

    root[v] = insert(root[p], 1, n, idx);

    for(auto i : node[v])
        if (i != p)
            dfs(i, v);
}

int LCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];

    rep(i, 0, lg)
    if (diff & (1<<i))
        u = parent[u][i];

    if (u != v)
    {
        for(int i = lg-1; i>=0; i--)
        {
            if (parent[u][i] != parent[v][i])
            {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }

    return u;
}

int main()
{
    dfs(1, 0);

    rep(i, 1, lg)
    {
        erep(j, 1, n)
        {
            parent[j][i] = parent[parent[j][i-1]][i - 1];
        }
    }
}

// Merge sort segment tree
// Complexity: NlogN build, log^2(n) per query, space complexity NlogN
/*
    we'll keep a merge sort segment tree carrying the indices of the array (after sorting it)
    when getting a query, we'll traverse the tree to the left/right child
    according to which child contains the target index
    the returned index is the index of our solution in the main array
*/
const int MAX = 100001;

vii arr;
vector<int> tree[4*MAX];

void build(int node, int st, int en)
{
    if (st > en) return;

    if (st == en)
    {
        tree[node].push_back(arr[st].second);
        return;
    }

    int mid = (st+en)/2;

    build(2*node, st, mid);
    build(2*node + 1, mid + 1, en);

    merge(all(tree[2*node]), all(tree[2*node + 1]), back_inserter(tree[node]));
}

int query(int node, int st, int en, int shemal, int yemeen, int idx)
{
    if (st == en) return tree[node][0];

    int mid = (st+en)/2;

    auto it = upper_bound(all(tree[2*node]), yemeen);
    int total = it - lower_bound(all(tree[2*node]), shemal);

    if (total >= idx) return query(2*node, st, mid, shemal, yemeen, idx);
    return query(2*node + 1, mid + 1, en, shemal, yemeen, idx - total);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    arr = vii(n);
    vi yay;
    rep(i, 0, n)
    {
        cin >> arr[i].first, arr[i].second = i;
        yay.push_back(arr[i].first);
    }
    sort(all(arr));
    build(1, 0, n-1);

    while(q--)
    {
        int l, r, idx;
        cin >> l >> r >> idx;
        l--, r--;

        cout << yay[query(1, 0, n-1, l, r, idx)] << endl;
    }
    return 0;
}

// Multidimensional Trie
// update/query LogN (1D)
// Dimension >= 2: ALWAYS REMEMBER TO USE INCLUSION-EXCLUSION TO GET THE CORRECT VALUES

/*
    this is a 3D BIT problem, the trick is to find the proper sets to use inclusion/exclusion princple
*/
const int MX = 130;

int bit[MX][MX][MX];

void update(int x, int y, int z, int val)
{
    while(x < MX)
    {
        int y1 = y;
        while(y1 < MX)
        {
            int z1 = z;
            while(z1 < MX)
            {
                bit[x][y1][z1] += val;
                z1 += (z1 & -z1);
            }
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int query(int x, int y, int z)
{
    int ret = 0;
    while(x > 0)
    {
        int y1 = y;
        while(y1 > 0)
        {
            int z1 = z;
            while(z1 > 0)
            {
                ret += bit[x][y1][z1];
                z1 -= (z1 & -z1);
            }
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;

    int op;

    while(cin >> op && op != 3)
    {
        if (op == 1)
        {
            int x, y, z, k;
            cin >> x >> y >> z >> k;
            update(x+1, y+1, z+1, k);
        }
        else
        {
            int x, y, z, xx, yy, zz;
            cin >> x >> y >> z >> xx >> yy >> zz;

            x++, y++, z++, xx++, yy++, zz++;

            cout << query(xx, yy, zz) - query(xx, yy, z - 1) - query(xx, y-1, zz) - query(x-1, yy, zz) + query(x-1, y-1, zz)
                 + query(x-1, yy, z-1) + query(xx, y-1, z-1) - query(x-1, y-1, z-1) << endl;
        }
    }
    return 0;
}

// Sqrt decomposition
// Complexity: Sqrt(n) per query

int main()
{

int n, q;
	cin >> n >> q;

	int sq = sqrt(n); // size of block
	vector<pair<int, int> > idx(sq + 5); // start/end indexes for each block (inclusive)
	vector<deque<char> > vec(sq + 5); // container for blocks

	int st = 0;
	for (int i = 0; i < idx.size(); i++)
	{
		idx[i] = {st, st + sq - 1}; // intervals of i-th block
		st += sq;
	}

	string x;
	cin >> x;

	for (int i = 0, j = 0; i < x.size(); i++)
	{
		if (idx[j].first <= i && i <= idx[j].second) // if data in range of current block, add it
			vec[j].push_back(x[i]);
		else                                         // if not, move on to the next block and add it
		{
			j++;
			vec[j].push_back(x[i]);
		}
	}
    return 0;
}

//////////////////////////////////////////////// Math ////////////////////////////////////////////////

// Matrix operations

vvi matrixUnit(int n)
{
    vvi res(n, vi(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

vvi matrixAdd(const vvi &a, const vvi &b)
{
    int n = a.size();
    int m = a[0].size();
    vvi res(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = (a[i][j] + b[i][j]) % mod;
    return res;
}

vvi matrixMul(const vvi &a, const vvi &b)
{
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvi res(n, vi(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
                res[i][j] = (res[i][j] + (long long) a[i][p] * b[p][j]) % mod;
    return res;
}

vvi matrixPow(const vvi &a, int p)
{
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}

vvi matrixPowSum(const vvi &a, int p)
{
    int n = a.size();
    if (p == 0)
        return vvi(n, vi(n));
    if (p % 2 == 0)
        return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}

int main()
{
    vvi a(2, vi(2));
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    vvi b = matrixPow(a, 10);
}

//-------------------------------------------- Ali segment tree without lazy --------------------------------------------
void build(int node, int s, int e)
{
	if (s == e)
	{
		t[node] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(node * 2, s, mid);
	build(node * 2 + 1, mid + 1, e);
	t[node] = t[node * 2] ^ t[node * 2 + 1];
}
int query(int node, int s, int e, int l, int r)
{
	if (s > r || e < l)
		return 0;
	if (l <= s && e <= r)
		return t[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, l, r);
	left = left ^ query(node * 2 + 1, mid + 1, e, l, r);
	return left;
}
void update(int node, int s, int e, int idx, int val)
{
	if (s == e)
	{
		arr[s] = val;
		t[node] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	if (s <= idx && idx <= mid)
		update(node * 2, s, mid, idx, val);
	else
		update(node * 2 + 1, mid + 1, e, idx, val);
	t[node] = t[node * 2] ^ t[node * 2 + 1];
}
// -------------------------------------------------- Ali segment tree with lazy ------------------------------------
void propagate(int node, int l, int r)
{
	t[node] += lazy[node];
	if (l != r)
	{
		lazy[node << 1] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
void inc(int node, int s, int e, int l, int r, ll v)
{
	propagate(node, s, e);
	if (l > e || r < s)
		return;

	if (l <= s && e <= r)
	{
		lazy[node] += v;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) >> 1;
	inc(node * 2, s, mid, l, r, v);
	inc(node * 2 + 1, mid + 1, e, l, r, v);
	t[node] = min(t[node * 2], t[node * 2 + 1]);
}
ll rmq(int node, int s, int e, int l, int r)
{
	propagate(node, s, e);
	if (l > e || r < s)
		return 1e18;

	if (s >= l && e <= r)
		return t[node];
	int mid = (s + e) >> 1;
	return min(rmq(node * 2, s, mid, l, r), rmq(node * 2 + 1, mid + 1, e, l, r));
}
// --------------------------------------- CCW for checking if two lines XY , AB intersect or not ----------------------
ll cp(pair<ll, ll> v1, pair<ll, ll> v2)
{
	return v1.first * v2.second - v1.second * v2.first;
}
ll dp(pair<ll, ll> v1, pair<ll, ll> v2)
{
	return v1.first * v2.first + v1.second * v2.second;
}
ll norm(pair<ll, ll> v1)
{
	return dp(v1, v1);
}
ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> x)
{
	pair<ll, ll> v1 =
	{ b.first - a.first, b.second - a.second };
	pair<ll, ll> v2 =
	{ x.first - a.first, x.second - a.second };
	if (cp(v1, v2) > 0)
		return 1;
	if (cp(v1, v2) < 0)
		return -1;
	if (v1.first * v2.first < 0 || v1.second * v2.second < 0)
		return -1;
	if (norm(v1) < norm(v2))
		return 1;
	return 0;
}
bool intersect(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> a, pair<ll, ll> b)
{
	if (x == y && a == b)
		return (x == a);
	if (x == y)
		return (ccw(a, b, x) == 0);
	return (ccw(x, y, a) * ccw(x, y, b) <= 0 && ccw(a, b, x) * ccw(a, b, y) <= 0);
}
// ----------------------------------------------- get vector from two points -----------------------------------------
pair<int, int> get_vec(pair<int, int> a, pair<int, int> b)
{
	int x = b.first - a.first, y = b.second - a.second;
	int t = __gcd(x, y);
	y /= t;
	x /= t;
	return
	{	x,y};
}
// ------------------------------------------------- fast power with mod --------------------------------------------
ll mod = 1000000007;
long long fast_power(long long base, long long power)
{
	if (power == 1)
		return base % mod;
	else if (power & 1)
		return (base * fast_power((base * base) % mod, power / 2)) % mod;
	else
		return (fast_power((base * base) % mod, power / 2)) % mod;
}
// -------------------------------------------------------- LCA --------------------------------------------------------
int cost[(int) 1e5 + 5];
int par[(int) 1e5 + 5];
int level[(int) 1e5 + 5];
int dp[20][(int) 1e5 + 5];
vector<vector<int> > v;
int LCA(int x, int y)
{
	if (x == y)
		return x;
	if (level[x] > level[y])
		swap(x, y);
	int diff = level[y] - level[x];
	for (int i = 19; i >= 0; i--)
	{
		if (diff & (1 << i))
			y = dp[i][y];
	}
	if (x == y)
		return x;
	for (int i = 19; i >= 0; i--)
	{
		if (dp[i][x] != dp[i][y])
		{
			y = dp[i][y];
			x = dp[i][x];
		}
	}
	return dp[0][x];
}
int main()
{
	for (int i = 1; i <= n; i++)
		dp[0][i] = par[i];
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
}
// ---------------------------------------------- NcR with mod inverse where mod is prime -----------------------------
ll ncr(int a, int b)
{
	if (a < 0 || b < 0)
		return 0;
	ll x = f[a];
	// f[a] is factorial[a]%mod
	x %= mod;
	ll y = f[b] * f[a - b];
	y %= mod;
	x = x * fast_power(y, mod - 2);
	x %= mod;
	return x;
}
// ----------------------------------------------- double compare -----------------------------------------------
int dcmp(double a, double b)
{
	return fabs(a - b) <= (1e-9) ? 0 : a < b ? -1 : 1;
}
// ------------------------------------------ very fast cout cin ---------------------------------------
template<class T>
inline void cinn(T &ret)
{
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	ret = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')
		ret = ret * 10 + (c - '0');
}

inline void coutt(int a)
{
	if (a < 0)
	{
		putchar('-');
		a = -a;
	}
	if (a >= 10)
	{
		coutt(a / 10);
	}
	putchar(a % 10 + '0');
}
// --------------------------------------- ternary search on doubles -------------------------------------
double ternary_search()
{
	double l = 0, r = 1e9, EPS = 1e-9;
	while (r - l > EPS)
	{
		double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(a, b, c, m2) - f(a, b, c, m1) >= EPS)
			l = m1;
		else
			r = m2;
	}
	return m1;
}
// ---------------------------------------- bellmanford multiple/single sources -------------------------------------------
ll dist[2001];
int main()
{
		memset(dist, 0, sizeof dist);
		// initialize with infinity except for the source if you want to start from single source
		vector< pair< int, pair<int, int> > > edge;
		bool flag = true;
		int mnn = INT_MAX;
			for(int i = 1; i<n; i++)
			{
				for(int j = 0; j<(int)edge.size(); j++)
				{
					int x = edge[j].first, y = edge[j].second.first, w = edge[j].second.second;
					if (dist[x] + w < dist[y]) dist[y] = dist[x] + w;
				}
			}
	}
	return 0;
}
// ---------------------------------------------- ternary search on integers-------------------------------
int ternary_search()
{
	int lo = -1, hi = n;
	while (hi - lo > 1)
	{
		int mid = (hi + lo) >> 1;
		if (f(mid) > f(mid + 1))
			hi = mid;
		else
			lo = mid;
	}
	return lo + 1;
//lo + 1 is the answer
}
// -------------------  This is the famous "Yarin sieve", for use when memory is tight --------------------------
#define MAXSIEVE 100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE / 16 + 2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd
int i, j;
memset(a, 255, sizeof(a));
a[0] = 0xFE;
for (i = 1; i < MAXSQRT; i++)
if (a[i >> 3] & (1 << (i & 7)))
for (j = i + i + i + 1; j < MAXSIEVEHALF; j += i + i + 1)
a[j >> 3] &= ~(1 << (j & 7));
// --------------------------------------------------Geometry----------------------------------
double INF = 1e100;
double EPS = 1e-12;
struct PT
{
	double x, y;
	P T()
	{
	}
	PT(double x, double y) :x(x), y(y)
	{
	}
	PT(const PT &p) : x(p.x), y(p.y)
	{
	}
	PT operator +(const PT &p) const
	{
		return PT(x + p.x, y + p.y);
	}
	PT operator -(const PT &p) const
	{
		return PT(x - p.x, y - p.y);
	}
	PT operator *(double c) const
	{
		return PT(x * c, y * c);
	}
	PT operator /(double c) const
	{
		return PT(x / c, y / c);
	}
	bool operator<(const PT &p) const
	{
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
	bool operator==(const PT &p) const
	{
		return !(*this < p) && !(p < *this);
	}
};
double dot(PT p, PT q)
{
	return p.x * q.x + p.y * q.y;
}
double dist2(PT p, PT q)
{
	return dot(p - q, p - q);
}
double cross(PT p, PT q)
{
	return p.x * q.y - p.y * q.x;
}
PT norm(PT x, double l)
{
	return x * sqrt(l * l / dot(x, x));
}
istream &operator>>(istream &is, PT &p)
{
	return is >> p.x >> p.y;
}
ostream &operator<<(ostream &os, const PT &p)
{
	return os << "(" << p.x << "," << p.y << ")";
}
/*around the origin*/
PT RotateCCW90(PT p)
{
	return PT(-p.y, p.x);
}
PT RotateCW90(PT p)
{
	return PT(p.y, -p.x);
}
PT RotateCCW(PT p, double t)
{
	return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
// project point c onto line through a and b (assuming a != b)
PT ProjectPointLine(PT a, PT b, PT c)
{
	return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}
// project point c onto line segment through a and b (assuming a != b)
PT ProjectPointSegment(PT a, PT b, PT c)
{
	double r = dot(c-a, b-a)/dot(b-a,b-a);
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b-a)*r;
}
PT reflectAroundLine(PT p, PT a, PT b)
{
	return ProjectPointLine(p, a, b) * 2.0 - p;
}
// DISTANCES:
// DISTANCE point to segment or line = distance between the point and its projection
// DISTNACE line to parallel line = distance between on end point to the other line
// DISTANCE line to parallel segment = distance between on end point of the line to the segment
// DISTANCE segment to segment = minimum distance of the four end points to the other segment
// DISTANCE point to polygon = minimum distance to any edge if it's outside
// DISTNACE Line\segment to polygon = minimum distance to any edge
// DISTANCE point to circle = distance point to center - R
// DISTANCE line to circle = distance between center to the line - R
// DISTANCE polygon to circle = minimum distance between circle and each edge (if the center isn't inside)
// DISTANCE polygon to polygon = minimum distance between any pair of edges
// DISTANCE circle to circle = distance between centers - sum of the two Rs
// CIRCLES states: (D = distance between circles, r first radius, R second radius)
// - Outside : D > r + R
// - Touch : D == r + R
// - Inside : D < R - r
// - Touch inside : D == R - r
//
// INTERSECTIONS:
// 1 = RIGTH, 0 = collinear, -1 = LEFT
int isLeft(PT o,PT a,PT b)
{
	double isLeft = cross(a - o, b - o);
	return isLeft < -EPS ? -1 : (isLeft > EPS ? 1 : 0 );
}
bool LinesParallel(PT a, PT b, PT c, PT d)
{
	return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d)
{
	return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS
			&& fabs(cross(c - d, c - a)) < EPS;
}
// determine if a to b intersects with c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
	if (LinesCollinear(a, b, c, d))
	{
		if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS
				|| dist2(b, d) < EPS)
			return true;
		if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0
				&& dot(c - b, d - b) > 0)
			return false;
		return true;
	}
	if (cross(d - a, b - a) * cross(c - a, b - a) > 0)
		return false;
	if (cross(a - c, d - c) * cross(b - c, d - c) > 0)
		return false;
	return true;
}
// ST Line ab intersect ST Line cd assuming unique intersection exists
// for line segments, check if segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
	b = b - a;
	d = c - d;
	c = c - a;
	assert(dot(b, b) > EPS && dot(d, d) > EPS);
	return a + b * cross(c, d) / cross(b, d);
}
// st line and r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
	vector<PT> ret;
	b = b - a, a = a - c;
	double A = dot(b, b), B = dot(a, b), C = dot(a, a) - r * r, D = B * B
			- A * C;
	if (D < -EPS)
		return ret;
	ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
	if (D > EPS)
		ret.push_back(c + a + b * (-B - sqrt(D)) / A);
	return ret;
}
// compute intersection of circle (a,r) and (b,R)
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R)
{
	vector<PT> ret;
	double d = sqrt(dist2(a, b));
	if (d > r+R || d+min(r, R) < max(r, R)) return ret;
	double x = (d*d-R*R+r*r)/(2*d);
	double y = sqrt(r*r-x*x);
	PT v = (b-a)/d;
	ret.push_back(a+v*x + RotateCCW90(v)*y);
	if (y > 0) ret.push_back(a+v*x - RotateCCW90(v)*y);
	return ret;
}
//return the common area of two circle
double cirAreaCut(double a, double r)
{
	double s1 = a * r * r / 2;
	double s2 = sin(a) * r * r / 2;
	return s1 - s2;
}
double commonCircleArea(PT c1, double r, PT c2, double R)
{
	if (r < R)
		swap(c1, c2), swap(r, R);
	double d = sqrt(dist2(c1, c2));
	if (d + R <= r + EPS)
		return R * R * acos(-1.0);
	if (d >= r + R - EPS)
		return 0.0;
	double a1 = acos((d * d + r * r - R * R) / 2 / d / r);
	double a2 = acos((d * d + R * R - r * r) / 2 / d / R);
	return cirAreaCut(a1 * 2, r) + cirAreaCut(a2 * 2, R);
}
pair<PT, double> getCircumcircle(PT a, PT b, PT c)
{
	double d = 2.0
			* (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
	assert(fabs(d) > EPS);
	double x = (dot(a, a) * (b.y - c.y) + dot(b, b) * (c.y - a.y)
			+ dot(c, c) * (a.y - b.y)) / d;
	double y = (dot(a, a) * (c.x - b.x) + dot(b, b) * (a.x - c.x)
			+ dot(c, c) * (b.x - a.x)) / d;
	PT p(x, y);
	return
	{	p, sqrt(dist2(p,a))};
}
pair<PT, double> getEnclosingCircle(vector<PT> & p)
{
	random_shuffle(p.begin(), p.end());
	PT c(0, 0);
	double r = 0;
	int n = p.size();
	for (int i = 1; i < n; i++)
		if (dist2(p[i], c) > r * r + EPS)
		{
			c = p[i], r = 0;
			for (int j = 0; j < i; j++)
				if (dist2(p[j], c) > r * r + EPS)
				{
					c = (p[i] + p[j]) / 2, r = sqrt(dist2(p[i], p[j])) / 2;
					for (int k = 0; k < j; k++)
						if (dist2(p[k], c) > r * r + EPS)
						{
							auto cir = getCircumcircle(p[i], p[j], p[k]);
							c = cir.first;
							r = cir.second;
						}
				}
		}
	return {c,r};
}
vector<PT> pointCircleTangent(const PT & x, double r, const PT & a)
{
	double dist = dist2(x, a);
	vector<PT> res;
	if (fabs(dist) < EPS)
		res.push_back(a);
	else if (dist > r * 1LL * r)
	{
		PT v = a - x;
		v = v * (r * 1.0 / sqrt(dist));
		double theta = acos(sqrt(dist) / r);
		res.push_back(x + RotateCCW(v, theta));
		res.push_back(x + RotateCCW(v, -theta));
	}
	return res;
}
vector<PT> circleCircleTangent(PT & a, int r1, PT & b, int r2)
{
	vector<PT> res;
	if (r1 == r2)
	{
		PT v = (b - a) / sqrt(dist2(a, b));
		PT p1 = PT(-v.y, v.x) * r1;
		PT p2 = PT(v.y, -v.x) * r1;
		res.push_back(p1 + a);
		res.push_back(p2 + a);
		res.push_back(p1 + b);
		res.push_back(p2 + b);
		return res;
	}
	if (r1 < r2)
	{
		swap(a, b);
		swap(r1, r2);
	}
	double r = r1 - r2;
	res = pointCircleTangent(a, r, b);
	PT t1 = res[0], t2 = res[1];
	PT p1 = (t1 - a) / sqrt(dist2(a, t1));
	PT p2 = (t2 - a) / sqrt(dist2(a, t1));
	res.push_back(p1 * r1 + a);
	res.push_back(p2 * r1 + a);
	res.push_back(p1 * r2 + b);
	res.push_back(p2 * r2 + b);
	return res;
}
// To line by segment and validate the intersection lie inside the segment
// INTERSECTION LINE->POLYGON: intersection beteween the line and any edge
// intersect every edge with the line or cirlce
//
// POLYGON FUNCTIONS
// possibly non-convex polygon
// strict in -> 1 .. strict out -> 0 ... else -> random
bool PointInPolygon(const vector<PT> &p, PT q)
{
	int cnt = 0;
	for (int i = 0; i < (int) p.size(); i++)
	{
		PT p1 = p[i], p2 = p[(i + 1) % p.size()];
		if (fabs(p1.y - p2.y) < EPS)
			continue;
		if (p1.y > p2.y)
			swap(p1, p2);
		if (p1.y <= q.y && q.y < p2.y)
		{
			double dx = p2.x - p1.x, dy = p2.y - p1.y;
			if (dy * p1.x + dx * (q.y - p1.y) >= q.x * dy)
				cnt++;
		}
	}
	return cnt % 2 == 1;
}
bool PointOnPolygon(const vector<PT> & p, PT q)
{
	for (int i = 0; i < (int) p.size(); i++)
		if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
			return true;
	return false;
}
// possibly non convex polygon, PT sorted CW or CCW
double ComputeSignedArea(const vector<PT> &p)
{
	double area = 0;
	if (p.size() < 3)
	{
		return 0;
	}
	area += p[0].x * (p[1].y - p.back().y);
	for (int i = 1; i < (int) p.size(); i++)
		area += p[i].x * (p[i + 1].y - p[i - 1].y);
	return area / 2.0;
}
double ComputeArea(const vector<PT> &p)
{
	return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT> & p)
{
	PT c(0, 0);
	double scale = 6.0 * ComputeSignedArea(p);
	for (int i = 0; i < (int) p.size(); i++)
	{
		int j = (i + 1) % p.size();
		c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
	}
	return c / scale;
}
bool PolygonIsSimple(const vector<PT> & p)
{
	for (int i = 0; i < (int) p.size(); i++)
	{
		for (int k = i + 1; k < (int) p.size(); k++)
		{
			int j = (i + 1) % p.size();
			int l = (k + 1) % p.size();
			if (i == l || j == k)
				continue;
			if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
				return false;
		}
	}
	return true;
}
bool PolygonIsConvex(const vector<PT> & P)
{
	int n = (int) P.size();
	if (n <= 2)
		return false;
	int start = isLeft(P[0], P[1], P[2]);
	for (int i = 1; i < n; i++)
		if (isLeft(P[i], P[(i + 1) % n], P[(i + 2) % n]) * start < 0)
			return false;
	return true;
}
vector<PT> convexHull(vector<PT> & poly)
{
	sort(poly.begin(), poly.end());
	auto it = unique(poly.begin(), poly.end());
	poly.erase(it, poly.end());
	if (poly.size() <= 3)
		return poly;
	vector<PT> res;
	for (int i = 0; i < (int) poly.size(); i++)
	{
		while (res.size() > 1
				&& cross(res.back() - res[res.size() - 2],
						poly[i] - res[res.size() - 2]) < 0)
			res.pop_back();
		res.push_back(poly[i]);
	}
	int t = res.size();
	for (int i = (int) poly.size() - 1; i >= 0; i--)
	{
		while ((int) res.size() > t
				&& cross(res.back() - res[res.size() - 2],
						poly[i] - res[res.size() - 2]) < 0)
			res.pop_back();
		res.push_back(poly[i]);
	}
	res.pop_back();
	poly = res;
	return res;
}
vector<PT> polygon_cut(const vector<PT> & v, const PT & a, const PT & b)
{
	vector<PT> res;
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		int j = (i + 1) % n;
		bool in1 = isLeft(a, b, v[i]) > 0;
		bool in2 = isLeft(a, b, v[j]) > 0;
		if (in1)
			res.push_back(v[i]);
		if (in1 ^ in2)
		{
			PT r = ComputeLineIntersection(a, b, v[i], v[j]);
			res.push_back(r);
		}
	}
	return res;
}
vector<PT> areaPolygonIntersection(const vector<PT> & a, const vector<PT> &b)
{
	int n = a.size();
	int m = b.size();
	vector<PT> res;
	for (int i = 0; i < n; i++)
		if (PointInPolygon(b, a[i]))
			res.push_back(a[i]);
	for (int i = 0; i < m; i++)
		if (PointInPolygon(a, b[i]))
			res.push_back(b[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (SegmentsIntersect(a[i], a[(i + 1) % n], b[j], b[(j + 1) % m]))
				res.push_back(
						ComputeLineIntersection(a[i], a[(i + 1) % n], b[j],
								b[(j + 1) % m]));
	return convexHull(res);
}
// CIRCLE CONSTUCTION
// given 3 points
PT ComputeCircleCenter(PT a, PT b, PT c)
{
	b = (a + b) / 2;
	c = (a + c) / 2;
	return ComputeLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(ac));
}
//
// RULE:
// SINE RULE: A/sin(a) = B/sin(b) = c/sin(c)
// COSINE RULE: C^2=A^2+B^2-2AB*cos(c)
// TANGENT RULE: (A-B)/(A+B) = tan(1/2(a-b)) / tan(1/2(a+b))
// COTAN RULE: A/cot(a/2) = B/cot(b/2) = C/cot(c/2)
// INDENTICAL CASES: SSS, SAS, AAS
// SIMILIAR CASE: AAA
// Mollweide's formula: (A+B)/C = cos((a-b)/2)/sin(c/2), (A-B)/C = sin((a-b)/2)/cos(c/2)
// AREA of triangle = (B * H)/2, SQRT(S*(S-A)*(S-B)*(S-C)), S = 1/2 * PERIMETER
// AREA of circle = R^2 * PI, PERIMETER = 2 * PI * R, AREA of sector = (r^2 * theta)/2
// AREA of trapzoid = (B1 + B2)/2 * H
// Manhattan -> KING: (x,y) -> (x + y,x - y)
// KING -> Manhattan: (x,y) -> ((x+y)/2,(x-y)/2)
//
// EXTEREME POINT:
long long mxDot(vector<PT> & poly,PT & p)
{
	int N = poly.size();
	if(N <= 10)
	{
		long long res = LLONG_MIN;
		for(int i = 0;i < N;i++) res = fmax(res,dot(p,poly[i]));
		return res;}
	if(dot(p,poly[0]-poly[1]) > 0 && dot(p,poly[0]-poly[N-1]) > 0)
	return dot(p,poly[0]);
	poly.push_back(poly[0]);
	int lo = 0,hi = N;
	long long res = -1;
	while(true)
	{
		int md = (lo + hi)>>1;
		if(dot(p,poly[md]-poly[md+1]) > 0 && dot(p,poly[md]-poly[md-1]) > 0)
		{
			res = dot(p,poly[md]);
			break;
		}
		if(dot(p,poly[lo+1]-poly[lo]) > 0)
		{
			if(dot(p,poly[md+1]-poly[md]) <= 0) hi = md;
			else
			{
				if(dot(p,poly[lo]-poly[md]) > 0) hi = md;
				else lo = md;
			}
		}
		else
		{
			if(dot(p,poly[md+1]-poly[md]) > 0) lo = md;
			else
			{
				if(dot(p,poly[lo]-poly[md]) <= 0) hi = md;
				else lo = md;
			}
		}
	}
	poly.pop_back();
	return res;
}
// ROTATING CALIPERS: assume p is set of points
double rotatingCalipers(vector<PT> p)
{
	if (p.size() <= 1)
		return 0;
	if (p.size() == 2)
		return sqrt(dist2(p[0], p[1]));
	sort(p.begin(), p.end());
	vector<PT> U, L;
	for (int i = 0; i < (int) p.size(); i++)
	{
		while (L.size() > 1
				&& cross(L.back() - L[L.size() - 2], p[i] - L[L.size() - 2]) < 0)
			L.pop_back();
		L.push_back(p[i]);
	}
	for (int i = (int) p.size() - 1; i >= 0; i--)
	{
		while (U.size() > 1
				&& cross(U.back() - U[U.size() - 2], p[i] - U[U.size() - 2]) < 0)
			U.pop_back();
		U.push_back(p[i]);
	}
	int i = 0, j = L.size();
	double res = 0.0;
	reverse(L.begin(), L.end());
	while (i < (int) U.size() && j >= 0)
	{
		res = fmax(res, dist2(u[i], l[j])); // yield
		if (i == (int) U.size())
			j--;
		else if (j == 0)
			i++;
		else if (cross(L[j] - L[j - 1], U[i + 1] - U[i]) > 0)
			i++;
		else
			j--;
	}
	return sqrt(res);
}

// ---------------------------------------------- big integers library ---------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef long long ll;
typedef pair<ll, ll> lll;
typedef pair<ll, int> lli;
typedef pair<int, int> ii;

#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a)
{
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
}

void Print(BigInt a)
{
	Set(a);
	printf("%d", (a.size() == 0) ? 0 : a.back());
	FORD(i,a.size()-2,0)
		printf("%09d", a[i]);
	EL;
}

BigInt Integer(string s)
{
	BigInt ans;
	if (s[0] == '-')
		return ans;
	if (s.size() == 0)
	{
		ans.pb(0);
		return ans;
	}
	while (s.size() % 9 != 0)
		s = '0' + s;
	for (int i = 0; i < s.size(); i += 9)
	{
		int v = 0;
		for (int j = i; j < i + 9; j++)
			v = v * 10 + (s[j] - '0');
		ans.insert(ans.begin(), v);
	}
	Set(ans);
	return ans;
}

BigInt Integer(char c[])
{
	string s = "";
	FOR(i,0,strlen(c)-1)
		s = s + c[i];
	return Integer(s);
}

BigInt Integer(ll x)
{
	string s = "";
	while (x > 0)
		s = char(x % 10 + '0') + s, x /= 10;
	return Integer(s);
}

BigInt Integer(int x)
{
	return Integer((ll) x);
}

void operator >>(istream &in, BigInt &a)
{
	string s;
	getline(cin, s);
	a = Integer(s);
}

void operator <<(ostream &out, BigInt a)
{
	Print(a);
}

bool operator <(BigInt a, BigInt b)
{
	Set(a);
	Set(b);
	if (a.size() != b.size())
		return (a.size() < b.size());
	FORD(i,a.size()-1,0)
		if (a[i] != b[i])
			return (a[i] < b[i]);
	return false;
}

bool operator >(BigInt a, BigInt b)
{
	return (b < a);
}

bool operator ==(BigInt a, BigInt b)
{
	return (!(a < b) && !(b < a));
}

bool operator <=(BigInt a, BigInt b)
{
	return (a < b || a == b);
}

bool operator >=(BigInt a, BigInt b)
{
	return (b < a || b == a);
}

bool operator <(BigInt a, int b)
{
	return (a < Integer(b));
}

bool operator >(BigInt a, int b)
{
	return (a > Integer(b));
}

bool operator ==(BigInt a, int b)
{
	return (a == Integer(b));
}

bool operator >=(BigInt a, int b)
{
	return (a >= Integer(b));
}

bool operator <=(BigInt a, int b)
{
	return (a <= Integer(b));
}

BigInt max(BigInt a, BigInt b)
{
	if (a > b)
		return a;
	return b;
}

BigInt min(BigInt a, BigInt b)
{
	if (a < b)
		return a;
	return b;
}

BigInt operator +(BigInt a, BigInt b)
{
	Set(a);
	Set(b);
	BigInt ans;
	int carry = 0;
	FOR(i,0,max(a.size(), b.size())-1)
	{
		if (i < a.size())
			carry += a[i];
		if (i < b.size())
			carry += b[i];
		ans.pb(carry % base);
		carry /= base;
	}
	if (carry)
		ans.pb(carry);
	Set(ans);
	return ans;
}

BigInt operator +(BigInt a, int b)
{
	return a + Integer(b);
}

BigInt operator ++(BigInt & a)
{ // ++a
	a = a + 1;
	return a;
}

void operator +=(BigInt &a, BigInt b)
{
	a = a + b;
}

void operator +=(BigInt &a, int b)
{
	a = a + b;
}

BigInt operator -(BigInt a, BigInt b)
{
	Set(a);
	Set(b);
	BigInt ans;
	int carry = 0;
	FOR(i,0,a.size()-1)
	{
		carry += a[i] - (i < b.size() ? b[i] : 0);
		if (carry < 0)
			ans.pb(carry + base), carry = -1;
		else
			ans.pb(carry), carry = 0;
	}
	Set(ans);
	return ans;
}

BigInt operator -(BigInt a, int b)
{
	return a - Integer(b);
}

void operator --(BigInt &a)
{ // --a
	a = a - 1;
}

void operator -=(BigInt &a, BigInt b)
{
	a = a + b;
}

void operator -=(BigInt &a, int b)
{
	a = a - b;
}

BigInt operator *(BigInt a, BigInt b)
{
	Set(a);
	Set(b);
	BigInt ans;
	ans.assign(a.size() + b.size(), 0);
	FOR(i,0,a.size()-1)
	{
		ll carry = 0ll;
		for (int j = 0; j < b.size() || carry > 0; j++)
		{
			ll s = ans[i + j] + carry
					+ (ll) a[i] * (j < b.size() ? (ll) b[j] : 0ll);
			ans[i + j] = s % base;
			carry = s / base;
		}
	}
	Set(ans);
	return ans;
}

BigInt operator *(BigInt a, int b)
{
	return a * Integer(b);
}

void operator *=(BigInt &a, BigInt b)
{
	a = a * b;
}

void operator *=(BigInt &a, int b)
{
	a = a * b;
}

BigInt operator /(BigInt a, BigInt b)
{
	Set(a);
	Set(b);
	if (b == Integer(0))
		return Integer("-1");
	BigInt ans, cur;
	FORD(i,a.size()-1,0)
	{
		cur.insert(cur.begin(), a[i]);
		int x = 0, L = 0, R = base;
		while (L <= R)
		{
			int mid = (L + R) >> 1;
			if (b * Integer(mid) > cur)
			{
				x = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		cur = cur - Integer(x - 1) * b;
		ans.insert(ans.begin(), x - 1);
	}
	Set(ans);
	return ans;
}

BigInt operator /(BigInt a, int b)
{
	Set(a);
	BigInt ans;
	ll cur = 0ll;
	FORD(i,a.size()-1,0)
	{
		cur = (cur * (ll) base + (ll) a[i]);
		ans.insert(ans.begin(), cur / b);
		cur %= b;
	}
	Set(ans);
	return ans;
}

void operator /=(BigInt &a, BigInt b)
{
	a = a / b;
}

void operator /=(BigInt &a, int b)
{
	a = a / b;
}

BigInt operator %(BigInt a, BigInt b)
{
	Set(a);
	Set(b);
	if (b == Integer(0))
		return Integer("-1");
	BigInt ans;
	FORD(i,a.size()-1,0)
	{
		ans.insert(ans.begin(), a[i]);
		int x = 0, L = 0, R = base;
		while (L <= R)
		{
			int mid = (L + R) >> 1;
			if (b * Integer(mid) > ans)
			{
				x = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		ans = ans - Integer(x - 1) * b;
	}
	Set(ans);
	return ans;
}

int operator %(BigInt a, int b)
{
	Set(a);
	if (b == 0)
		return -1;
	int ans = 0;
	FORD(i,a.size()-1,0)
		ans = (ans * (base % b) + a[i] % b) % b;
	return ans;
}

void operator %=(BigInt &a, BigInt b)
{
	a = a % b;
}

void operator %=(BigInt &a, int b)
{
	a = a % Integer(b);
}

BigInt gcd(BigInt a, BigInt b)
{
	Set(a);
	Set(b);
	while (b > Integer(0))
	{
		BigInt r = a % b;
		a = b;
		b = r;
	}
	Set(a);
	return a;
}

BigInt lcm(BigInt a, BigInt b)
{
	return (a * b / gcd(a, b));
}

BigInt sqrt(BigInt a)
{
	BigInt x0 = a, x1 = (a + 1) / 2;
	while (x1 < x0)
	{
		x0 = x1;
		x1 = (x1 + a / x1) / 2;
	}
	return x0;
}

BigInt pow(BigInt a, BigInt b)
{
	if (b == Integer(0))
		return Integer(1);
	BigInt tmp = pow(a, b / 2);
	if (b % 2 == 0)
		return tmp * tmp;
	return tmp * tmp * a;
}

BigInt pow(BigInt a, int b)
{
	return pow(a, (Integer(b)));
}

int log(int n, BigInt a)
{ // log_n(a)
	Set(a);
	int ans = 0;
	while (a > Integer(1))
	{
		ans++;
		a /= n;
	}
	return ans;
}

int main()
{
	BigInt B;
	cin >> B;
	BigInt A = Integer("123456789");
	BigInt C = Integer(123456789ll);
	int x;
	x = 123456789;

	if (B <= A)
		cout << A - B;
	else
	{
		cout << "-";
		cout << B - A;
	}

	cout << A + B;
	Print(A + x);
	cout << A * B;
	Print(A * x);
	cout << A / B;
	Print(A / x);
	cout << A % B;
	printf("%d\n", A % x);

	C = ++A;
	++B;
	C += B + x;
	Print(A);
	Print(B);
	Print(C);

	cout << max(A, B);
	cout << min(A, B);

	cout << gcd(A, B);
	cout << lcm(A, B);

	cout << sqrt(A);
	printf("%d %d %d\n", log(2, A), log(10, B), log(5, C));

	A = Integer(16);
	x = 12;
	cout << pow(A, B);
	cout << pow(A, x);

	return 0;
}

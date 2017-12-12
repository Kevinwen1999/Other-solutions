#include <bits/stdc++.h>
#define MAXN 10010
#define ll long long
#define LOG 20
using namespace std;
int N;
int pa[20][MAXN];
vector <pair <int, int>> adj[MAXN];
ll dist[MAXN], depth[MAXN];
void process()
{
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < N; j++)
			if (pa[i-1][j]!=-1)
				pa[i][j] = pa[i-1][pa[i-1][j]];
}
int lca(int u, int v)
{
	if (depth[u]<depth[v]) swap(u,v);
	for (int i  = LOG - 1; i >=0; i--)
		if (pa[i][u]!=-1 && depth[pa[i][u]] >= depth[v])
			u = pa[i][u];
	if (u==v) return v;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (pa[i][v]!=-1&&pa[i][u]!=-1&&pa[i][u]!=pa[i][v])
			u = pa[i][u], v = pa[i][v];
	}
	return pa[0][u];
}
void dfs(int u, int p) {
	for (auto x : adj[u]) {
		int i = x.first;
		if (p == i) continue;
		pa[0][i] = u;
		depth[i] = depth[u] + 1;
		dist[i] = dist[u] + x.second;
		dfs(i, u);
	}
}
void exec() {
	cin >> N;
	for (int i = 0; i < N; i++) adj[i].clear();
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dist[0] = depth[0] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < LOG; j++)
			 pa[j][i] = -1;
	dfs(0, -1);
	process();
	while (true) {
		string in; cin >> in;
		if (in == "DIST") {
			int a, b; cin >> a >> b;
			a--, b--;
			int c = lca(a, b);
			cout << dist[a] + dist[b] - 2LL * dist[c] << "\n";
		} else if (in == "KTH") {
			int a, b, k;
			cin >> a >> b >> k; a--, b--, k--;
			int c = lca(a, b);
			int t;
			if (depth[a] - depth[c] >= k) t = a;
			else t = b, k = depth[b] - depth[c] - (k - (depth[a] - depth[c])); 
			for (int i = LOG - 1; i >= 0; i--) {
				if ((k >> i) & 1) {
					t = pa[i][t];
				}
			}
			cout << t + 1 << "\n";
		} else {
			break;
		}
	}
	cout << "\n"; 
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--)
		exec();
}


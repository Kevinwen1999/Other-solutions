#include <bits/stdc++.h>
#define MOD 1000000007
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 5010
#define MAXL 5
#define SEGN 300030

const int INF = 0x3f3f3f3f;

using namespace std;
int N, M;
vector <pii> adj[MAXN];
vector <int> arrives;
int dist[MAXN][2];
bool done[MAXN][2];
bool start[MAXN];
int main() {
    cin >> N >> M;
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    start[1] = 1;
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;
    queue <pii> q; q.emplace(1, 0);
    while (!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        done[u][d] = 0;
        for (auto i : adj[u]) {
            int v = i.first, dd = i.second;
            int nd;
            if (dist[u][d] >= dd) {
                nd = dist[u][d] + 1;
            } else {
                int ad = (d % 2 == dd % 2) ? 0 : 1;
                nd = dd + ad + 1;
            }
            if (dist[v][nd % 2] > nd) {
                dist[v][nd % 2] = nd;
                if (!done[v][nd % 2]) {
                    done[v][nd % 2] = 1;
                    q.emplace(v, nd % 2);
                }
            }
        }
    }
    int ans = min(dist[N][0], dist[N][1]);
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}

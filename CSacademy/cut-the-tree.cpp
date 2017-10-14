#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 100010
#define MAXL 5010
#define SEGN 300030
using namespace std;

int N;
vector <int> adj[MAXN];
int dist[MAXN];
int occ[MAXN];
void dfs(int cur, int pa) {
    for (int i : adj[cur]) {
        if (i == pa) continue;
        dist[i] = dist[cur] + 1;
        dfs(i, cur);
    }
}
int maxa = -INF, midx;
int ans = 0;
void calc() {
    maxa = -INF;
    memset(occ, 0, sizeof occ);
    for (int i = 1; i <= N; i++) {
        if (dist[i] > maxa) {
            maxa = dist[i];
            midx = i;
        }
        occ[dist[i]]++;
    }
    for (int i = N - 2; i; i--) {
        if (!occ[i]) continue;
        if (occ[i] == 1) {
            ans++;
        } else break;
    }
}
int main() {
    cin >> N;
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    for (int i = 1; i <= N; i++) {
        if (dist[i] > maxa) {
            maxa = dist[i];
            midx = i;
        }
    }
    memset(dist, 0, sizeof dist);
    dfs(midx, -1);
    calc();
    memset(dist, 0, sizeof dist);
    dfs(midx, -1);
    calc();
    if (occ[N - 1] == 1)
        return cout << N - 1, 0;
    cout << ans << "\n";
}

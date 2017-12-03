#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100010
using namespace std;

int N, K;
vector <int> adj[MAXN], cadj[MAXN];
bool visited[MAXN], marked[MAXN];
int subsz[MAXN];
int ntotal;
void calc_sz(int src, int pa) {
    ntotal ++;
    subsz[src] = 1;
    for (int i : adj[src]) {
        if (i == pa || marked[i]) continue;
        calc_sz(i, src);
        subsz[src] += subsz[i];
    }
}
int findct(int src, int pa) {
    bool OK = true;
    int hvc = -1;
    for (int i : adj[src]) {
        if (i == pa || marked[i]) continue;
        if (subsz[i] > ntotal / 2) OK = false;
        if (hvc == -1 || subsz[hvc] < subsz[i])
            hvc = i;
    }
    if (OK && ntotal - subsz[src] <= ntotal / 2)
        return src;
    else
        return findct(hvc, src);
}
int val;
long long cnt[MAXN];
long long ans = 0;
void dfs(int u, int pa, int dist) {
    cnt[dist] += val;
    for (int i : adj[u]) {
        if (i == pa || marked[i]) continue;
        dfs(i, u, dist + 1);
    }
}
void dfs2(int u, int pa, int dist) {
    if (dist <= K) {
        ans += cnt[K - dist];
    }
    for (int i : adj[u]) {
        if (i == pa || marked[i]) continue;
        dfs2(i, u, dist + 1);
    }
}
void dfs3(int u, int pa) {
    cnt[0] = 2;
    val = 1;
    for (int i : adj[u]) {
        if (i == pa || marked[i]) continue;
        dfs(i, u, 1);
    }
    for (int i : adj[u]) {
        if (i == pa || marked[i]) continue;
        val = -1;
        dfs(i, u, 1);
        dfs2(i, u, 1);
        val = 1;
        dfs(i, u, 1);
    }
    val = -1;
    for (int i : adj[u]) {
        if (i == pa || marked[i]) continue;
        dfs(i, u, 1);
    }
}
int ctdecomp(int src) {
    ntotal = 0;
    calc_sz(src, -1);
    int ct = findct(src, -1);
    marked[ct] = true;
    dfs3(ct, -1);
    for (int i : adj[ct]) {
        if (!marked[i]) {
            int cst = ctdecomp(i);
            cadj[ct].push_back(cst);
            cadj[cst].push_back(ct);
        }
    }
    return ct;
}
int main() {
    cin >> N >> K;
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int st = ctdecomp(1);
    ans /= 2;
    ans = (long long) K * (K + 1) / 2 % MOD * (ans % MOD) % MOD;
    cout << ans << "\n";
    return 0;
}

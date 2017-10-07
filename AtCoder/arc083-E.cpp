#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 1010
#define MAXL 5010
#define SEGN 300030
using namespace std;

int N;
int X[MAXN], dp[MAXN];
vector <int> adj[MAXN];
int tdp[MAXL];
void dfs(int cur) {
    if (adj[cur].size() == 0) {
        dp[cur] = 0;
        return;
    }
    ll totw = 0;
    bool flag = false;
    for (int i : adj[cur])
        dfs(i);
    memset(tdp, 0, sizeof tdp);
    for (int i : adj[cur]) {
        totw += X[i];
        totw += dp[i];
        if (!flag) {
            flag = true;
            if (X[i] < MAXL) tdp[X[i]] = 1;
            if (dp[i] < MAXL) tdp[dp[i]] = 1;
        } else {
            for (int j = MAXL - 1; j >= 0; j--) {
                if (tdp[j]) {
                    tdp[j] = 0;
                    if (j + X[i] < MAXL) tdp[j + X[i]] = 1;
                    if (j + dp[i] < MAXL) tdp[j + dp[i]] = 1;
                }
            }
        }
    }
    int ans = INF;
//    cout << cur << ":    " << ans << "\n";
//    for (int i = 0; i < 10; i++)
//        cout << tdp[i] << " ";
    for (int i = 0; i <= X[cur]; i++) {
        if (tdp[i])
            ans = i;
    }
    if (ans > X[cur]) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    dp[cur] = totw - ans;
}
void print(int i) {
    cout << i << "\n";
}
int main() {
    cin >> N;
    for (int i = 2, a; i <= N; i++) {
        cin >> a;
        adj[a].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }
    dfs(1);
//    for_each(dp + 1, dp + N + 1, print);
    cout << "POSSIBLE";
}

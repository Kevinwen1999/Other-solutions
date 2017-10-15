#Round 51
#include <bits/stdc++.h>
#define ll unsigned long long
#define MOD 1000000007
#define MAXN 100010
using namespace std;

ll N, K;
vector <ll> adj[MAXN];
ll Pchoose[MAXN];
int main() {
    cin >> N >> K;
    for (ll i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Pchoose[0] = 1;
    for (ll i = 1; i <= min(N, K - 2); i++) {
        Pchoose[i] = (Pchoose[i - 1] * (K - 2 - i + 1)) % MOD;
    }
    ll ans = 1;
    for (ll i = 1; i <= N; i++) {
        ans = (ans * Pchoose[adj[i].size() - 1]) % MOD;
    }
    ans = (((ans * K) % MOD) * (K - 1)) % MOD;
    cout << ans << "\n";
}

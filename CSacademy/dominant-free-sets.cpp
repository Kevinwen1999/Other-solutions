#include <bits/stdc++.h>
#define MAXN 100001
#define MOD 1000000007
#define ll long long
using namespace std;
int N;
vector <pair <int, int> > v;
ll bit[MAXN];
void update(int i, int v) {
    for (int j = i; j < MAXN; j += (j & -j))
        bit[j] += v;
}
long long query(int i) {
    ll sum = 0;
    for (int j = i; j > 0; j -= (j & -j)) 
        sum += bit[j];
    return sum;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll val = ((query(MAXN - 1) % MOD) - (query(v[i].second) % MOD)  + 1 + MOD) % MOD;
        ans = (ans + val) % MOD;
        update(v[i].second, val);
    }
    cout << ans << "\n";
    return 0;
}

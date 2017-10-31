#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;
ll N, K;
int main() {
    cin >> N >> K;
    ll C = N * (N - 1) / 2LL;
    bool OK = true;
    ll need = N - K - 1;
    if (C - K < 2 * need) OK = false;
    if (!OK)
        return cout << -1 << "\n", 0;
    int i = 1, j = 2;
    cout << K + 2 * need << "\n";
    for (ll tot = 1; tot <= K + need; tot++) {
        cout << i << " " << j << " " << tot << "\n";
        i++, j++;
    }
    i = 1, j = 3;
    for (ll tot = K + need + 1; tot <= K + 2 * need; tot++) {
        if (j > N) {
            i++; 
            j = i + 2;
        }
        cout << i << " " << j << " " << tot << "\n";
        j++;
    }
    return 0;
}

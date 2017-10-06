#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 310
#define SEGN 300030
using namespace std;

int N;
ll adj[MAXN][MAXN];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
        }
    }
    ll total;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            bool flag = false;
            for (int k = 1; k <= N; k++) {
                if (k == i || k == j) continue;
                if (adj[i][k] + adj[j][k] < adj[i][j]) {
                    return cout << "-1\n", 0;
                } else if (adj[i][k] + adj[j][k] == adj[i][j]) {
                    flag = true;
                }
            }
            if (!flag) {
                total += adj[i][j];
            }
        }
    }
    cout << total << "\n";
}

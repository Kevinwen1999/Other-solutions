#include <bits/stdc++.h>

#define INF INT_MAX
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9

#define MAXN 100010
#define SEGN 300030
using namespace std;

ll N, K;
ll total;
int A[MAXN], B[MAXN];
bool used[MAXN];
void check(int X) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if ((A[i] | X) <= X) {
            sum += B[i];
        }
    }
    total = max(total, sum);
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < 30; i++) {
        if (K & (1 << i)) {
            int X = K;
            X ^= (1 << i);
            for (int j = i - 1; j >= 0; j--) {
                X |= (1 << j);
            }
            check(X);
        }
    }
    check(K);
    cout << total << "\n";
}

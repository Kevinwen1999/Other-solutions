#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10
 
#define MAXN 3010
#define SEGN 300030
using namespace std;
 
 
bitset<MAXN> water, suger;
int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    water[0] = suger[0] = 1;
    for (int i = 100 * A; i < MAXN; i++)
        water[i] = water[i] | water[i - 100 * A];
    for (int i = 100 * B; i < MAXN; i++)
        water[i] = water[i] | water[i - 100 * B];
    for (int i = C; i < MAXN; i++) {
        suger[i] = suger[i] | suger[i - C];
    }
    for (int i = D; i < MAXN; i++) {
        suger[i] = suger[i] | suger[i - D];
    }
    long double ans = -INF, ca;
    int a1, a2;
    for (int i = 1; i <= F; i++) {
        for (int j = 0; j <= F; j++) {
            if ((i + j <= F) && water[i] && suger[j] && (j * 100 <= (E * i) )) {
                ca = (100.0 * j) / (double)(i + j);
                if (ca > ans) {
                    ans = ca;
                    a1 = i + j, a2 = j;
                }
            }
        }
    }
    cout << a1 << " " << a2 << "\n";
}

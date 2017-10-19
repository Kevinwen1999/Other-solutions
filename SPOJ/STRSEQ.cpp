#include <bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;

string in;
int N;
int nextidx[MAXN][10];
int dp[MAXN];
int nextone[MAXN];
int DP(int cur) {
    if (~dp[cur]) return dp[cur];
    dp[cur] = INF;
    for (int i = 0; i < 10; i++) {
        int nx = nextidx[cur + 1][i];
        if (nx == INF) {
            nextone[cur] = i;
            return dp[cur] = 0;
        }
        if (dp[cur] > DP(nx) + 1) {
            dp[cur] = DP(nx) + 1;
            nextone[cur] = i;
        }
    }
    return dp[cur];
}
int main() {
    while (cin >> in) {
        int N = in.size();
        in = " " + in;
        for (int j = 0; j < 10; j++)
            nextidx[N + 1][j] = INF;
        for (int i = N; i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                nextidx[i][j] = nextidx[i + 1][j];
            }
            if (i)
                nextidx[i][in[i] - '0'] = i;
        }
        if (nextidx[0][0] == INF) {
            cout << "0\n";
            continue;
        }
        else {
            memset(dp, -1, sizeof dp);
            int minans = INF, st;
            for (int i = 1; i < 10; i++) {
                int nx = nextidx[1][i];
                if (nx == INF) {
                    st = i;
                    break;
                } else {
                    if (DP(nx) < minans) {
                        minans = DP(nx);
                        st = i;
                    }
                }
            }
            int pnt = 0;
            while(pnt != INF) {
                cout << st;
                pnt = nextidx[pnt + 1][st];
                if (pnt == INF) break;
                st = nextone[pnt];
            }
            cout << "\n";
        }
    }
}

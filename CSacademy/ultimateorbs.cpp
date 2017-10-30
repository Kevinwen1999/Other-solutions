#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 2000000007
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 1000010
#define MAXL 5
#define SEGN 300030

using namespace std;
int N;
ll D;
ll A[MAXN];
ll psum[MAXN];
ll lidx[MAXN], ridx[MAXN];
int dp[MAXN];
inline ll query (int j, int i) {
    return psum[j] - psum[i - 1];
}
int DP(int cur) {
    if (~dp[cur]) return dp[cur];
    if (lidx[cur] == 0 && ridx[cur] == N + 1) return dp[cur] = 1;
    if (lidx[cur]) {
        if (query(ridx[cur] - 1, lidx[cur] + 1) + D >= A[lidx[cur]] && DP(lidx[cur]))
            return dp[cur] = 1;
    }
    if (ridx[cur] != N + 1) {
        if (query(ridx[cur] - 1, lidx[cur] + 1) + D >= A[ridx[cur]] && DP(ridx[cur]))
            return dp[cur] = 1;
    }
    return dp[cur] = 0;
}
int main() {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    A[0] = A[N + 1] = INF;
    stack <pair <ll, int> > st;
    lidx[0] = lidx[N + 1] = 0;
    ridx[0] = ridx[N + 1] = N + 1;
    st.push({INF, 0});
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && st.top().first <= A[i]) st.pop();
        lidx[i] = st.top().second;
        st.push({A[i], i});
    }
    while (!st.empty()) st.pop();
    st.push({INF, N + 1});
    for (int i = N; i; i--) {
        while (!st.empty() && st.top().first <= A[i]) st.pop();
        ridx[i] = st.top().second;
        st.push({A[i], i});
    }
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i];
    }
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= N; i++) {
        if (DP(i))
            cout << i << " ";
    }
}

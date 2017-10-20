#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll unsigned long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 100010
#define MAXL 5010
#define SEGN 300030
using namespace std;

int N;
int node[SEGN];
int A[MAXN];
int query(int stidx, int L, int R, int i, int j) // i and j are the given range
{
    if (i > R || j < L) return INF; //out of range
    if (L >= i && R <= j) return node[stidx];
    int p1 = query(2*stidx, L, (L+R)/2, i,j);
    int p2 = query(2*stidx + 1, (L+R)/2 + 1, R, i,j);
    if (p1== INF) return p2;
    if (p2== INF) return p1;
    return min(p1, p2);//base on  the calculation, same as in buildtree;
}
//call update(1,0,N-1, index_of_value, value);
void update(int stidx, int L, int R, int idx, int val)
{
    if (L==R)
    {
        //assign val to node[stidx];
        node[stidx] = val;
        return;
    }
    int le = 2 * stidx, ri = le + 1, mid = (L + R) / 2;
    if (idx <= mid)
        update(le, L, mid, idx, val);
    else
        update(ri, mid+1, R, idx, val);
    int p1 = node[le], p2 = node[ri];
    //node[stidx] = merge result like in previous using node[le] and node[ri];
    node[stidx] = min(p1, p2);
}
int last[2 * MAXN];
ll ans = 0;
void intended_solution() {
    int N; cin >> N;
    stack <int> mono;
    int ans = 0;
    for (int i = 0, a; i <= N; i++) {
        if (i < N) cin >> a;
        else a = -1;
        while (!mono.empty() && mono.top() > a) {
            mono.pop();
            ans++;
        }
        if (mono.empty() || mono.top() < a) {
            mono.push(a);
        }
    }
    cout << ans << "\n";
}
int main() {
    int N;
    cin >> N;
    memset(last, -1, sizeof last);
    memset(node, 0x3f, sizeof node);
    int pre = -1;

    for (int i = 0, a; i < N; i++) {
        cin >> a;
        A[i] = a;
        update(1, 0, N - 1, i, a);
    }
    for (int i = 0, a; i < N; i++) {
        a = A[i];
        if (~last[a]) {
            if (query(1, 0, N - 1, last[a], i) >= a) {
                last[a] = i;
            } else {
                last[a] = i;
                ans++;
            }
        } else {
            last[a] = i;
            ans++;
        }
    }
    cout << ans << "\n";
}

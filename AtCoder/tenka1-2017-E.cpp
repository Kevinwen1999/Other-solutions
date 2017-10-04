#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-10

#define MAXN 40010
#define SEGN 300030
using namespace std;
struct line {
    double a, b, c;
    double slope() {
        return -(a / b);
    }
    double gety(double x) {
        return (-c / b) - (a * x / b);
    }
    double getx(double y) {
        return (-c / a) - (b * y / a);
    }
};
inline bool cmp1 (line &n1, line &n2) {
    return n1.slope() > n2.slope();
}
inline bool cmp2 (line &n1, line &n2) {
    return n1.slope() < n2.slope();
}
vector <line> AL;
int N;
double K;
int bit[MAXN];
void update(int x, int v) {
    for (int a = x; a <= N; a += (a & -a))
        bit[a] += v;
}
int query(int x) {
    int sum = 0;
    for (int a = x; a > 0; a -= (a & -a))
        sum += bit[a];
    return sum;
}
set <double> inter;
double seq[MAXN];
unordered_map <double, int> MP;
int cnt;
double findans(int mode) {
    double left = -INF, rght = INF;
    if (!mode) {
        sort(AL.begin(), AL.end(), cmp2);
    } else {
        for (auto &i : AL) {
            swap(i.a, i.b);
        }
        sort(AL.begin(), AL.end(), cmp2);
    }
    int steps = 0;
    while (steps < 100) {
        steps++;
        cnt = 1;
//        memset(bit, 0, sizeof bit);
        for (int i = 0; i <= N; i++)
            bit[i] = 0;
        inter.clear();
        double mid = (rght + left) / 2;
        for (line i : AL) {
            double a = i.gety(mid);
            inter.insert(a);
            seq[cnt++] = a;
        }
        cnt = 1;
        for (auto i : inter) {
            MP[i] = cnt++;
        }
        cnt = 0;
        for (int i = 1, c; i <= N; i++) {
            c = MP[seq[i]];
            cnt += query(c);
            update(c, 1);
        }
        if (cnt < K / 2.0) {
            left = mid + EPS;
        } else {
            rght = mid - EPS;
        }
    }
    return 0.5 * (left + rght);
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    K = (N * (N - 1)) / 2;
    for (int i = 1; i <= N; i++) {
        double a, b, c;
        cin >> a >> b >> c; c = -c;
        AL.push_back((line){a, b, c});
    }
    cout << fixed << setprecision(12) << findans(0) << " ";
    cout << findans(1) << "\n";
}

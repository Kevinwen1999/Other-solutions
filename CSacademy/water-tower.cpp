#include <bits/stdc++.h>
#define ld long double
using namespace std;

int H, Q;
vector < pair <int, int> > blyat;

int main() {
    cin >> H >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        blyat.push_back({a, b});
    }
    sort (blyat.begin(), blyat.end());
    priority_queue <int> pq;
    ld rate = 0;
    ld tm = 0;
    ld level = H;
    for (int i = 0; i < Q; i++) {
        while (!pq.empty()) {
            ld nl = level - (blyat[i].first - tm) * rate;
            if (nl > pq.top()) break;
            else {
                tm += (level - pq.top()) / rate;
                level = pq.top();
                pq.pop();
                rate -= 1;
            }
        }
        if (level == 0) {
            cout << fixed << setprecision(7) << tm << "\n";
            return 0;
        }
        level = level - (blyat[i].first - tm) * rate;
        tm = blyat[i].first;
        if (level > blyat[i].second) rate += 1, pq.push(blyat[i].second); // cykacykacykacyka
    }
    while (!pq.empty()) {
        tm += (level - pq.top()) / rate;
        level = pq.top();
        pq.pop();
        rate -= 1;
    }
    if (level != 0) cout << -1 << "\n";
    else cout << fixed << setprecision(7) << tm << "\n";
}

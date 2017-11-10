#include <bits/stdc++.h>
#define ll long long
using namespace std;
unordered_set <ll> all;
vector <ll> v;
ll tot;
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    deque <ll> dq;
    while (dq.size() || v.size()) {
        ll maxx = -1;
        if (dq.size()) maxx = max(maxx, dq.front());
        if (v.size()) maxx = max(maxx, v.back());
        tot += 1;
        if (maxx != 1) {
            dq.push_back(maxx / 2);
        }
        while (dq.size() && dq.front() == maxx) dq.pop_front();
        while (v.size() && v.back() == maxx) v.pop_back();
    }
    cout << tot - 1 << "\n";
}

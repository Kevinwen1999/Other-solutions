#include <bits/stdc++.h>

using namespace std;
vector <int> v;
multiset <int> s, tmp;
int main() {
    int N; cin >> N; N *= 2;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
        s.insert(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N / 2; i++) {
    }
    for (int i = 0; i < N; i++) {
        int x = v[N - 1] - v[i];
        tmp = s;
        bool OK = true;
        while (!tmp.empty()) {
            multiset<int>::iterator it = tmp.begin();
            int val = *it; val += x;
            tmp.erase(it);
            if (!tmp.empty() && tmp.count(val)) {
                tmp.erase(tmp.lower_bound(val));
            } else {
                OK = false; break;
            }
        }
        if (OK) {
            cout << x << "\n";
            tmp = s;
            while (!tmp.empty()){
                multiset<int>::iterator it = tmp.begin();
                int val = *it; val += x;
                tmp.erase(it);
                if (!tmp.empty() && tmp.count(val)) {
                    cout << val << " ";
                    tmp.erase(tmp.lower_bound(val));
                } else {
                    OK = false; break;
                }
            }
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
} 

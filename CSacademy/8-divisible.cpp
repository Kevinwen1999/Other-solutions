#include <bits/stdc++.h>

using namespace std;
int N;
string in;
multiset<int> ms;
int ent[126][3];
int main() {
    string ans = "X";
    cin >> in; 
    N = in.size();
    if (N == 1) {
        cout << ( in == "0" || in == "8" ? in : "-1");
        return 0;
    }
    if (N == 2) {
        int a = stoi(in);
        if (a % 8 == 0) ans = in;
        if (in[1] != '0') {
            reverse(in.begin(), in.end());
            int b = stoi(in);
            if (b % 8 == 0 && b < a) {
                ans = in;
            }
        }
        cout << (ans == "X" ? "-1" : ans);
        return 0;
    }
    for (int i = 0; i < N; i++) {
        ms.insert(in[i] - '0');
    }
    for (int i = 0; i < 125; i++) {
        int t = 8 * i;
        int c = 2;
        while (t) {
            ent[i][c--] = t % 10;
            t /= 10;
        }
    }
    for (int i = 0; i < 125; i++) {
        //cout << i << ": test\n";
        bool OK = true;
        vector<int> tv;
        for (int j = 0; j < 3; j++) {
            if (ms.count(ent[i][j])) {
                tv.push_back(ent[i][j]);
                ms.erase(ms.lower_bound(ent[i][j]));
            } else {
                OK = false; break;
            }
        }
        if (!OK || (ms.empty() && ent[i][0] == 0) || (!ms.empty() && ms.upper_bound(0) == ms.end())) {
            for (int j : tv) {
                ms.insert(j);
            } 
            continue;
        }
        string ta = "";
        if (!ms.empty()) {
            multiset<int>::iterator it = ms.upper_bound(0);
            ta += to_string(*it);
            tv.push_back(*it);
            ms.erase(it);
        }
        for (int j : ms) ta += to_string(j);
        for (int j : ent[i]) {
            ta += to_string(j);
        }
        if (ans == "X" || ans > ta)
            ans = ta;
        for (int j : tv) {
            ms.insert(j);
        }
    }
    if (ans == "X")
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}

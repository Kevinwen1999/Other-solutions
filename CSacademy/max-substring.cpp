#include <bits/stdc++.h>
using namespace std;
string in;
int N;
vector<int> sts[30];
int main() {
    cin >> in;
    N = in.size();
    for (int i = 0; i < N; i++) {
        sts[in[i] - 'a'].push_back(i);
    }
    int maxl = -1, maxz = 1;
    int ts;
    for (int i = 0; i < 26; i++) {
        if (sts[i].size() < maxz) continue;
        int l;
        // string length is at most 26
        for (l = 0; l < 26; l++) {
            bool OK = true;
            char tar = 'A';
            for (int k = 0; k < sts[i].size(); k++) {
                if (sts[i][k] + l >= N) {
                    OK = false;
                    break;
                }
                char j = in[sts[i][k] + l];
                if (tar == 'A')
                    tar = j;
                else if (j != tar) {
                    OK = false;
                    break;
                }
            }
            if (!OK) break;
        }
        if (maxz < sts[i].size()) {
            maxz = sts[i].size();
            maxl = l;
            ts = sts[i][0];
        } else if (maxz == sts[i].size() && l > maxl) {
            maxz = sts[i].size();
            maxl = l;
            ts = sts[i][0];
        }
    }
    cout << in.substr(ts, maxl) << "\n";
    return 0;
}

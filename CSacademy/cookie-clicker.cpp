#include <bits/stdc++.h>
using namespace std;

int N, C, S;

int A[5], B[5];

int main() {
    cin >> N >> C >> S;
    vector <int> blyat;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        blyat.push_back(i);
    }
    int best = (C - 1) / S + 1;
    do {
        int rate = S;
        int cookies = 0;
        int days = 0;
        for (int i = 0; i < N; i++) {
            int cur = blyat[i];
            int diff = A[cur] - cookies;
            if (diff > 0) {
                int extra = (diff - 1) / rate + 1;
                cookies += extra * rate;
                days += extra;
            }
            cookies -= A[cur];
            rate += B[cur];
            int left = (C - cookies > 0) ? ((C - cookies - 1) / rate + 1) : 0;
            best = min(best, days + left);
        }
    } while (next_permutation(blyat.begin(), blyat.end()));
    cout << best << "\n";
}

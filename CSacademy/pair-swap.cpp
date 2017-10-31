#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int N, D; 
vector <int> A;
int main() {
    cin >> N >> D;
    for (int i = 0, a; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }
    int st = 0, ed = 0;
    deque <pair <int, int>> dq;
    for (ed; ed < N && ed <= D; ed++) {
        while (!dq.empty() && dq.back().first >= A[ed])
            dq.pop_back();
        dq.push_back({A[ed], ed});
    }
    while (true) {
        if (st == N - 1) break;
        if (dq.front().second == st) dq.pop_front();
        if (dq.front().first < A[st]) {
            swap(A[st], A[dq.front().second]);
            break;
        }
        if (ed < N) {
            while (!dq.empty() && dq.back().first >= A[ed])
                dq.pop_back();
            dq.push_back({A[ed], ed});
            ed++;
        }st++;
        
    }
    for (int i : A)
        cout << i << " ";
    return 0;
    return 0;
}

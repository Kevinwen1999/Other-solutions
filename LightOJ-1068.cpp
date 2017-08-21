#include <bits/stdc++.h>
using namespace std;
int na;
string A, B, C;
int K, N;
int dp[11][101][101][2];
string to_str(int t) {
  stringstream ss;
  ss << t;
  return ss.str();
}
int DP(int idx, int sum, int num, int flag) {
    int &ans = dp[idx][sum][num][flag];
    if (ans != -1) return ans;
    if (idx == N) {
        return ans = (sum == 0 && num == 0) ? 1 : 0;
    }
    ans = 0;
    int range = flag ? 9 : C[idx] - '0';
    for (int i = 0; i <= range; i++) {
        ans += DP(idx + 1, (sum + i) % K, ((num * 10) % K + i) % K, flag || i < range);
    }
    return ans;
}
void exec(int kase) {
    cin>>na>>B>>K;
    na--; A = to_str(na);
    cout<<"Case "<<kase<<": ";
    if (K >= 100) {
        cout<<0<<"\n"; return;
    }
    memset(dp, -1, sizeof dp);
    C = B, N = B.size();
    int a = DP(0, 0, 0, 0);
    memset(dp, -1, sizeof dp);
    C = A, N = A.size();
    a -= DP(0, 0, 0, 0);
    cout<<a<<"\n";
}

int main() {
    int T;
    cin>>T;
    for (int i = 1; i <= T; i++) {
        exec(i);
    }
}

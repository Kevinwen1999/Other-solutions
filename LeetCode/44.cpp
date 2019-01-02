#define MAXN 10001
class Solution {
public:
    bool isMatch(string s, string p) {
        int N = s.size(), M = p.size();
        if (!N) {
            if (!M || (M == 1 && p[0] == '*'))
                return true;
            else return false;
        }
        bool dp[2][MAXN][2] = {0};
        dp[0][0][0] = true;
        bool ans = false;
        int flag = 0;
        for (int i = 0; i <= N; i++) {
            memset(dp[flag ^ 1], 0, sizeof dp[flag ^ 1]);
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < 2; k++) {
                    if (!dp[flag][j][k]) continue;
                    if (i < N && (s[i] == p[j] || p[j] == '?')) {
                        dp[flag ^ 1][j + 1][0] = true;
                    }
                    if (k) {
                        dp[flag ^ 1][j][1] = true;
                    }
                    if (p[j] == '*') {
                        dp[flag][j + 1][1] = true;
                    }
                }
            }
            ans = ans || dp[flag][M][1];
            flag ^= 1;
        }
        flag ^= 1;
        ans = ans || dp[flag][M][0] || dp[flag][M][1];
        return ans;
    }
};

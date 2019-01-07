#define MAXN 10000
class Solution {
public:
    bool isMatch(string s, string p) {
        int N = s.size(), M = p.size();
        bool dp[2][MAXN] = {0};
        dp[0][0] = true;
        int flag = 0;
        for (int i = 0; i < N; i++) {
            memset(dp[flag ^ 1], 0, sizeof dp[flag ^ 1]);
            for (int j = 0; j < M; j++) {
                if (!dp[flag][j]) continue;
                if (s[i] == p[j] || p[j] == '.') {
                    if (j + 1 < M && p[j + 1] == '*') {
                        dp[flag ^ 1][j] = true;
                        dp[flag ^ 1][j + 2] = true;
                        dp[flag][j + 2] = true;
                    } else {
                        dp[flag ^ 1][j + 1] = true;
                    }
                } else if (j + 1 < M && p[j + 1] == '*') {
                    dp[flag][j + 2] = true;
                }
            }
            flag ^= 1;
        }
        for (int j = 0; j < M; j++) { 
            if (!dp[flag][j]) continue;
            if (j + 1 < M && p[j + 1] == '*') {
                dp[flag][j + 2] = true;
            }
        }
        return dp[flag][M];
    }
};

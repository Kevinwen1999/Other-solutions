#define MAXN 3000
class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        bool pa[MAXN][MAXN] = {0};
        int dp[MAXN] = {0};
        for (int i = 0; i < N; i++) {
            pa[i][i] = true;
            if (i) pa[i - 1][i] = (s[i] == s[i - 1]);
        }
        for (int k = 3; k <= N; k++) {
            for (int i = 0; i + k - 1 < N; i++) {
                pa[i][i + k - 1] = (s[i] == s[i + k - 1]) && pa[i + 1][i + k - 2];
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            for (int j = i + 1; j < N; j++) {
                if (pa[i][j]) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }
        return dp[0] - 1;
    }
};

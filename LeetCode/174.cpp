#define MAXN 500
class Solution {
public:
    int M, N;
    int dp[MAXN][MAXN];
    int dp1[MAXN][MAXN];
    int bs_sol(vector<vector<int>>& dungeon) {
        M = dungeon.size();
        N = dungeon[0].size();
        int l = 0, r = 100000;
        while (l <= r) {
            int mid = (l + r) / 2;
            dp[0][0] = dp1[0][0] = dungeon[0][0] + mid;
            bool shit = false;
            for (int i = 1; i < N; i++) {
                dp[0][i] = -1;
                if (dp[0][i - 1] > 0) dp[0][i] = dp[0][i - 1] + dungeon[0][i];
            }
            for (int i = 1; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    dp[i][j] = -1;
                    if (dp[i - 1][j] > 0) dp[i][j] = dp[i - 1][j] + dungeon[i][j];
                    if (j && dp[i][j - 1] > 0) {
                        int d = dp[i][j - 1] + dungeon[i][j];
                        if (d > dp[i][j]) {
                            dp[i][j] = d;
                        }
                    }
                }    
            }
            if (dp[M - 1][N - 1] > 0) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l == 0 ? 1 : l;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        M = dungeon.size();
        N = dungeon[0].size();
        int ans[MAXN];
        memset(ans, 0x3f, sizeof ans);
        for (int i = M - 1; i >= 0; i--) {
            if (i == M - 1) ans[N] = 1;
            else ans[N] = 0x3f3f3f3f;
            for (int j = N - 1; j >= 0; j--) {
                ans[j] = max(1, min(ans[j + 1], ans[j]) - dungeon[i][j]);
            }
        }
        return ans[0];
    }
};

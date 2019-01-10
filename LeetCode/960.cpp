class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int dp[101];
        int N = A.size();
        int M = A[0].size();
        int ans = 1;
        for (int i = 0; i < M; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                bool smaller = true;
                for (int k = 0; k < N; k++) {
                    if (A[k][j] > A[k][i]) {
                        smaller = false;
                    }
                }
                if (smaller) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans =  max(ans, dp[i]);
        }
        return M - ans;
    }
};

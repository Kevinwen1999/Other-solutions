class Solution {
public:
    int dp[1001][1001] = {0};
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        int ans = 0;
        unordered_map<int, int> idx;
        for (int i = 0; i < N; i++) {
            idx[A[i]] = i;
        }
        // Assume A[k] + A[j] = A[i]
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j];
                if (idx.count(diff) && A[i] - A[j] < A[j]) { // check whether the first one exists and is also after j
                    int k = idx[diff];
                    dp[j][i] = dp[k][j] + 1;
                    ans = max(ans, dp[j][i] + 2);
                }
            }
        }
        return ans <= 2 ? 0 : ans;
    }
};

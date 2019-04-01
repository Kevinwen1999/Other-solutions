#define MAXN 501
class Solution {
public:
    int N;
    int dp[MAXN][MAXN];
    int recur(int l, int r, vector<int>& nums) {
        if (dp[l][r] != -1) return dp[l][r];
        
        for (int i = l; i <= r; i++) {
            int t = nums[i];
            if (l != 0) t *= nums[l - 1];
            if (r != N) t *= nums[r + 1];
            
            if (i != l) t += recur(l, i - 1, nums);
            if (i != r) t += recur(i + 1, r, nums);
            
            dp[l][r] = max(dp[l][r], t);
        }
        
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        N = nums.size() - 1;
        if (N < 0) return 0;
        return recur(0, N, nums);
    }
};

class Solution {
public:
    int dp[31][2][2];
    int cur[31];
    int recur(int n, int val, bool limited) {
        int &ans = dp[n][val][limited];
        if (ans != -1) return ans;
        ans = 0;
        if (n == 0) {
            ans = 1;
            if (val != 1 && (!limited || (limited && cur[n] == 1)))
                ans ++;
            return ans;
        }
        int choice = 0;
        bool nlimited = limited && (choice >= cur[n]);
        ans += recur(n - 1, choice, nlimited);
        if (val != 1 && (!limited || (limited && cur[n] == 1))) {
            choice = 1;
            nlimited = limited;
            ans += recur(n - 1, choice, nlimited);
        }
        return ans;
    }
    int findIntegers(int num) {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < 31; i++) {
            cur[i] = (num >> i) & 1;
        }
        return recur(30, 0, true);
    }
};

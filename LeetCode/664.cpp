class Solution {
public:
    int MAX = 0x3f3f3f3f;
    int dp[110][110];
    void init() {
        for (int i = 0; i < 110; i++)
            for (int j = 0; j < 110; j++)
                dp[i][j] = MAX;
    }
    string str;
    int recur(int i, int j) {
        if (dp[i][j] != MAX) return dp[i][j];
        int& ans = dp[i][j];
        if (i == j) return ans = 1;
        if (i + 1 == j) return ans = 2;
        for (int k = i; k < j; k++) {
            int tmp = recur(i, k) + recur(k + 1, j);
            if (str[i] == str[j]) {
                tmp--;
            }
            ans = min(ans, tmp);
        }
        return ans;
    }
    int strangePrinter(string s) {
        int N = static_cast<int>(s.size());
        if (!N) return 0;
        for (int i = 0; i < N; i++) {
            if (i == N - 1) str += s[i];
            else if (s[i] != s[i + 1]) str += s[i];
        }
        init();
        N = str.size();
        recur(0, N - 1);
        return dp[0][N-1];
    }
};

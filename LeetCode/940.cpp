class Solution {
public:
    long long MOD = 1e9 + 7;
    long long dp[2010];
    long long last[30];
    int distinctSubseqII(string S) {
        int N = S.size();
        for (int i = 0; i < N; i++) {
            dp[i] = !i ? 1LL : (1 + ((2 * dp[i - 1]) % MOD) - last[S[i] - 'a'] + MOD) % MOD;
            last[S[i] - 'a'] = !i ? 1LL : (dp[i - 1] + 1) % MOD;
            //cout << dp[i] << " " << last[S[i] - 'a'] << "\n";
        }
        return dp[N - 1];
    }
};

#define MAXN 1000000
#define ll long long
class Solution {
public:
    int N, M;
    ll dp[MAXN];
    ll numDistinct(string s, string t) {
        N = s.size(), M = t.size();
        
        for (int i = 0; i < N; i++) {
            dp[i] = (i ? dp[i - 1] : 0) + (s[i] == t[0] ? 1 : 0);
        }
        
        for (int i = 1; i < M; i++) {
            for (int j = N - 1; j >= 0; j--) {
                dp[j] = 0;
                if (s[j] != t[i]) continue;
                if (j) dp[j] += dp[j - 1];
            }
            for (int i = 1; i < N; i++) dp[i] += dp[i - 1];
        }
        
        return dp[N - 1];
    }
};

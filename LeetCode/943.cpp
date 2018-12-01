class Solution {
public:
    int N;
    int INF = 0x3f3f3f3f;
    int calc_length(string s1, string s2) {
        int ans = 0;
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1.substr(s1.size() - 1 - i, i + 1) == s2.substr(0, i + 1))
                ans = i + 1;
        }
        return s2.size() - ans;
    }
    int cover[20][20];
    int dp[20][1<<12];
    int nex[20][1<<12];
    int recur(int cur, int mask) {
        int& ans = dp[cur][mask];
        if (ans != -1) return ans;
        if (mask == ((1 << N) - 1)) return ans = 0;
        ans = INF;
        for (int i = 1; i <= N; i++) {
            if ((mask >> (i - 1)) & 1) continue;
            if ((cover[cur][i] + recur(i, mask | (1 << (i - 1)))) < ans) {
                ans = cover[cur][i] + recur(i, mask | (1 << (i - 1)));
                nex[cur][mask] = i;
            }
        }
        return ans;
    }
    string shortestSuperstring(vector<string>& A) {
        N = A.size();
        for (int i = 0; i < N; i++) {
            cover[0][i + 1] = A[i].size();
            for (int j = 0; j < N; j++) {
                cover[i + 1][j + 1] = calc_length(A[i], A[j]);
            }
        }
        memset(dp, -1, sizeof dp);
        recur(0, 0);
        int cnt = 0, cur = 0, mask = 0;
        string ans = "";
        while (cnt != N) {
            ans += A[nex[cur][mask] - 1].substr(A[nex[cur][mask] - 1].size() - cover[cur][nex[cur][mask]], cover[cur][nex[cur][mask]]);
            cnt++;
            cur = nex[cur][mask];
            mask |= (1 << (cur - 1));
        }
        return ans;
    }
};

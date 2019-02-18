#define MAXN 100
class Solution {
public:
    int dp[MAXN][MAXN][MAXN];
    string S1, S2;
    
    int recur(int a, int b, int l) {
        int &ans = dp[a][b][l];
        if (ans != -1) return ans;
        if (l == 1) {
            ans = (S1[a] == S2[b] ? 1 : 0);
            return ans;
        }
        ans = 0;
        for (int mid = a; mid < a + l - 1 && !ans; mid++) {
            int length_l = mid - a + 1;
            int length_r = l - length_l;
            if (recur(a, b, length_l) != 0 && recur(mid + 1, b + length_l, length_r) != 0) {
                ans++;
            } else if (recur(mid + 1, b, length_r) != 0 && recur(a, b + length_r, length_l) != 0) {
                ans++;
            }
        }
        return ans;
    }
    
    bool isScramble(string s1, string s2) {
        if (s1.size() == 1) {
            return s1[0] == s2[0];
        }
        S1 = s1, S2 = s2;
        memset(dp, -1, sizeof dp);
        return recur(0, 0, s1.size()) != 0;
    }
};

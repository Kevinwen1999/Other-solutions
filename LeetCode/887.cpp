#define ll long long
#define MAXN 1000
class Solution {
public:
    ll dp[110][MAXN];
    ll recur(int negg, int ntry) {
        ll &ans = dp[negg][ntry];
        if (ans != -1) return ans;
        if (negg == 1) return ans = ntry;
        if (ntry == 1) return ans = 1;
        return ans = recur(negg, ntry - 1) + recur(negg - 1, ntry - 1) + 1;
    }
    int superEggDrop(int K, int N) {
        memset(dp, -1, sizeof dp);
        int ntry = 1;
        while (true) {
            if (recur(K, ntry) >= N) return ntry;
            else ntry ++;
        }
    }
};

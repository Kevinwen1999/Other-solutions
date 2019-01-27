#define MAXN 10010
class Solution {
public:
    int dp[2][MAXN];
    int N;
    int flag;
    int maxx;
    void calc(vector<int>& prices) {
        vector <pair <int, int>> mono;
        int mindiff = prices[0]; // min of prices[i] - dp[k - 1][i - 1]
        for (int i = 1; i < N; i++) {
            dp[flag][i] = dp[1 - flag][i];
            if (i) dp[flag][i] = max(dp[flag][i], dp[flag][i - 1]);
            dp[flag][i] = max(dp[flag][i], prices[i] - mindiff);
            maxx = max(maxx, dp[flag][i]);
            if (i) mindiff = min(mindiff, prices[i] - dp[1 - flag][i - 1]);
        }
        flag = 1 - flag;
    }
    int maxProfit(int k, vector<int>& prices) {
        N = prices.size();
        if (!N) return 0;
        k = min(k, N / 2 + 1);
        while (k--) {
            calc(prices);
        }
        return maxx;
    }
};
/* Back when I was not using brain
void calc(vector<int>& prices) {
    vector <pair <int, int>> mono;
    for (int i = 0; i < N; i++) {
        dp[flag][i] = dp[1 - flag][i];
        if (i) dp[flag][i] = max(dp[flag][i], dp[flag][i - 1]);
        while (!mono.empty() && mono.back().first > prices[i])
            mono.pop_back();
        for (auto j : mono) {
            int temp = (j.second - 1 >= 0) ? dp[1 - flag][j.second - 1] : 0;
            temp += prices[i] - j.first;
            dp[flag][i] = max(dp[flag][i], temp);
        }
        mono.push_back({prices[i], i});
        maxx = max(maxx, dp[flag][i]);
    }
    flag = 1 - flag;
}
*/

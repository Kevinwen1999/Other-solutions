class Solution {
public:
    int N;
    vector <pair <int, int> > pros;
    inline int getval(vector<int>& prices, int i) {
        return prices[pros[i].second] - prices[pros[i].first];
    }
    int maxProfit(vector<int>& prices) {
        N = prices.size();
        int st = 0;
        int ans = 0;
        while (st < N) {
            while (st + 1 < N && prices[st] >= prices[st + 1]) st ++;
            if (st == N - 1) break;
            int l = st ++;
            while (st + 1 < N && prices[st] <= prices[st + 1]) st ++;
            int r = st ++;
            pros.push_back({l, r});
        }
        if (pros.empty()) return ans;
        vector <int> dp, dp2;
        dp.push_back(getval(prices, 0));
        dp2.push_back(dp[0]);
        int minn = pros[0].first, midx = 0;
        ans = dp[0];
        int n = pros.size();
        for (int i = 1; i < n; i++) {
            dp.push_back(dp[i - 1]);
            dp2.push_back(dp2[i - 1]);
            if (prices[pros[i].first] <= prices[minn]) minn = pros[i].first, midx = i;
            dp[i] = max(dp[i], prices[pros[i].second] - prices[minn]);  
            dp2[i] = dp2[i - 1];
            for (int j = i; j >= 0; j--)
                dp2[i] = max(dp2[i], prices[pros[i].second] - prices[pros[j].first] + (j >= 1 ? dp[j - 1] : 0));
            ans = dp2[i];
        }
        return ans;
    }
};

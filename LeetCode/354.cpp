#define MAXN 10000
pair<int, int> lis[MAXN];
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
            return a.first == b.first ? a.second > b.second : a.first < b.first;});
        
        int len = 0;
        
        for (int i = 0; i < envelopes.size(); i++) {
            if (!len || (lis[len - 1].first < envelopes[i].first && lis[len - 1].second < envelopes[i].second))
                lis[len++] = envelopes[i];
            else if (lis[0].first > envelopes[i].first && lis[0].second > envelopes[i].second) {
                lis[0] = envelopes[i];
            } else {
                int l = 0, r = len - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (lis[mid].first < envelopes[i].first && lis[mid].second < envelopes[i].second) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                lis[r + 1] = envelopes[i];
            }
        }
        
        return len;
        
        /*
        sort(envelopes.begin(), envelopes.end());
        
        int ans = 0;
        
        vector<int> dp;
        for (int i = 0; i < envelopes.size(); i++) {
            dp.push_back(1);
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
        */
    }
};

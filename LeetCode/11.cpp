class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        
        vector<pair <int, int>> left_inc;
        vector<pair <int, int>> right_inc;
        
        //Construct increasing sequence from left and inc from right
        for (int i = 0; i < N; i++) {
            if (!i || height[i] > left_inc.back().first) {
                left_inc.push_back({height[i], i});
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            if (i == N - 1 || height[i] > right_inc.back().first) {
                right_inc.push_back({height[i], i});
            }
        }
        
        // Calculate area with left bounds and right bounds
        int ans = 0;
        int ln = left_inc.size(), rn = right_inc.size();
        for (int i = 0, j = 0; i < ln; i++) {
            while (j < rn - 1 && right_inc[j].first < left_inc[i].first)
                j++;
            ans = max(ans, left_inc[i].first * (right_inc[j].second - left_inc[i].second));
        }
        for (int i = 0, j = 0; i < rn; i++) {
            while (j < ln - 1 && left_inc[j].first < right_inc[i].first)
                j++;
            ans = max(ans, right_inc[i].first * (right_inc[i].second - left_inc[j].second));
        }
        
        return ans;
    }
};

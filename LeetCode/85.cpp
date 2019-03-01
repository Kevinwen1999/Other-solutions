class Solution {
public:
    vector<pair<int, int>> mono;
    
    int ans = 0;
    int clearans(int right_idx, int tar_h) {
        int left_idx = -1;
        while(!mono.empty() && mono.back().first > tar_h) {
            ans = max(ans, mono.back().first * (right_idx - mono.back().second + 1));
            left_idx = mono.back().second;
            mono.pop_back();
        }
        return left_idx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int N = (int)matrix.size();
        if (N == 0) return 0;
        int M = (int)matrix[0].size();
        vector<int> h(M, 0);
        
        for (int i = 0; i < N; i++) {
            clearans(M - 1, 0);
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == '0') {
                    h[j] = 0;
                    clearans(j - 1, 0);
                    continue;
                }
                h[j] += 1;
                int left_idx = clearans(j - 1, h[j]);
                left_idx = left_idx == -1 ? j : left_idx;
                mono.push_back(make_pair(h[j], left_idx));
            }
        
        }
        clearans(M - 1, 0);
        
        return ans;
    }
};

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int M = matrix.size(), N = matrix[0].size();
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i > 0) matrix[i][j] += matrix[i - 1][j];
                if (j > 0) matrix[i][j] += matrix[i][j - 1];
                if (i > 0 && j > 0) matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }
        
        int rtn = INT_MIN;
        
        for (int i1 = 0; i1 < M; i1++) {
            for (int j1 = 0; j1 < N; j1++) {
                for (int i2 = i1; i2 < M; i2++) {
                    for (int j2 = j1; j2 < N; j2++) {
                        int ans = matrix[i2][j2];
                        if (i1 > 0) ans -= matrix[i1 - 1][j2];
                        if (j1 > 0) ans -= matrix[i2][j1 - 1];
                        if (i1 > 0 && j1 > 0) ans += matrix[i1 - 1][j1 - 1];
                        if (ans <= k) rtn = max(rtn, ans);
                    }
                }
            }
        }
        
        return rtn;
    }
};

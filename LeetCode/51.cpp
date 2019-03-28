#define MAXN 10000
class Solution {
public:
    int N;
    vector<vector<string>> ans;
    vector<string> temp;
    
    int col[MAXN], diag1[MAXN], diag2[MAXN];
    
    void recur(int row) {
        if (row == N) {
            ans.push_back(temp);
        }
        
        string cs (N, '.');
        
        for (int i = 0; i < N; i++) {
            if (col[i] || diag1[row - N + i + N] || diag2[row - i + N])
                continue;
            
            cs[i] = 'Q';
            temp.push_back(cs);
            col[i] = diag1[row - N + i + N] = diag2[row - i + N] = 1;
            recur(row + 1);
            col[i] = diag1[row - N + i + N] = diag2[row - i + N] = 0;
            temp.pop_back();
            cs[i] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        recur(0);
        return ans;
    }
};

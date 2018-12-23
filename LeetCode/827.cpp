class Solution {
public:
    int M, N;
    int node[50][50];
    int tot = 0;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    bool valid(int i, int j) {
        return i >= 0 &&i < M && j >= 0 && j < N;
    }
    void dfs(int i, int j, int &cnt, vector<vector<int>>& grid) {
        if (node[i][j]) return;
        node[i][j] = tot;
        cnt++;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (!valid(ni, nj)) continue;
            if (!grid[ni][nj]) continue;
            dfs(ni, nj, cnt, grid);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        memset(node, 0, sizeof node);
        M = grid.size(), N = grid[0].size();
        vector <int> vals;
        vals.push_back(0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] && !node[i][j]) {
                    tot ++;
                    int cnt = 0;
                    dfs(i, j, cnt, grid);
                    if (cnt == M * N) return cnt;
                    vals.push_back(cnt);
                }
            }
        }
        int maxans = 0;
        set<int> pool;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!grid[i][j]) {
                    pool.clear();
                    int tans = 1;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + di[k], nj = j + dj[k];
                        if (!valid(ni, nj)) continue;
                        if (!pool.count(node[ni][nj])) {
                            tans += vals[node[ni][nj]];
                            pool.insert(node[ni][nj]);
                        }
                    }
                    maxans = max(maxans, tans);
                }
            }
        }
        return maxans;
    }
};

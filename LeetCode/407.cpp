class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int M = heightMap.size(), N = heightMap[0].size();
        int maxx = -1, tot = 0;
        
        int di[] = {0, 0, 1, -1};
        int dj[] = {1, -1, 0, 0};
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                    pq.push({heightMap[i][j], i * N + j});
                    visited[i][j] = true;
                }
            }
        }
        
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int ch = cur.first, i = cur.second / N, j = cur.second % N;
            maxx = max(maxx, ch);
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= M || nj >= N || visited[ni][nj]) continue;
                visited[ni][nj] = true;
                if (heightMap[ni][nj] < maxx) tot += maxx - heightMap[ni][nj];
                pq.push({heightMap[ni][nj], ni * N + nj});
            }
        }
        
        return tot;
    }
};

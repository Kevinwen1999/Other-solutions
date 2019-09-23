const int MAXN = 1010;
class Solution {
public:
    vector<int> adj[MAXN];
    int cnt = 0;
    int visited[MAXN];
    int ss, se;
    
    bool dfs(int cur){
        if (visited[cur] == cnt) {
            return false;
        }
        visited[cur] = cnt;
        bool ok = true;
        for (int j : adj[cur]) {
            if (cur == ss && j == se) continue;
            ok = ok && dfs(j);
        }
        return ok;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int E = edges.size();
        
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
        }
        for (int i = E - 1; i >= 0; i--) {
            memset(visited, 0, sizeof visited);
            ss = edges[i][0], se = edges[i][1];
            bool check = true;
            cnt = 1;
            for (int j = 1; j <= E; j++) {
                if (!visited[j]) {
                    cnt++;
                    check = check && dfs(j);
                }
            }
            for (int j = 1; j < E; j++) {
                if (visited[j] != visited[j + 1])
                    check = false;
            }
            if (check) {
                return edges[i];
            }
        }
        return edges[0];
    }
};

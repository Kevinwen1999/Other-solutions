#define MAXN 80000
#define MAXM 200
class Solution {
public:
    int sz = 1;
    unordered_map <int, int> trie[MAXN];
    int val[MAXN];
    int N, M;
    bool visited[MAXM][MAXM];
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    unordered_set <int> ans;
    
    void init() {
        sz = 1;
        memset(val, -1, sizeof val);
    }
    int ctoi(char a) {
        return a - 'a';
    }
    void insert_word(string s, int idx) {
        int n = s.size();
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (!trie[cur].count(ctoi(s[i]))) {
                trie[cur][ctoi(s[i])] = sz++;
            }
            cur = trie[cur][ctoi(s[i])];
        }
        val[cur] = idx;
    }
    
    bool valid(int i, int j) {
        return (i >= 0 && j >= 0 && i < N && j < M);
    }
    void dfs(int i, int j, int cur, vector<vector<char>>& board) {
        if (cur == -1) return;
        if (val[cur] != -1) ans.insert(val[cur]);
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!valid(ni, nj)) continue;
            if (visited[ni][nj]) continue;
            if (trie[cur].count(ctoi(board[ni][nj]))) {
                visited[ni][nj] = true;
                dfs(ni, nj, trie[cur][ctoi(board[ni][nj])], board);
                visited[ni][nj] = false;
            }
        }
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        init();
        for (int i = 0; i < words.size(); i++) {
            insert_word(words[i], i);
        }
        N = board.size();
        M = board[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!trie[0].count(ctoi(board[i][j]))) continue;
                visited[i][j] = true;
                dfs(i, j, trie[0][ctoi(board[i][j])], board);
                visited[i][j] = false;
            }
        }
        vector <string> r;
        for (auto i : ans) {
            r.push_back(words[i]);
        }
        return r;
    }
};

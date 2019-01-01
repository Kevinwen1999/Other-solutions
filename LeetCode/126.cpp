#define MAXN 100001
class Solution {
public:
    vector <int> adj[MAXN];
    int dist[MAXN];
    vector<vector<string>> ans;
    int st, ed;
    bool hasEdge(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    }
    vector<string> stack;
    void bfs(int st, int ed) {
        queue<int> q;
        q.push(st);
        memset(dist, -1, sizeof dist);
        dist[st] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == ed) continue;
            for (int i : adj[cur]) {
                if (dist[i] == -1) {
                    dist[i] = dist[cur] + 1;
                    q.push(i);
                }
            }
        }
    }
    void backtrack(int cur, vector<string>& wordList) {
        if (dist[cur] == 0) {
            reverse(stack.begin(), stack.end());
            ans.push_back(stack);
            reverse(stack.begin(), stack.end());
            return;
        }
        for (int i : adj[cur]) {
            if (dist[i] == dist[cur] - 1) {
                stack.push_back(wordList[i]);
                backtrack(i, wordList);
                stack.pop_back();
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        st = -1, ed = -1;
        int N = wordList.size();
        for (int i = 0; i < N; i++) {
            if (wordList[i] == beginWord) st = i;
            else if (wordList[i] == endWord) ed = i;
        }
        if (ed == -1) return ans;
        if (st == -1) {
            st = N++;
            wordList.push_back(beginWord);
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (hasEdge(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        bfs(st, ed);
        if (dist[ed] == -1) return ans;
        stack.push_back(endWord);
        backtrack(ed, wordList);
        return ans;
    }
};

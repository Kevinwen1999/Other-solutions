#define MAXN 60000
#define ALPHA 26
class Solution {
public:
    int sz = 0;
    unordered_map<int, int> trie[MAXN];
    bool value[MAXN];
    void insert(string& s) {
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!trie[cur].count(s[i] - 'a')) {
                trie[cur][s[i] - 'a'] = ++sz;
            }
            cur = trie[cur][s[i] - 'a'];
        }
        value[cur] = true;
    }
    int cat(string& s, int cur, int i) {
        if (i == s.size()) {
            return 0;
        }
        int ends = -1;
        for (; i < s.size(); i++) {
            if (!trie[cur].count(s[i] - 'a')) break;
            cur = trie[cur][s[i] - 'a'];
            if (value[cur]) {
                int temp = cat(s, 0, i + 1);
                if (temp != -1) {
                    if (ends == -1) ends = 0;
                    ends = temp + 1;
                    return ends;
                }
            }
        }
        return ends;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == 0) continue;
            insert(words[i]);
        }
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == 0) continue;
            if (cat(words[i], 0, 0) > 1)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};

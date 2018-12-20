#define ll long long
class Solution {
public:
    const ll prm = 7919;
    const ll mod = 1000000007;
    const int MAXN = 505;
    ll prec[505];
    ll calc_hash(string& input) {
        int ans = 0;
        for (int i = 0; i < input.size(); i++) {
            ans = ((ans * prm) % mod + (input[i] - 'a' + 1 + mod) % mod) % mod;
        }
        return ans;
    }
    int combine(vector<string>& words, vector<ll>& h1, int i, int j) {
        return (((h1[i] * prec[words[j].size()])% mod + h1[j]) % mod + mod) % mod;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<ll> hash1, hash2;
        vector<int> st[30], ed[30];
        prec[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            prec[i] = (prec[i - 1] * prm) % mod;
        }
        for (int i = 0; i < words.size(); i++) {
            hash1.push_back(calc_hash(words[i]));
            if (words[i].size() == 0) st[29].push_back(i);
            else st[words[i][0] - 'a'].push_back(i);
            reverse(words[i].begin(), words[i].end());
            if (words[i].size() != 0) ed[words[i][0] - 'a'].push_back(i);
            hash2.push_back(calc_hash(words[i]));
        }
        vector<vector<int>> ans;
        for (int c = 0; c < 30; c++) {
            if (c == 29) {
                for (int i : st[c]) {
                    for (int j = 0; j < words.size(); j++) {
                        if (i == j) continue;
                        if (combine(words, hash1, i, j) == combine(words, hash2, j, i)) {
                            vector<int> t; t.push_back(i); t.push_back(j);
                            ans.push_back(t);
                        }
                        if (combine(words, hash1, j, i) == combine(words, hash2, i, j)) {
                            vector<int> t; t.push_back(j); t.push_back(i);
                            ans.push_back(t);
                        }
                    }
                }
                continue;
            }
            for (int i : st[c]) {
                for (int j : ed[c]) {
                    if (i == j) continue;
                    if (combine(words, hash1, i, j) == combine(words, hash2, j, i)) {
                        vector<int> t; t.push_back(i); t.push_back(j);
                        ans.push_back(t);
                    }
                }
            }
        }
        return ans;
    }
};

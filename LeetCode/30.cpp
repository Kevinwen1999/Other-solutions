class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        int L = s.size(), N = words.size(), n = words[0].size();
        unordered_map<string, int> des;
        set<string> all;
        for (auto i : words) {
            des[i]++;
            all.insert(i);
        }
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> sw;
            int tot = 0;
            int st = i;
            int cnt1 = 0, cnt2 = 0;
            for (int j = i; j + n - 1 < L; j += n) {
                tot++;
                if (tot > N) {
                    string rm = s.substr(st, n);
                    sw[rm]--;
                    if (des[rm]) {
                        if (sw[rm] + 1 == des[rm]) {
                            cnt1 -= des[rm];
                        } else if (sw[rm] == des[rm]) {
                            cnt1 += des[rm];
                        }
                    } else {
                        cnt2--;
                    }
                    st += n;
                    tot--;
                }
                string rm = s.substr(j, n);
                sw[rm]++;
                if (des[rm]) {
                    if (sw[rm] - 1 == des[rm]) {
                        cnt1 -= des[rm];
                    } else if (sw[rm] == des[rm]) {
                        cnt1 += des[rm];
                    }
                } else {
                    cnt2++;
                }
                if (cnt1 == N && cnt2 == 0) {
                    ans.push_back(st);
                }
            }
        }
        return ans;
    }
};

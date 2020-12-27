class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> checknum;
        unordered_map<char, deque<int> > curpos;
        for (auto i : t) {
            if (checknum.count(i)) {
                checknum[i]++;
            } else {
                checknum[i] = 1;
                std::deque<int> first;
                curpos[i] = first;
            }
        }
        int reql = t.size(), N = s.size();
        int cntl = 0;
        deque<int> allpos;
        int MAX = 0x3f3f3f3f;
        int ans = MAX;
        string ansStr = "";
        for (int i = 0; i < N; i++) {
            char c = s[i];
            if (!checknum.count(c)) continue;
            if (cntl != reql && curpos[c].size() != checknum[c]) {
                allpos.push_back(i);
                curpos[c].push_back(i);
                cntl++;
            } else {
                curpos[c].pop_front();
                curpos[c].push_back(i);
                allpos.push_back(i);
                while (true) {
                    int idx = allpos.front();
                    char cc = s[idx];
                    if (curpos[cc].front() == idx) break;
                    allpos.pop_front();
                }
            }
            if (cntl == reql) {
                if(ans > i - allpos.front() + 1) {
                    ans = i - allpos.front() + 1;
                    ansStr = s.substr(allpos.front(), ans);
                }
            }
        }
        return ansStr;
    }
};

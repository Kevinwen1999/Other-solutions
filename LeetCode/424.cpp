class Solution {
public:
    int characterReplacement(string s, int k) {
        int L = 0, R = 0, N = s.size();
        int ans = 0;
        unordered_map<char, int> m;
        while (L < N && R < N) {
            char cur = s[R];
            if (m.count(cur) == 0) {
                m[cur] = 0;
            }
            m[cur]++;
            bool OK = false;
            for (char i = 'A'; i <= 'Z'; i++) {
                if (m.count(i) == 0) {
                    m[i] = 0;
                }
                if (m[i] + k >= R - L + 1) {
                    OK = true;
                    ans = max(ans, min(m[i] + k, R - L + 1));
                }
            }
            if (OK) {
                R++;
            } else {
                m[s[R]]--;
                m[s[L]]--;
                L++;
            }
        }
        return ans;
    }
};

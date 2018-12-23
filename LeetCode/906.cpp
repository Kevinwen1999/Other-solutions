#define ull unsigned long long
class Solution {
public:
    ull cnt = 0, l, r;
    void judge(string i) {
        ull cur = stoull(i);
        cur = cur * cur;
        if (cur > r || cur < l) return;
        string s = to_string(cur);
        bool ok = true;
        for (int i = 0; i <= s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i])
                ok = false;
        }
        if (ok)
            cnt++;
    }
    int superpalindromesInRange(string L, string R) {
        l = stoull(L), r = stoull(R);
        for (int i = 1; i < 10; i++) {
            string s = to_string(i);
            judge(s);
        }
        for (int i = 1; i < 10000; i++) {
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            for (int j = 0; j < 10; j++){
                string mid = to_string(j);
                judge(s + mid + t);
            }
            judge(s + t);
        }
        return cnt;
    }
};

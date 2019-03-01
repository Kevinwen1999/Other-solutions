class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> mono;
        bool in_stack[30] = {0};
        int cnt[30] = {0};
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a';
            
            if (in_stack[cur]) {
                cnt[cur]--;
                continue;
            }
            
            while (!mono.empty() && mono.back() > cur && cnt[mono.back()] > 1) {
                cnt[mono.back()]--;
                in_stack[mono.back()] = false;
                mono.pop_back();
            }
            
            mono.push_back(cur);
            in_stack[cur] = true;
        }
        
        string ans;
        for (auto i : mono) {
            ans += (char)(i + 'a');
        }
        return ans;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        for (int i = 1; i < n; i++) {
            string newans = "";
            
            for (int j = 0; j < ans.size(); j++) {
                int k = j;
                int cnt = 0;
                for (; k < ans.size() && ans[k] == ans[j]; k++) {
                    cnt++;
                }
                newans += to_string(cnt);
                newans += ans[j];
                j = k - 1;
            }
            
            ans = newans;
        }
        
        return ans;
    }
};

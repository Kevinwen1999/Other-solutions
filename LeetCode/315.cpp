#define MAXN 100000
class Solution {
public:
    
    int bit[MAXN];
    
    void update(int a) {
        for (; a < MAXN; a += (a & -a)) {
            bit[a]++;
        }
    }
    
    int query(int a) {
        int sum = 0;
        for (; a > 0; a -= (a & -a)) {
            sum += bit[a];
        }
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        
        unordered_map<int, int> um;
        vector<int> sn;
        for (int i : nums) {
            sn.push_back(i);
            sn.push_back(i - 1);
        }
        sort(sn.begin(), sn.end());
        sn.erase(unique(sn.begin(), sn.end()), sn.end());
        for (int i = 0; i < sn.size(); i++) {
            um[sn[i]] = i + 1;
        }
        
        vector <int> ans;
        
        for (int i = N - 1; i >= 0; i--) {
            ans.push_back(query(um[nums[i] - 1]));
            update(um[nums[i]]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

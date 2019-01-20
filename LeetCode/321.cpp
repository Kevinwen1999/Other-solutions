class Solution {
public:
    vector<int> maxList(vector<int>& num, int k) {
        vector<int> ans;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            while (!ans.empty()) {
                if ((ans.size() + (n - i - 1)) < k) break;
                if (ans.back() >= num[i]) break;
                ans.pop_back();
            }
            if (ans.size() < k) ans.push_back(num[i]);
        }
        return ans;
    }
    bool greater(vector<int>& n1, vector<int>& n2, int i1, int i2) {
        while (i1 < n1.size() && i2 < n2.size() && n1[i1] == n2[i2])
            i1++, i2++;
        return i1 == n1.size() || (i2 < n2.size() && n2[i2] > n1[i1]);
    }
    vector<int> max2List(vector<int> n1, vector<int> n2, int k) {
        vector<int> ans;
        int i1 = 0, i2 = 0;
        while (ans.size() < k) {
            ans.push_back(greater(n1, n2, i1, i2) ? n2[i2++] : n1[i1++]);
        }
        return ans;
    } 
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans, tmp;
        for (int i = 0; i <= k && i <= nums1.size(); i++) {
            if (k - i > nums2.size()) continue;
            tmp = max2List(maxList(nums1, i), maxList(nums2, k - i), k);
            if (greater(ans, tmp, 0, 0))
                ans = tmp;
        }   
        return ans;
    }
};

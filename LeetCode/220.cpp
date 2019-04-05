class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int N = nums.size();
        if (!N) return false;
        int st = 0;
        int ed = 0;
        multiset<long long> ms;
        ms.insert(nums[ed]);
        while (ed + 1 != N && ed - st < k) {
            ms.insert(1LL * nums[++ed]);
        }
        while (st < N) {
            ms.erase(ms.lower_bound(nums[st]));
            auto s = ms.lower_bound(1LL * nums[st] - t);
            if (s != ms.end()) {
                int a = *s;
                if (a <= 1LL* nums[st] + t) return true;
            }
            st++;
            if (ed + 1 != N) {
                ms.insert(1LL * nums[++ed]);
            }
        }
        
        return false;
    }
};

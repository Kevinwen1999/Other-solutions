int check(vector<int>& a, int req) { // can implement sliding window for this, too lazy
    int ans = 0;
    for (int i = 1; i < a.size(); i++) {
        int t = (a.size() - i) - (upper_bound(a.begin() + i, a.end(), a[i - 1] + req) - (a.begin() + i));
        ans += t;
    }
    return ans;
}
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int tot = (nums.size()) * (nums.size() - 1) / 2;
        sort(nums.begin(), nums.end());
        int l = 0, h = 1000000;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (tot - check(nums, mid) < k)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
};

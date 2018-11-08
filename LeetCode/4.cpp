class Solution {
public:
    int MAX = 0x3f3f3f3f;
    int after(int req, vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] <= req) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return nums.size() - l;
    }
    int judge (int req, vector<int>& nums1, vector<int>& nums2) {
        int l = 0, h = nums1.size() - 1;
        bool ok = false;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (after(nums1[mid], nums1) + after(nums1[mid], nums2) > req) {
                l = mid + 1;
            } else {
                ok = true;
                h = mid - 1;
            }
        }
        return ok ? l : -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tn = nums1.size() + nums2.size();
        if (nums1.size() < nums2.size()) swap(nums1, nums2);
        if (tn % 2) {
            int ans = judge(tn / 2, nums1, nums2), ans2 = judge(tn / 2, nums2, nums1);
            ans = (ans == -1) ? MAX : nums1[ans]; 
            ans2 = (ans2 == -1) ? MAX : nums2[ans2]; 
            return min(ans, ans2);
            
        } else {
            int ans = judge(tn / 2, nums1, nums2), ans2 = judge(tn / 2, nums2, nums1);
            ans = (ans == -1) ? MAX : nums1[ans]; 
            ans2 = (ans2 == -1) ? MAX : nums2[ans2]; 
            double fans = min(ans, ans2);
            ans = judge(tn / 2 - 1, nums1, nums2), ans2 = judge(tn / 2 - 1, nums2, nums1);
            ans = (ans == -1) ? MAX : nums1[ans]; 
            ans2 = (ans2 == -1) ? MAX : nums2[ans2]; 
            double lans = min(ans, ans2);
            return (fans + lans) * 0.5;
        }
    }
};

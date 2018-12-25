class Solution {
public:
    int temp[50010];
    int mergesort(vector<int>& nums, int l, int r) { 
        int mid, cnt = 0; 
        if (l < r) { 
            mid = (l + r) / 2; 
            cnt = mergesort(nums, l, mid); 
            cnt += mergesort(nums, mid + 1, r); 
            cnt += merge(nums, l, mid + 1, r); 
        }
        return cnt;
    }
    int merge(vector<int>& nums, int l, int mid, int r) {
        int i = l, j = mid, k = l, cnt = 0;
        while (i < mid && j <= r) {
            if (nums[i] <= 2LL * nums[j])
                i++;
            else { 
                cnt += mid - i;
                j++;
            }
        }
        i = l, j = mid;
        while (i < mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i < mid) {
            temp[k++] = nums[i++];
        }
        while (j <= r) {
            temp[k++] = nums[j++];
        }
        for (i = l; i <= r; i++) {
            nums[i] = temp[i];
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};

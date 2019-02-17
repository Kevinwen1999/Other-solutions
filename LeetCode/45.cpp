class Solution {
public:
    vector <int> mono;
    int jump(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) return 0;
        for (int i = N - 1; i >= 0; i--) {
            if (i == N - 1) {
                mono.push_back(i);
            }
            int last = -1;
            while (!mono.empty() && mono.back() - i <= nums[i]) {
                last = mono.back();
                mono.pop_back();
            }
            if (last != -1) mono.push_back(last);
            mono.push_back(i);
        }
        return mono.size() - 1;
    }
};

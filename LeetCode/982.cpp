class Solution {
public:
    int countTriplets(vector<int>& A) {
        int N = A.size();
        unordered_map<int, int> us;
        if (!N) return 0;
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                us[(A[i] & A[j])]++;
            }
        }
        for (int i = 0; i < N; i++) {
            for (auto j : us)
                if ((j.first & A[i]) == 0)
                    ans += j.second;
        }
        
        return ans;
    }
};

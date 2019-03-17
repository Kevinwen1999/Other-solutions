class Solution {
public:
    int findMinMoves(vector<int>& machines) { 
        int N = machines.size();
        int tot = 0;
        for (int i : machines) tot += i;
        if (tot % N) return -1;
        
        int need = tot / N;
        int last = 0;
        int ans = 0;
        
        for (int i = 0; i < N; i++) {
            int ta = 0;
            if (last < 0) ta -= last;
            int diff = machines[i] - need;
            last += diff;
            if (last > 0) ta += last;
            ans = max(ans, ta);
        }
        
        return ans;
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int N = timeSeries.size();
        int last = -1;
        int tot = 0;
        for (int i = 0; i < N; i++) {
            if (last == -1) {
                last = timeSeries[i] + duration - 1;
                tot += duration;
            } else {
                tot += -1 * max(0, last - timeSeries[i] + 1) + duration;
                last = timeSeries[i] + duration - 1;
            }
        }
        return tot;
    }
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int N = intervals.size();
        vector<Interval> ans;
        bool shit = false;
        for (int i = 0; i < N; i++) {
            auto cur = intervals[i];
            if (cur.end < newInterval.start) {
                ans.push_back(cur);
                continue;
            }
            if (cur.start > newInterval.end) {
                if (!shit) {
                    shit = true;
                    ans.push_back(newInterval);
                }
                ans.push_back(cur);
                continue;
            }
            shit = true;
            int sc = min(cur.start, newInterval.start);
            while (i < N && intervals[i].end < newInterval.end)
                i++;
            int ed;
            if (i == N) {
                ed = newInterval.end;
            }
            else if (newInterval.end >= intervals[i].start) {
                ed = intervals[i].end;
            } else {
                ed = newInterval.end;
                i--;
            }
            ans.push_back(Interval(sc, ed));
        }
        if (!shit) ans.push_back(newInterval);
        return ans;
    }
};

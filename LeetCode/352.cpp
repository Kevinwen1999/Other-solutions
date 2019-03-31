/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct cmp{
    bool operator() (const Interval &a, const Interval &b) const {
        return a.end < b.end;
    }
};
class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    vector <Interval> all;
    void addNum(int val) {
        Interval v(val, val);
        auto rt = lower_bound(all.begin(), all.end(), v, cmp());
        bool inserted = false;
        if (rt == all.end()) {
            rt = all.insert(rt, v);
            inserted = true;
        } else if (rt->start <= val + 1) {
            rt->start = (rt->start == val + 1) ? val : rt->start;
            inserted = true;
        }
        
        auto prev = rt;
        if (prev != all.begin()) {
            prev--;
            if (inserted) {
                if (rt->start == prev->end + 1) {
                    prev->end = rt->end;
                    all.erase(rt);
                }
            } else if (prev->end + 1 == val) {
                prev->end++;
            } else {
                all.insert(rt, v);
            }
        } else if (!inserted) {
            all.insert(rt, v);
        }
    }
    
    vector<Interval> getIntervals() {
        return all;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */

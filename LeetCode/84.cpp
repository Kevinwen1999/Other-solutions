#define ull unsigned long long
class node {
public:
    int h;
    int lidx;
} t;
bool operator< (const node &a, const node &b) {
    return a.h < b.h;
}
class Solution {
public:
    ull largestRectangleArea(vector<int>& heights) {
        priority_queue <node> pq;
        int N = heights.size();
        ull ans = 0;
        for (int i = 0; i < N; i++) {
            int lidx = i;
            while (!pq.empty() && pq.top().h >= heights[i]) {
                t = pq.top();
                pq.pop();
                ans = max(ans, 1ULL * t.h * (i - t.lidx));
                lidx = t.lidx;
            }
            pq.push((node){heights[i], lidx});
        }
        while (!pq.empty()) {
            t = pq.top();
            pq.pop();
            ans = max(ans, 1ULL * t.h * (N - t.lidx));
        }
        return ans;
    }
};

class node {
public:
    int p;
    int c;
};
bool operator< (const node &a, const node &b) {
    return a.c  < b.c;
}
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int N = Profits.size();
        vector <node> all;
        
        for (int i = 0; i < N; i++) {
            all.push_back({Profits[i], Capital[i]});
        }
        
        sort(all.begin(), all.end());
        priority_queue<int> pq;
        int tot = W;
        int last = -1;
        int idx = 0;
        while (k) {
            if (tot != last) {
                while (idx < N && all[idx].c <= tot) {
                    pq.push(all[idx++].p);
                }
                last = tot;
            }
            if (!pq.empty()) {
                tot += pq.top();
                pq.pop();
            }
            k--;
        }
        
        return tot;
    }
};

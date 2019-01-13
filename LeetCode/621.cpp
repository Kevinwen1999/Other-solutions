int cnt[26] = {0};
class node {
public:
    int idx;
} t;
bool operator< (const node &a, const node &b) {
    return cnt[a.idx] < cnt[b.idx];
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue <node> pq;
        int N = tasks.size();
        for (auto i : tasks) {
            cnt[i - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                pq.push((node){i});
            }
        }
        int tot = 0;
        while (N) {
            vector <node> hold;
            node mx = pq.top();
            pq.pop();
            N--;
            cnt[mx.idx]--;
            tot++;
            if (cnt[mx.idx]) hold.push_back(mx);
            for (int i = 0; i < n; i++) {
                if (!N) break;
                tot++;
                if (pq.empty()) continue;
                node mx = pq.top();
                pq.pop();
                N--;
                cnt[mx.idx]--;
                if (cnt[mx.idx]) hold.push_back(mx);
            }
            for (auto i : hold)
                pq.push(i);
        }
        return tot;
    }
};

#define ll long long
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        ll prefix[50001] = {0};
        int N = A.size();
        for (int i = 1; i <= N; i++) {
            prefix[i] = prefix[i - 1] + A[i - 1];
        }
        int ans = 50010;
        deque<int> mq;
        for (int i = 0; i <= N; i++) {
            while (!mq.empty() && prefix[mq.back()] >= prefix[i])
                mq.pop_back();
            while (!mq.empty() && prefix[i] - prefix[mq.front()] >= K)
                ans = min(ans, i - mq.front()), mq.pop_front();
            mq.push_back(i);
        }
        return ans == 50010 ? -1 : ans;
    }
};

#define MAXN INT_MAX
#define MAXL 102
class Solution {
public:
    int dp[MAXL], dp1[MAXL];
    int N, M;
    int last_char[MAXL];
    int llen = 0;
    
    int get_dist(int i, int j) {
        int ans = MAXN;
        if (j < i) swap(j, i);
        ans = j - i;
        ans = min(ans, i + M - j);
        return ans;
    }
    void process_last(char tar, string &ring) {
        llen = 0;
        int first_seen = MAXN, last_seen = -1;
        for (int j = 0; j < M; j++) {
            if (ring[j] != tar) continue;
            first_seen = min(first_seen, j);
            last_seen = max(last_seen, j);
        }
        last_char[llen++] = last_seen;
        for (int j = 0; j < M; j++) {
            if (ring[j] == tar)
                last_char[llen++] = j;
        }
        last_char[llen++] = first_seen;
    }
    
    int findRotateSteps(string ring, string key) {
        N = key.size(), M = ring.size();
        if (!N) return 0;
        
        for (int i = 0; i < M; i++) {
            dp[i] = MAXN;
            if (ring[i] == key[0]) {
                dp[i] = min(i, M - i);
            }
        }
        process_last(key[0], ring);
        
        for (int i = 1; i < N; i++) {
            int closest_before = 1, closest_after = 1;
            for (int j = 0; j < M; j++) {
                dp1[j] = MAXN;
                if (ring[j] != key[i]) continue;
                while (closest_after < llen - 1 && last_char[closest_after] < j) {
                    closest_after++;
                }
                int t = last_char[closest_after - 1];
                dp1[j] = dp[t] + get_dist(t, j);
                t = last_char[closest_after];
                dp1[j] = min(dp1[j], dp[t] + get_dist(j, t));
            }
            
            process_last(key[i], ring);
            
            swap(dp, dp1);
        }
        
        int ans = MAXN;
        
        for (int i = 0; i < M; i++) {
            ans = min(ans, dp[i]);
        }
        
        return ans + N;
    }
};

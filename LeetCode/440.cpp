typedef long long ll;
class Solution {
public:
    int getcnt(int n, int ans) {
        int cnt = 0;
        ll fac = 1;
        while (1) {
            ll low = ans * fac;
            ll high = ans * fac + (fac - 1);
            if (low > n) break;
            if (low <= n && high >= n) {
                cnt += n - low + 1;
                break;
            } else {
                cnt += fac;
                fac *= 10;
            }
        }
        return cnt;
    }
    ll findnext(int n, int k, ll ans) {
        if (k) {
            for (int i = ans ? 0 : 1; i < 10; i++) {
                int cnt = getcnt(n, ans * 10 + i);
                if (k <= cnt) return findnext(n, k - 1, ans * 10 + i);
                k -= cnt;
            }
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        return findnext(n, k, 0);
    }
};

class Solution {
public:
    int check(int m, int n, int val) {
        int i = m, j = 1;
        int cnt = 0;
        while (i > 0 && j <= n) {
            if (i * j <= val)
                cnt += i, j++;
            else
                i--;
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, h = m * n;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(m, n, mid) < k) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }
};

#define ull unsigned long long
class Solution {
public:
    ull pow(ull a, int b) {
        return !b ? 1ULL : a * pow(a, b - 1);
    }
    ull make_palin(ull n) {
        int cnt = 0;
        ull add = 0, tmp = n;
        while (tmp) {
            add = add * 10 + (tmp % 10);
            cnt++;
            tmp /= 10;
        }
        return n * pow(10ULL, cnt) + add;
    }
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        for (ull i = pow(10ULL, n) - 1; i >= pow(10ULL, n - 1); i--) {
            ull pa = make_palin(i);
            for (ull j = pow(10ULL, n) - 1; j * j >= pa; j--) {
                if (pa % j == 0) {
                    return pa % 1337;
                }
            }
        }
        return 0;
    }
};

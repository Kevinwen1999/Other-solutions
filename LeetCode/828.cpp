class Solution {
public:
    int uniqueLetterString(string S) {
        int N = S.size();
        if (N == 0) {
            return 0;
        }
        long long MOD = 1e9 + 7;
        int leftmost[30][10010];
        int rightmost[30][10010];
        for (char i = 'A'; i <= 'Z'; i++) {
            leftmost[i - 'A'][0] = -1;
            for (int j = 1; j < N; j++) {
               leftmost[i - 'A'][j] = (S[j - 1] == i) ? j - 1 : leftmost[i - 'A'][j - 1];
            }
            rightmost[i - 'A'][N - 1] = N;
            for (int j = N - 2; j >= 0; j--) {
               rightmost[i - 'A'][j] = (S[j + 1] == i) ? j + 1 : rightmost[i - 'A'][j + 1];
            }
        }
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int lm = i - leftmost[S[i] - 'A'][i];
            int rm = rightmost[S[i] - 'A'][i] - i;
            ans = (ans + ((lm * rm) % MOD)) % MOD;
        }
        return ans;
    }
};

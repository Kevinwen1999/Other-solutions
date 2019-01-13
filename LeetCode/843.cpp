/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int sdiff (string a, string b) {
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            cnt += (a[i] == b[i]) ? 1 : 0;
        }
        return cnt;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int N = wordlist.size();
        swap(wordlist[0], wordlist[N - 1]);
        bool invalid[101] = {0};
        for (int i = 0; i < N; i++) {
            if (invalid[i]) {
                continue;
            }
            int g = master.guess(wordlist[i]);
            for (int j = i + 1; j < N; j++) {
                if (sdiff(wordlist[i], wordlist[j]) != g) {
                    invalid[j] = true;
                }
            }
        }
    }
};

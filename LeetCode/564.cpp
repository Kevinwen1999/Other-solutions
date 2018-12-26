#define ull unsigned long long
class Solution {
public:
    bool smaller(string a, string b) {
        if (a.size() < b.size()) return true;
        if (a.size() > b.size()) return false;
        else return a < b;
    }
    ull calc(string &ans, ull maxans, string n, string nn) {
        ull diff = smaller(n, nn) ? (stoull(nn) - stoull(n)) : (stoull(n) - stoull(nn));
        if (diff < maxans || maxans == -1) {
            ans = nn;
            return diff;
        } else {
            return maxans;
        }
    }
    string sub1(string n) {
        return to_string(stoull(n) - 1);
    }
    string add1(string n) {
        return to_string(stoull(n) + 1);
    }
    string nearestPalindromic(string n) {
        int N = n.size();
        if (N == 1) return sub1(n);
        bool ispa = true;
        for (int i = 0; i < N; i++) {
            if (n[i] != n[N - 1 - i])
                ispa = false;
        }
        ull mindiff = -1;
        string ans = n;
        string tn = "";
        for (int i = 0; i < N - 1; i++)
            tn += "9";
        mindiff = calc(ans, mindiff, n, tn);
        tn = "1";
        for (int i = 0; i < N - 1; i++) {
            tn += "0";
        }
        tn += "1";
        mindiff = calc(ans, mindiff, n, tn);
        if (ispa) {
            if (N % 2) {
                int idx = N / 2;
                tn = n;
                if (tn[idx] == '0') {
                    tn[idx] = '1';
                } else {
                    tn[idx] --;
                }
                mindiff = calc(ans, mindiff, n, tn);
                return ans;
            } else {
                int idx1 = N / 2, idx2 = idx1 - 1;
                tn = n;
                if (tn[idx1] == '0') {
                    tn[idx1] = tn[idx2] = '1';
                } else {
                    tn[idx1] --, tn[idx2]--;
                }
                mindiff = calc(ans, mindiff, n, tn);
                return ans;
            }
        }
        string fh = n.substr(0, N / 2 + (N % 2 ? 1 : 0));
        string lh = n.substr((N - 1) / 2 + 1);
        if (sub1(fh).size() == fh.size() && sub1(fh) != "0") {
            string nfh = sub1(fh);
            reverse(nfh.begin(), nfh.end());
            if (N % 2 && nfh.size() != 1) nfh = nfh.substr(1);
            mindiff = calc(ans, mindiff, n, sub1(fh) + nfh);
        }
        tn = n;
        for (int i = 0; i < N; i++) {
            if (tn[i] != tn[N - 1 - i])
                tn[N - 1 - i] = tn[i];
        }
        mindiff = calc(ans, mindiff, n, tn);
        if (add1(fh).size() == fh.size()) {
            string nfh = add1(fh);
            reverse(nfh.begin(), nfh.end());
            if (N % 2 && nfh.size() != 1) nfh = nfh.substr(1);
            mindiff = calc(ans, mindiff, n, add1(fh) + nfh);
        }
        return ans; 
    }
};  

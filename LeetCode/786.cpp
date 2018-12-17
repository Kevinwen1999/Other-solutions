class node {
public:
    int p;
    int q;
    long double frac;
} f;
bool operator< (const node &a, const node &b) {
        return a.frac > b.frac;
    }
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<node> shit;
        for (int i = 1; i < A.size(); i++) {
            shit.push((node){0, i, ((long double)A[0] / (long double)A[i])}); // push in all 1 / q
        }
        while (K--){
            f = shit.top();
            shit.pop();
            if (f.p < A.size() - 1)
                shit.push((node){f.p + 1, f.q, ((long double)A[f.p + 1] / (long double)A[f.q])}); // push in p + 1 / q
        }
        vector<int> ans; ans.push_back(A[f.p]); ans.push_back(A[f.q]);
        return ans;
    }
};

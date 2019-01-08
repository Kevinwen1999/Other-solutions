#define ll long long
#define MAXN 100010
class Solution {
public:
    bitset <MAXN> bs;
    vector<int> primes;
    // Sieve of E
    void sieve(ll upper) {
        bs.set();
        bs[0] = bs[1] = false;
        for (ll i = 2; i <= upper; i++)
            if (bs[i]) {
                for (ll j = i*i; j < upper; j+=i)
                    bs[j] = 0;
                primes.push_back((int)i);
            }
    }
    vector<int> primefactors(ll N) {
        vector<int> factors;
        ll idx = 0, PF = primes[idx];
        while (PF * PF <= N) {
            while (N % PF ==0) {
                N /= PF;
                factors.push_back(PF);
            }
            PF = primes[++idx];
        }
        if (N != 1) factors.push_back(N);
        return factors;
    }
    int p[MAXN], rnk[MAXN];
    void init(int N) {
        for (int i = 0; i <= N; i++)
            p[i] = i, rnk[i] = 1;
    }
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    bool sameset(int x, int y) {
        return findp(x) == findp(y);
    }
    void mergeset(int x, int y) {
        if (!sameset(x, y)) {
            x = findp(x), y = findp(y);
            if (rnk[x] > rnk[y])
                rnk[x] += rnk[y], p[y] = x;
            else
                rnk[y] += rnk[x], p[x] = y;
        }
    }
    int largestComponentSize(vector<int>& A) {
        int N = A.size();
        sieve(100000);
        init(100000);
        for (int i = 0; i < N; i++) {
            vector <int> pf = primefactors(A[i]);
            for (int i = 1; i < pf.size(); i++) {
                mergeset(pf[i], pf[i - 1]);
            }
        }
        map<int, int> mp;
        for (int i = 0; i < N; i++) {
            if (A[i] == 1) continue;
            vector <int> pf = primefactors(A[i]);
            mp[findp(pf[0])]++;
        }
        int maxx = 0;
        for (auto i : mp) {
            maxx = max(maxx, i.second);
        }
        return maxx;
    }
};

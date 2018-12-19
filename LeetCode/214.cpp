#define ll long long
#define MOD 1000000007
#define MAXN 40010
#define prm 307

class Solution {
public:
    ll x, y, d;
    ll f1[MAXN], f2[MAXN];
    ll prex[MAXN];
    ll e[MAXN];
    int N;
    void extendedeuclid(ll a, ll b, ll &x, ll &y, ll &d) {
        if (!b) {x = 1; y = 0; d = a; return;}
        extendedeuclid(b, a % b, x, y, d);
        ll x1 = y;
        ll y1 = x - (a/b)*y;
        x = x1;
        y = y1;
    }
    void precalc_exponents() {
        memset(e, -1, sizeof e);
        prex[0] = 1;
        extendedeuclid(MOD, 1, x, y, d);
        for (int i = 1; i < MAXN; i++) {
            prex[i] = (prex[i - 1] * prm) % MOD;
        }
    }
    void hash_string(string& in, ll F[], int p) {
        for (int i = 0; i < in.size(); i++) {
            F[i] = (((in[i] - 'a' + 1) % MOD) * (prex[i] % MOD)) % MOD;
            if (i) F[i] = (F[i] + F[i - 1]) % MOD;
        }
    }
    ll query_hash(ll F[], int p, int i, int j) {
        ll val = F[j] - (i ? F[i - 1] : 0);
        val %= MOD;
        if (e[i] == -1) {
            extendedeuclid(MOD, prex[i] % MOD, x, y, d);
            e[i] = y;
        } 
        y = e[i];
        y %= MOD;
        val = (val * y) % MOD;
        return (val + MOD) % MOD;
    }

    string shortestPalindrome(string s) {
        precalc_exponents();
        hash_string(s, f1, prm);
        string rs = s;
        reverse(rs.begin(), rs.end());
        hash_string(rs, f2, prm);
        int n = s.size() - 1;
        for (int i = 0; i <= n; i++) {
            if (query_hash(f1, prm, 0, n - i) == query_hash(f2, prm, i, n)) {
                //cout << i << "\n";
                string aft = s.substr(n - i + 1);
                reverse(aft.begin(), aft.end());
                return aft = aft + s; 
            }
        }
        return s;
    }
};

#define MAXN 10000
#define ll long long
class Solution {
public:
    int bit[MAXN] = {0};
    void update(int x, int v) {
        for (;x < MAXN; x += (x & -x))
            bit[x] += v;
    }
    int query(int a) {
        int sum = 0;
        for (; a > 0; a -= (a & -a))
            sum += bit[a];
        return sum;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll cur_p = 0;
        int ans = 0;
        
        vector<ll> alln;
        alln.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            cur_p += nums[i];
            alln.push_back(cur_p);
            alln.push_back(cur_p - lower);
            alln.push_back(cur_p - upper - 1);
        }
        
        sort(alln.begin(), alln.end());
        alln.erase(unique(alln.begin(), alln.end()), alln.end());
        
        unordered_map<ll, int> mp;
        
        for (int i = 0; i < alln.size(); i++) {
            mp[alln[i]] = i + 1;
        }
        
        cur_p = 0;
        update(mp[0], 1);
        for (int i = 0; i < nums.size(); i++) {
            cur_p += nums[i];
            int uidx = query(mp[cur_p - lower]);
            int lidx = query(mp[cur_p - upper - 1]);
            ans += uidx - lidx;
            update(mp[cur_p], 1);
        }
        
        return ans;
    }
};

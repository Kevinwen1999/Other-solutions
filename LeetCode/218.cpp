#define MAXN 10010
class Solution {
public:
    vector <int> points;
    unordered_map <int, int> ump;
    int node[8 * MAXN];
    int lazy[8 * MAXN];
    int ql, qr, v;
    void update(int stidx, int L, int R) {
        if (lazy[stidx] != -1) {
            node[stidx] = max(node[stidx], lazy[stidx]);
            if (L != R) {
                lazy[stidx << 1] = max(lazy[stidx], lazy[stidx << 1]);
                lazy[stidx << 1 | 1] = max(lazy[stidx], lazy[stidx << 1 | 1]);
            }
            lazy[stidx] = -1;
        }
        if (L > R || L > qr || R < ql) return;
        if (ql <= L && R <= qr) {
            node[stidx] = max(node[stidx], v);
            if (L != R) {
                lazy[stidx << 1] = max(lazy[stidx << 1], v);
                lazy[stidx << 1 | 1] = max(lazy[stidx << 1 | 1], v);
            }
            return;
        }
        int mid = (L + R) / 2;
        update(stidx << 1, L, mid);
        update(stidx << 1 | 1, mid + 1, R);
        node[stidx] = max(node[stidx << 1], node[stidx << 1 | 1]);
    }
    int query(int stidx, int L, int R) {
        if (lazy[stidx] != -1) {
            node[stidx] = max(node[stidx], lazy[stidx]);
            if (L != R) {
                lazy[stidx << 1] = max(lazy[stidx], lazy[stidx << 1]);
                lazy[stidx << 1 | 1] = max(lazy[stidx], lazy[stidx << 1 | 1]);
            }
            lazy[stidx] = -1;
        }
        if (L > R || L > qr || R < ql) return -1;
        if (ql <= L && R <= qr) {
            return node[stidx];
        }
        int mid = (L + R) / 2;
        return max(query(stidx << 1, L, mid), query(stidx << 1 | 1, mid + 1, R));
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        memset(lazy, -1, sizeof lazy);
        vector<pair<int, int>> ans;
        for (auto i : buildings) {
            points.push_back(i[0]);
            points.push_back(i[1]);
        }
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        int tmp = 0;
        for (auto i : points) {
            ump[i] = tmp++;
        }
        for (auto i : buildings) {
            ql = ump[i[0]], qr = ump[i[1]] - 1, v = i[2];
            update(1, 0, tmp - 1);
        }
        int cm = -1;
        for (auto i : points) {
            ql = ump[i], qr = ump[i];
            int cur = query(1, 0, tmp - 1);
            if (cur != cm) {
                cm = cur;
                ans.push_back({i, cur});
            }
        }
        return ans;
    }
};

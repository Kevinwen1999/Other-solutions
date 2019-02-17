#define MAXN 20000
struct rect {
    int x;
    int yup;
    int ydown;
    int t;
};
bool cmp(rect &a, rect &b) {
    return a.x < b.x;
}
class Solution {
public:
    int val[MAXN];
    vector <int> ycord;
    vector <rect> allr;
    unordered_map<int, int> yhash;
    int cnt = 0;
    void process_rect(rect &cur) {
        for (int i = yhash[cur.ydown]; i < yhash[cur.yup]; i++) {
            val[i] += cur.t;
        }
    }
    bool check() {
        bool ans = true;
        for (int i = 0; i < cnt - 1; i++) {
            if (val[i] != 1)
                ans = false;
        }
        return ans;
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        for (auto i : rectangles) {
            ycord.push_back(i[1]);
            ycord.push_back(i[3]);
            allr.push_back((rect){i[0], i[3], i[1], 1});
            allr.push_back((rect){i[2], i[3], i[1], -1});
        }
        sort(allr.begin(), allr.end(), cmp);
        sort(ycord.begin(), ycord.end());
        ycord.erase(unique(ycord.begin(), ycord.end()), ycord.end());
        for (cnt; cnt < ycord.size(); cnt++) {
            yhash[ycord[cnt]] = cnt;
        }
        int lastx = allr[0].x;
        int i = 0;
        bool ans = true;
        while (true) {
            while (i < allr.size() && allr[i].x == lastx) {
                process_rect(allr[i]);
                i++;
            }
            if (i == allr.size()) break;
            ans = ans && check();
            lastx = allr[i].x;
        }
        return ans;
    }
};

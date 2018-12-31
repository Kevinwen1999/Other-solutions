/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
    int maxPoints(vector<Point>& points) {
        int N = points.size();
        if (!N) return 0;
        int ans = 1;
        int hp = 0, vp = 0;
        for (int i = 0; i < N; i++) {
            int tans = 1;
            int tmp = 0;
            map<pair <int, int>, set <int> > um;
            for (int j = i + 1; j < N; j++) {
                int y = points[i].y - points[j].y;
                int x = points[i].x - points[j].x;
                if (x == 0 && y == 0) tmp++;
                else if (y == 0) um[{1, 0}].insert(i), um[{1, 0}].insert(j);
                else if (x == 0) um[{0, 0}].insert(i), um[{0, 0}].insert(j);
                else {
                    int d = gcd(x, y);
                    x = x / d, y = y / d;
                    um[{x, y}].insert(i), um[{x, y}].insert(j);
                }
            }
            for (auto i : um) {
                tans = max(tans, (int)i.second.size() + tmp);
            }
            tans = max(tans, (int)um[{1, 0}].size() + tmp);
            tans = max(tans, (int)um[{0, 0}].size() + tmp);
            tans = max(tans, 1 + tmp);
            ans = max(ans, tans);
        }
        return ans;
    }
};

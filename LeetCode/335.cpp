class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int N = x.size();
        if (x.size() < 4) return false;
        for (int i = 3; i < N; i++) {
            if (x[i - 1] <= x[i - 3] && x[i] >= x[i - 2]) {
                cout << "fuck " << i << " 1 \n";
                return true;
            }
            if (i >= 4 && x[i - 1] == x[i - 3] && (x[i - 2] - x[i - 4]) >= 0 && x[i] >= (x[i - 2] - x[i - 4])) {
                cout << "fuck " << i << " 2 \n";
                return true;
            }
            if (i >= 5 && (x[i - 2] - x[i - 4]) >= 0 && x[i] >= (x[i - 2] - x[i - 4]) && x[i - 1] <= x[i - 3] && (x[i - 3] - x[i - 5]) >= 0 && x[i - 1] >= (x[i - 3] - x[i - 5])) {
                cout << "fuck " << i << " 3 \n";
                return true;
            }
        }
        return false;
    }
};

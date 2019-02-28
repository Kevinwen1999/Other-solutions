class Solution {
public:
    vector<string> ops;
    vector<string> output;
    vector <int> result;
    int calculate(string s) {
        int i = 0;
        while (i < s.size()) {
            int numbuff = -1;
            while (i < s.size() && isdigit(s[i])) {
                if (numbuff == -1) numbuff = 0;
                numbuff = numbuff * 10 + (s[i] - '0');
                i++;
            }
            if (numbuff != -1) output.push_back(to_string(numbuff));
            if (i == s.size()) break;
            string op;
            op = s[i];
            if (op == " ") {
                i++;
                continue;
            }
            if (op == "(") {
                ops.push_back(op);
            } else if (op == ")") {
                while (ops.back() != "(") {
                    output.push_back(ops.back());
                    ops.pop_back();
                }
                ops.pop_back();
            } else {
                while (!ops.empty() && ops.back() == "-") {
                    output.push_back(ops.back());
                    ops.pop_back();
                }
                ops.push_back(op);
            }
            i++;
        }
        while (!ops.empty()) {
            output.push_back(ops.back());
            ops.pop_back();
        }
        for (auto i : output) {
            if (i == "+" || i == "-") {
                int a = result.back();
                result.pop_back();
                int b = result.back();
                result.pop_back();
                if (i == "+") {
                    result.push_back(b + a);
                } else {
                    result.push_back(b - a);
                }
            } else {
                result.push_back(stoi(i));
            }
        }
        return result[0];
    }
};

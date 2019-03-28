class Solution {
public:
    
    string combine(string in) {
        string tmp = "";
        for (int i = 0; i < in.size(); i++) {
            int cnt = 1;
            int j = i + 1;
            for (; j < in.size(); j++) {
                if (in[i] == in[j]) cnt++;
                else break;
            } 
            if (cnt >= 3) {
                i = j - 1;
            } else {
                tmp += in[i];
            }
        }
        
        if (tmp == in) {
            return tmp;
        } else {
            return combine(tmp);
        }
    }
    
    int bfs(string board, string hand) {
        map<pair<string, string>, int> vis;
        vis[{board, hand}] = 0;
        queue<pair<string, string>> buff;
        buff.push({board, hand});
        
        while(!buff.empty()) {
            pair<string, string> top = buff.front();
            buff.pop();
            
            if (top.first == "") {
                return vis[top];
            }
            if (top.second == "") {
                continue;
            }
            
            
            for (int i = 0; i < top.second.size(); i++) {
                char cur = top.second[i];
                for (int j = 0; j < top.first.size(); j++) {
                    if (cur != top.first[j]) continue;
                    string nfirst = top.first.substr(0, j) + cur + top.first.substr(j);
                    nfirst = combine(nfirst);
                    string nsecond = top.second;
                    nsecond.erase(i, 1);
                    if (!vis.count({nfirst, nsecond})) {
                        vis[{nfirst, nsecond}] = vis[top] + 1;
                        buff.push({nfirst, nsecond});
                    }
                }
            }
        }

        return -1;
    }
    
    int findMinStep(string board, string hand) {
        return bfs(board, hand);
    }
};

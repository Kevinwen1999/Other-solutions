#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int K;
int dist[MAXN];
deque <int> dq;
int main() {
	cin >> K;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	dq.push_back(1);
	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		int n1 = (cur + 1) % K, n2 = (cur * 10) % K;
		if (dist[cur] + 1 < dist[n1]) {
			dist[n1] = dist[cur]  + 1;
			dq.push_back(n1);
		}	
		if (dist[cur] < dist[n2]) {
			dist[n2] = dist[cur];
			dq.push_front(n2);
		}
	}
	cout << dist[0] + 1 << "\n";
} 

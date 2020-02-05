#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 101
#define INF 1000000000
using namespace std;
typedef long long ll;

struct BUS {
	int t, p, n;
};

int n, m, v, t;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<BUS> q; //정차줄
	cin >> n >> m;//뒤 n ~ 1 앞 큐 추월 금지 정차시간 끝나고 떠남 앞에가 안가면 못감.
	//가장 앞쪽에 정차 못 들어가면 큐에 쌓임. 시간이 되는순간 다 빠져나가고 그다음 정차
	for (int i = 0; i < m; i++) {
		int t, p;
		cin >> t >> p;
		q.push({ t,p,i });
	}
	int time = 0;
	queue<BUS> st;
	while (++time) {
		while (!st.empty()) {
			BUS bus = st.front();
			if (bus.p + bus.t <= time)
				st.pop();
			else
				break;
		}

		while (st.size() < n && !q.empty()) {
			int t = q.front().t;
			int p = q.front().p;
			if (!st.empty())
				if (n - st.back().n <= 0) break;
			if (t <= time) {
				int idx;
				if (!st.empty())
					idx = st.back().n + 1;
				else
					idx = 1;
				st.push({ time,p,idx });
				q.pop();
				m--;
				if (m == 0) {
					cout << idx << '\n';
					return 0;
				}
			}
			else {
				break;
			}
		}

	}
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 100001;
const int INF = 2147400000;
bool visit[MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans, cnt;

queue<int> q;

void bfs() {
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int x = q.front();
			q.pop();
			if (x == k)
				return;

			int nx = x + 1;
			if (nx > MAX) continue;
			if (visit[nx] == false) {
				visit[nx] = true;
				q.push(nx);
			}
			nx = x - 1;
			if (nx < 0) continue;
			if (visit[nx] == false) {
				visit[nx] = true;
				q.push(nx);
			}
			nx = 2 * x;
			if (nx > MAX) continue;
			if (visit[nx] == false) {
				visit[nx] = true;
				q.push(nx);
			}
		}
		cnt++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	q.push(n);
	bfs();

	cout << cnt << '\n';
	return 0;
}
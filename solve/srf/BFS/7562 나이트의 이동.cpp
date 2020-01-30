#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 301;
const int INF = 2147000000;
bool visit[MAX][MAX];

int dr[] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int t;
int n, m, p, k, l, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> n;
		DATA st, des;
		cin >> st.x >> st.y;
		cin >> des.x >> des.y;
		queue<DATA> q;
		q.push(st);
		visit[st.x][st.y] = true;
		while (!q.empty()) {
			bool flag = false;
			int qs = q.size();
			while (qs--) {
				int x = q.front().x;
				int y = q.front().y;
				q.pop();
				if (x == des.x && y == des.y) {
					flag = true;
					cout << cnt << '\n';
					break;
				}

				for (int i = 0; i < 8; i++) {
					int nx = x + dr[i];
					int ny = y + dc[i];
					if (nx <0 || nx>=n || ny<0 || ny>=n) continue;
					if (visit[nx][ny] == false) {
						visit[nx][ny] = true;
						q.push({ nx,ny});
					}
				}
			}
			if (flag)
				break;
			cnt++;
		}
		memset(visit, false, sizeof(visit));
	}

	return 0;
}
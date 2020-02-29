#include <iostream>
#include <queue>
#define ll long long
using namespace std;

const int MAX = 501;
const int INF = 2147000000;
char a[MAX][MAX];
bool ch[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
struct point {
	int x, y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	point() {
	}
};

int t;
int n, m, k, l, ans;
int pr, pc;
pair<char,int> bfs(int r, int c, int dir) {
	int cnt = 0;
	queue<point> q;
	q.push({ r,c });
	int ndir = dir;
	while (!q.empty()) {
		if (cnt >= 250000) {
			cnt = INF;
			break;
		}
		cnt++;
		r = q.front().x;
		c = q.front().y;
		q.pop();
		int nr = r + dr[ndir];
		int nc = c + dc[ndir];
		if (0 <= nr && nr < n && 0 <= nc && nc < m) {
			if(a[nr][nc]=='.')
				q.push({ nr,nc });
			else if (a[nr][nc] == '/') {
				switch (ndir) {
				case 0:
					ndir = 1;
					break;
				case 1:
					ndir = 0;
					break;
				case 2:
					ndir = 3;
					break;
				case 3:
					ndir = 2;
					break;
				}
				q.push({ nr,nc });
			}
			else if (a[nr][nc] == '\\') {
				switch (ndir) {
				case 0:
					ndir = 3;
					break;
				case 1:
					ndir = 2;
					break;
				case 2:
					ndir = 1;
					break;
				case 3:
					ndir = 0;
					break;
				}
				q.push({ nr,nc });
			}
			else if (a[nr][nc] == 'C') {
				break;
			}
		}
		else {
			break;
		}
	}
	return { dir, cnt };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> pr >> pc;
	pair<int, int> max = { 0,0 };
	for (int i = 0; i < 4; i++) {
		pair<int, int> ans = bfs(pr - 1, pc - 1, i);
		max = max.second >= ans.second ? max : ans;
	}
	switch (max.first) {
	case 0:
		cout << "U\n";
		break;
	case 1:
		cout << "R\n";
		break;
	case 2:
		cout << "D\n";
		break;
	case 3:
		cout << "L\n";
		break;
	}
	if (max.second == INF)
		cout << "Voyager\n";
	else
		cout << max.second << '\n';
	return 0;
}
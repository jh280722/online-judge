#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1001;
const int INF = 2147000000;
char a[MAX][MAX];
bool ch[MAX][MAX];
int pn[10];
int s[10];

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
int n, m, p, k, l, ans;
int pr, pc;
queue<point> q;
void bfs() {
	while (!q.empty()) {
		int r = q.front().x;
		int c = q.front().y;
		int si = s[a[r][c] - '1'];
		pn[a[r][c] - '1']++;
		q.pop();
		for (int dis = 1; dis <= si; dis++) {
			for (int i = 0; i < 4; i++) {
				int nr = r + dis * dr[i];
				int nc = c + dis * dc[i];
				if (0 <= nr && nr < n && 0 <= nc && nc < m) {
					if (a[nr][nc] == '.' && ch[nr][nc] == false) {
						a[nr][nc] = a[r][c];
						ch[nr][nc] = true;
						q.push({ nr,nc });
					}
				}
			}
		}
	}
}

void insertq(char pnum) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == pnum && ch[i][j] == false) {
				q.push({ i, j });
				ch[i][j] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> p;

	for (int i = 0; i < p; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < p; i++) {
		insertq(i + '1');
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}

	for (int i = 0; i < p; i++) {
		cout << pn[i] << ' ';
	}
	return 0;
}
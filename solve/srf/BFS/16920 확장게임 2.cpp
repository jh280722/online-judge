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
queue<point> q[10];

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
			if (a[i][j] >= '1' && a[i][j] <= '9') {
				q[a[i][j] - '1'].push({ i,j });
				pn[a[i][j] - '1']++;
			}
		}
	}

	while (1) {
		bool flag = false;
		for (int pp = 0; pp < p; pp++) {
			for (int t = 0; t < s[pp]; t++) {
				bool ch = false;
				int qs = q[pp].size();
				while (qs--) {
					int r = q[pp].front().x;
					int c = q[pp].front().y;
					q[pp].pop();
					for (int i = 0; i < 4; i++) {
						int nr = r + dr[i];
						int nc = c + dc[i];
						if (nr < 0 || nc < 0 || nr > n || nc > m)
							continue;
						if (a[nr][nc] == '.') {
							pn[pp]++;
							a[nr][nc] = a[r][c];
							q[pp].push({ nr,nc });
							flag = true;
							ch = true;
						}
					}
				}
				if (!ch)
					break;
			}
		}
		if (!flag)
			break;
	}

	for (int i = 0; i < p; i++) {
		cout << pn[i] << ' ';
	}
	return 0;
}
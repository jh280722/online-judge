#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point {
	int x, y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	point() {
	}
};

const int MAX = 500;
const int INF = 2147000000;
int a[MAX][MAX];
bool ch[MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;
int maxsum = 0;
point te[5][4] = {
{{0,0},{0,1},{0,2},{0,3}},
{{0,0},{0,1},{1,0},{1,1}},
{{0,0},{1,0},{2,0},{2,1}},
{{0,0},{1,0},{1,1},{2,1}},
{{0,0},{0,1},{0,2},{1,1}}
};

void rot(point p[]) {
	for (int i = 0; i < 4; i++) {
		int x = p[i].x, y = p[i].y;
		p[i].x = -y;
		p[i].y = x;
	}
}

void sym(point p[]) {
	for (int i = 0; i < 4; i++) {
		p[i].x = p[i].x;
		p[i].y = -p[i].y;
	}
}

bool chrange(int x, int y, point p[]) {
	for (int i = 0; i < 4; i++) {
		if (x + p[i].x < 0 || x + p[i].x >= n || y + p[i].y < 0 || y + p[i].y >= m)
			return false;
	}
	return true;
}

void sum(int x, int y, point p[]) {
	int s = 0;
	for (int i = 0; i < 4; i++) {
		s += a[x + p[i].x][y + p[i].y];
	}
	maxsum = maxsum < s ? s : maxsum;
}

void solve(int x, int y) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			rot(te[i]);
			if (chrange(x, y, te[i])) {
				sum(x, y, te[i]);
			}
		}
		sym(te[i]);
		for (int j = 0; j < 4; j++) {
			rot(te[i]);
			if (chrange(x, y, te[i])) {
				sum(x, y, te[i]);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	maxsum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			solve(i, j);
		}
	}

	cout << maxsum << '\n';
	return 0;
}
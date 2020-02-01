#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define MAX 10
using namespace std;

int map[MAX][MAX];
int n, m;
int ans = INF;

struct DATA {
	int r, c;
};
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int paper[5] = { 5,5,5,5,5 };
DATA one[101];
int visit[MAX][MAX];
int oidx = 0;

bool is_possible(int r, int c, int num) {
	if (r + num + 1 > MAX || c + num + 1 > MAX)
		return false;
	for (int i = r; i < r + num + 1; i++) {
		for (int j = c; j < c + num + 1; j++) {
			if (map[i][j] == 0 || visit[i][j])
				return false;
		}
	}
	return true;
}
void change(int r, int c, int num, int val, int val2) {
	for (int i = r; i < r + num + 1; i++) {
		for (int j = c; j < c + num + 1; j++) {
			map[i][j] = val;
			visit[i][j] = val2;
		}
	}
}

bool is_clear() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}
bool pass = false;
void dfs(int idx, int cnt, int num_one) {
	if (cnt > ans) return;
	if (num_one == 0 || idx == oidx) {
		pass = true;
		if (ans > cnt)
			ans = cnt;
		return;
	}
	int r = one[idx].r;
	int c = one[idx].c;
	if (visit[r][c]) {
		dfs(idx + 1, cnt, num_one);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (paper[i] > 0) {
			if (is_possible(r, c, i)) {
				paper[i]--;
				change(r, c, i, 0, 1);
				dfs(idx + 1, cnt + 1, num_one - (i + 1) * (i + 1));
				change(r, c, i, 1, 0);
				paper[i]++;
			}
			else {
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	oidx = 0;
	ans = INF;
	pass = false;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				one[oidx++] = { i,j };
		}
	}
	dfs(0, 0, oidx);
	if (ans == INF)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}

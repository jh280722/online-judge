#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 51
#define INF 2147483647
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
	int s;
};
int n, m, t, k;
int ans=INF;

int map[MAX][MAX];
int tmp[MAX][MAX];
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

int idx;
DATA ro[6];
int ch[6];

void circle(int r, int c, int s) {
	int rh = tmp[r - s][c + s];
	int rl = tmp[r + s][c + s];
	int lh = tmp[r - s][c - s];
	int ll = tmp[r + s][c - s];
	for (int i = 0; i < 2 * s; i++) {
		tmp[r - s][c + s - i] = tmp[r - s][c + s - i - 1];
	}
	for (int i = 0; i < 2 * s; i++) {
		tmp[r + s - i][c + s] = tmp[r + s - i - 1][c + s];
	}
	tmp[r + s - 2 * s + 1][c + s] = rh;
	for (int i = 0; i < 2 * s; i++) {
		tmp[r + s][c - s + i] = tmp[r + s][c - s + i + 1];
	}
	tmp[r + s][c - s + 2 * s - 1] = rl;
	for (int i = 0; i < 2 * s; i++) {
		tmp[r - s + i][c - s] = tmp[r - s + i + 1][c - s];
	}
	tmp[r - s + 2 * s - 1][c - s] = ll;
}

void rotate(int idx) {
	int r = ro[idx].r, c = ro[idx].c;
	int s = ro[idx].s;
	for (int i = 1; i <= s; i++) {
		circle(r, c, i);
	}
}

void dfs(int cnt) {
	if (cnt == k) {
		memcpy(tmp, map, sizeof(map));
		for (int i = 0; i < k; i++) {
			rotate(ch[i] - 1);
		}
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += tmp[i][j];
			}
			ans = min(ans, sum);
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		bool flag = false;
		for (int j = 0; j < cnt; j++) {
			if (ch[j] == i + 1) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		ch[cnt] = i +1;
		dfs(cnt + 1);
		ch[cnt] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> ro[i].r >> ro[i].c >> ro[i].s;
		ro[i].r--;
		ro[i].c--;
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <set>
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define MAX 2001
#define INF 2147483640
using namespace std;

struct POINT {
	int r, c;
};
int n, m, t, k;
int h;
bool map[30][11];
int ans = -1;

bool suc() {
	for (int i = 1; i <= n; i++) {//세로선
		int c = i;
		for (int j = 0; j < h; j++) {//가로선
			if (map[j][c - 1]) {
				c--;
			}
			else if (map[j][c]) {
				c++;
			}
		}
		if (c != i) {
			return false;
		}
	}
	return true;
}

bool flag;
void dfs(int idx, int cnt, int com) {
	if (com == cnt) {
		if (suc()) {
			flag = true;
			ans = cnt;
			return;
		}
		return;
	}

	for (int i = idx; i < h; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j - 1] || map[i][j] || map[i][j + 1]) continue;
			map[i][j] = true;
			dfs(i, cnt + 1, com);
			if (flag)
				return;
			map[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int r, c;
		cin >> r >> c;
		map[r - 1][c] = true;
	}
	for (int i = 0; i < 4; i++) {
		dfs(0, 0, i);
		if (ans != -1)
			break;
	}
	cout << ans << '\n';
	return 0;
}
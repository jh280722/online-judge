#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 11
#define INF 214700000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j,l) for(int i=0;i<j;i+=l)
using namespace std;

int n, m, k, t;
int ans = 0;
int map[MAX][MAX];
int honey[2][6];
bool selh[6];
int maxhoney[2];
void hy(int idx, int idx2, int c) {
	if (c > k) {
		return;
	}
	int tmp = 0;
	for (int i = 0; i < m; i++) {
		if (selh[i]) {
			tmp += honey[idx][i] * honey[idx][i];
		}
	}
	maxhoney[idx] = max(maxhoney[idx], tmp);
	for (int i = idx2; i < m; i++) {
		selh[i] = true;
		hy(idx, i + 1, honey[idx][i] + c);
		selh[i] = false;
	}

}

void dfs(int idx, int cnt) {
	if (cnt == 2) {
		int tmp = 0;
		f(i, 2, 1) {
			maxhoney[i] = 0;
			hy(i, 0, 0);
		}
		tmp += maxhoney[0] + maxhoney[1];
		ans = max(ans, tmp);
		return;
	}

	for (int i = idx; i < n * n; i++) {
		int j = i % n;
		if (j + m > n) continue;
		for (int c = j; c < j + m; c++) {
			honey[cnt][c - j] = map[i / n][c];
		}
		dfs(i + m, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	f(tc, t, 1) {
		ans = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0, 0);
		cout << '#' << tc + 1 << ' ' << ans << '\n';
	}
	return 0;
}
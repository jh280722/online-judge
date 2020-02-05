#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define MAX 15
using namespace std;

struct DATA {
	int r, c;
};

char map[MAX][MAX];
bool visit[MAX][MAX];
int n, m, k;
int ans = 0;

void dfs(int r, int c, int color) {
	if (r == n - 1 && c == m - 1) {
		ans++;
		return;
	}
	for (int i = r+1; i < n; i++) {
		for (int j = c+1; j < m; j++) {
			if (map[i][j] != color) {
				dfs(i, j, map[i][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0,0,map[0][0]);
	cout << ans << '\n';
	return 0;
}
// DP Ç®ÀÌ
//#include <cstdio>
//char s[17][17];
//long long d[17][17];
//int main() {
//	int r, c;
//	scanf("%d%d", &r, &c);
//	for (int i = 0; i < r; i++) {
//		scanf("%s", s[i]);
//	}
//	d[0][0] = 1;
//	for (int i = 1; i < r; i++) {
//		for (int j = 1; j < c; j++) {
//			d[i][j] = 0;
//			for (int k = 0; k < i; k++) {
//				for (int l = 0; l < j; l++) {
//					if (s[i][j] != s[k][l]) d[i][j] += d[k][l];
//				}
//			}
//		}
//	}
//	printf("%lld\n", d[r - 1][c - 1]);
//}

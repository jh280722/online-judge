#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 101
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int map[MAX][MAX];

int l;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			bool flag = false;
			int pre = 1;
			for (int j = 0; j < n - 1; j++) {
				if (map[i][j] == map[i][j + 1]) {
					pre++;
				}
				else if (map[i][j] + 1 == map[i][j + 1] && pre >= l) {
					pre = 1;
				}
				else if (map[i][j] - 1 == map[i][j + 1] && pre >= 0) {
					pre = -l + 1;
				}
				else {
					flag = true;
					break;
				}
			}
			if (pre >= 0 && !flag)
				ans++;
		}
		for (int j = 0; j < n; j++) {
			bool flag = false;
			int pre = 1;
			for (int i = 0; i < n - 1; i++) {
				if (map[i][j] == map[i + 1][j]) {
					pre++;
				}
				else if (map[i][j] + 1 == map[i + 1][j] && pre >= l) {
					pre = 1;
				}
				else if (map[i][j] - 1 == map[i + 1][j] && pre >= 0) {
					pre = -l + 1;
				}
				else {
					flag = true;
					break;
				}
			}
			if (pre >= 0 && !flag)
				ans++;
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
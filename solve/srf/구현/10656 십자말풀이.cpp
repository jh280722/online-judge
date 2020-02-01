#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define MAX 51
using namespace std;

int n, m;
int ans;

struct DATA {
	int r, c;
};

char map[MAX][MAX];

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '.') {
				if (j - 1 <= 0 || map[i][j - 1] == '#') {
					if (j + 1 <= m && j + 2 <= m)
						if ((map[i][j + 1] == '.' || map[i][j + 1] == '!') && (map[i][j + 2] == '.' || map[i][j + 2] == '!')) {
							map[i][j] = '!';
						}
				}

				if (i - 1 <= 0 || map[i - 1][j] == '#') {
					if (i + 1 <= n && i + 2 <= n)
						if ((map[i + 1][j] == '.' || map[i + 1][j] == '!') && (map[i + 2][j] == '.' || map[i + 2][j] == '!')) {
							map[i][j] = '!';
						}
				}
			}
		}
	}
	vector<DATA> hint;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '!') {
				map[i][j] = ++ans;
				hint.push_back({ i,j });
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << hint[i].r << ' ' << hint[i].c << '\n';
	}

	return 0;
}

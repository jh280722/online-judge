#include <iostream>
#include <algorithm>
#include <queue>
#define all(v) v.begin(), v.end()
#define MAX 201
#define INF 1000000000
using namespace std;
typedef long long ll;

struct BOMB {
	int r, c;
	int t;
};

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int n, m, v, t;
int bt;
char map[MAX][MAX];
int bombtime[MAX][MAX];

int time;

queue<BOMB> q;

void setbomb() {
	time++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.') {
				bombtime[i][j] = time;
				map[i][j] = 'O';
			}
		}
	}
}

void solve() {
	while (bt!=time) {
		setbomb();		
		if (bt == time)
			break;
		time++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (bombtime[i][j] + 3 <= time) {
					for (int k = 0; k < 5; k++) {
						int nx = i + dr[k];
						int ny = j + dc[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (bombtime[i][j] == bombtime[nx][ny]) continue;
						bombtime[nx][ny] = INF;
						map[nx][ny] = '.';
					}
					bombtime[i][j] = INF;
					map[i][j] = '.';
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> bt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				bombtime[i][j] = 0;
			}
			else
				bombtime[i][j] = INF;
		}
	}
	time++;
	solve();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 1001
#define INF 1000000000
typedef long long ll;
using namespace std;


int map[MAX][MAX];
int dis[MAX][MAX];
int n, m,t;

struct CITY {
	int s, x, y;
};
CITY city[MAX];

int dist(CITY c1, CITY c2) {
	return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

void floyWarshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = map[i][j];
			if (map[i][j] == 0)
				dis[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> city[i].s >> city[i].x >> city[i].y;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			int d = dist(city[i], city[j]);
			if (city[i].s == 1 && city[j].s == 1 && d>t) {
				map[i][j] = t;
				map[j][i] = t;
			}
			else {
				map[i][j] = d;
				map[j][i] = d;
			}
		}
	}
	floyWarshall();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		cout << dis[c1][c2] << '\n';
	}

	return 0;
}

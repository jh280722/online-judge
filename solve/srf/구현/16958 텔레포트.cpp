#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 1000000000
typedef long long ll;
using namespace std;

int n, m, t;
struct CITY {
	int s, x, y;
};
CITY city[MAX];
int telcity[MAX];
int tid;
int near[MAX];
int dist(CITY c1, CITY c2) {
	return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> city[i].s >> city[i].x >> city[i].y;
		if (city[i].s == 1) {
			telcity[tid++] = i;
		}
		near[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		if (city[i].s == 1) {
			near[i] = 0;
			continue;
		}
		for (int j = 0; j < tid; j++) {
			int d = dist(city[i], city[telcity[j]]);
			near[i] = min(near[i], d);
		}
		if (tid == 0)
			near[i] = 0;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		int d = dist(city[c1], city[c2]);
		if (city[c1].s == 1 && city[c2].s == 1)
		{
			d = min(d, t);
		}
		d = min(d, near[c1] + near[c2] + t);
		cout << d << '\n';
	}

	return 0;
}

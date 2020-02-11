#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 51
#define INF 1000000000
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
	//int cnt;
};
int n, m, t, k;
int ans;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
vector<DATA> house;

int dis(DATA a, DATA b) {
	return abs(a.r - b.r) + abs(a.c - b.c);
}

void cal(int r, int c) {
	int cnt[41] = {0,};
	for (int i = 0; i < house.size(); i++) {
		cnt[dis({ r,c }, house[i]) + 1]++;
	}
	for (int k = 1; k < 2 * n; k++) {
		int price = -(k*k+(k-1)*(k-1));
		cnt[k] += cnt[k - 1];
		if (price + cnt[k]*m < 0)
			continue;
		if (ans < cnt[k])
			ans = cnt[k];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		house.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					house.push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cal(i,j);
			}
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
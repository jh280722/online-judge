#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define MAX 51
using namespace std;

int map[MAX][MAX];
int origin[MAX][MAX];
int n, m;
int ans=INF;
struct DATA {
	int r, c;
};
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
DATA chicken[14];
bool visit[14];
int cidx;
vector<DATA> house;
int circul(DATA a, DATA b) {
	return abs(a.r - b.r) + abs(a.c - b.c);
}
void dfs(int idx, int cnt) {
	if (cnt==m) {
		int tempResult = 0;

		for (int i = 0; i < house.size(); i++)
		{
			int dist = INF;
			for (int j = 0; j < cidx; j++)
				if (visit[j])
					dist = min(dist, circul(house[i], chicken[j]));
			tempResult += dist;

		}
		ans = min(ans, tempResult);
		return;
	}

	for (register int i = idx + 1; i < cidx; i++) {
		visit[i] = true;
		dfs(i, cnt + 1);
		visit[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			origin[i][j] = map[i][j];
			if (map[i][j] == 2)
				chicken[cidx++] = { i,j };
			if (map[i][j] == 1)
				house.push_back({ i,j});
		}
	}
	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}
#include <iostream>
#include <string.h>
#include <queue>
#define MAX 10
#define INF 214700000
typedef long long ll;
using namespace std;

int n, m, t, ans;
int map[MAX][MAX];
int dis[MAX][MAX][2];

vector<pair<int, int>> Cliff;

struct DATA {
	int r, c;
	bool ch, done;
};

int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

int cr[4] = { 1, -1, 1, -1 };
int cc[4] = { -1, -1, 1, 1 };


int set_time(int ctime, int period)
{
	int time = ctime;
	while (1)
	{
		if (time % period == 0) break;
		time++;
	}
	return time;
}
void check_state()
{
	for (int i = 0; i < Cliff.size(); i++)
	{
		int r = Cliff[i].first;
		int c = Cliff[i].second;

		int Garo = 0;
		for (int j = 0; j < 2; j++)
		{
			int nr = r + dr[j];
			int nc = c + dc[j];

			if (nr >= 0 && nc >= 0 && nr < n && nc < n)
			{
				if (map[nr][nc] == 0 || map[nr][nc] == -1 || map[nr][nc] >= 2) Garo++;
			}
		}

		int Sero = 0;
		for (int j = 2; j < 4; j++)
		{
			int nr = r + dr[j];
			int nc = c + dc[j];

			if (nr >= 0 && nc >= 0 && nr < n && nc < n)
			{
				if (map[nr][nc] == 0 || map[nr][nc] == -1 || map[nr][nc] >= 2) Sero++;
			}
		}

		if (Garo >= 1 && Sero >= 1) map[r][c] = -1;
	}
}

void bfs() {
	queue<DATA> q;
	q.push({ 0,0,0 });
	dis[0][0][0] = 0;
	int cnt1 = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {

			int r = q.front().r;
			int c = q.front().c;
			bool ch = q.front().ch;
			bool done = q.front().done;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				if (map[nr][nc] == -1) continue;
				if (map[nr][nc] == 1) {
					if (dis[nr][nc][done] <= dis[r][c][done] + 1) continue;
					q.push({ nr,nc, false, done });
					dis[nr][nc][done] = dis[r][c][done] + 1;
				}
				else if (map[nr][nc] > 1 && !ch) {
					int time = set_time(dis[r][c][done] + 1, map[nr][nc]);
					if (dis[nr][nc][done] <= time) continue;
					q.push({ nr,nc, true, done });
					dis[nr][nc][done] = time;
				}
				else if (map[nr][nc] == 0 && !ch && !done) {
					int time = set_time(dis[r][c][done] + 1, m);
					if (dis[nr][nc][done] <= time) continue;
					q.push({ nr,nc, true, true });
					dis[nr][nc][1] = time;
				}

			}
		}
		cnt1++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(dis[0][0], dis[0][0] + MAX * MAX * 2, INF);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				Cliff.push_back(make_pair(i, j));
			}
		}
	}
	check_state();
	bfs();
	cout << min(dis[n - 1][n - 1][0], dis[n - 1][n - 1][1]) << '\n';
	return 0;
}
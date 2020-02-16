#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <set>
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define MAX 51
#define INF 2147483640
using namespace std;

struct POINT {
	int r, c;
};
int n, m, t, k;
int lf, rt;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
int ans = 0;

queue<POINT> q;
bool bfs(int r, int c) {
	queue<POINT> nq;
	vector<POINT> v;
	int sum = map[r][c];
	v.push_back({ r,c });
	nq.push({ r,c });
	visit[r][c] = true;
	int lev = 0;
	while (!nq.empty()) {
		int qs = nq.size();
		while (qs--) {
			r = nq.front().r;
			c = nq.front().c;
			nq.pop();
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n || visit[nr][nc]) continue;
				int sub = abs(map[r][c] - map[nr][nc]);
				if (sub >= lf && sub <= rt) {
					visit[nr][nc] = true;
					sum += map[nr][nc];
					v.push_back({ nr,nc });
					nq.push({ nr,nc });
				}
			}
		}
		lev++;
	}

	if (v.size() > 1) {
		int vs = v.size();
		int num = sum / vs;
		for (int i = 0; i < vs; i++) {
			int r = v[i].r, c = v[i].c;
			map[r][c] = num;
			q.push({ r,c });
		}
		return false;
	}
	else
		return true;
}

bool chk(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		int dif = abs(map[nr][nc] - map[r][c]);
		if (dif >= lf && dif <= rt) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> lf >> rt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			q.push({ i,j });
		}
	}
	bool flag = false;
	while (!flag) {
		flag = true;
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();
			if (visit[r][c] || chk(r, c)) continue;
			if (!bfs(r, c))
				flag = false;
		}
		if (!flag)
			ans++;
		else
			break;
		memset(visit, 0, sizeof(visit));
	}

	cout << ans << '\n';
	return 0;
}
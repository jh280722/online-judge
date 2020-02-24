#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#define MAX 11
#define INF 214700000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j,l) for(int i=0;i<j;i+=l)
using namespace std;

struct PS {
	int num;
	int r, c;
	int t;
};
struct ST {
	int num;
	int r, c;
	int t;
};
int n, m, k, t;
int ans = INF;
int map[MAX][MAX];
int sel[MAX];
pii dis[MAX];
vector<PS> p;
vector<ST> st;
queue<pair<int, pii>> q;

int manD(PS p) {
	return abs(p.r - st[sel[p.num]].r) + abs(p.c - st[sel[p.num]].c);
}

void bfs() {
	int time = 0;
	while (!q.empty()) {
		int qs = q.size();
		time++;
		while (qs--) {
			int lng = q.front().first;
			int num = q.front().second.first;
			int t = q.front().second.second;
			q.pop();
			if (time < t) {
				q.push({ lng,{num,t} });
				continue;
			}
			if (lng == st[sel[num]].t) {
				st[sel[num]].num--;
			}
			else if (lng == 0) {
				if (st[sel[num]].num < 3) {
					st[sel[num]].num++;
					q.push({ lng + 1,{num,t + 1} });
				}
				else
					q.push({ lng,{num,t + 1} });
			}
			else {
				q.push({ lng + 1,{num,t + 1} });
			}
		}
	}
	ans = min(ans, time + 1);
}

void dfs(int idx, int cnt) {
	if (cnt == p.size()) {
		f(i, cnt, 1)
			dis[i].second = p[i].num, dis[i].first = manD(p[i]);
		sort(dis, dis + cnt);
		f(i, cnt, 1)
			q.push({ 0,{ dis[i].second,dis[i].first} });
		bfs();
		return;
	}

	for (int i = idx; i < p.size(); i++) {
		for (int j = 0; j < 2; j++) {
			sel[i] = j;
			dfs(i + 1, cnt + 1);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	f(tc, t, 1) {
		ans = INF;
		p.clear();
		st.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					p.push_back({ (int)p.size(),i,j,0 });
				}
				else if (map[i][j] != 0) {
					st.push_back({ 0, i,j,map[i][j] });
				}
			}
		}
		dfs(0, 0);

		cout << '#' << tc + 1 << ' ' << ans << '\n';
	}
	return 0;
}
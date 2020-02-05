#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 501
#define INF 1000000000
using namespace std;
typedef long long ll;

struct BALL {
	int n;
	pair<int,int> rc;
};

int n, m, v, t;
int map[MAX][MAX];
int ball[MAX][MAX];

int dr[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dc[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

//체스판의 각 칸 위에 공을 하나씩 놓는다.이제 공은 다음과 같은 규칙에 의해서 자동으로 움직인다.
//인접한 8방향(가로, 세로, 대각선)에 적힌 모든 정수가 현재 칸에 적힌 수보다 크면 이동을 멈춘다.
//그 외의 경우에는 가장 작은 정수가 있는 칸으로 공이 이동한다.
//공의 크기는 매우 작아서, 체스판의 한 칸 위에 여러 개의 공이 있을 수 있다.체스판의 상태가 주어진다.
//공이 더 이상 움직이지 않을 때, 각 칸에 공이 몇 개 있는지 구해보자

//공이 굴러가서 다른곳으로 가는데 작은 곳으로 가므로 우선순위 큐를 통해 한번씩만 비교한다.
priority_queue<pair<int,pair<int,int>>> q;
void bfs() {
	while (!q.empty()) {
		int num = q.top().first;
		int r = q.top().second.first;
		int c = q.top().second.second;
		q.pop();
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ball[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
		int min = num;
		bool ch = false;
		int cr, cc;
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (min > map[nr][nc]) {
				ch = true;
				min = map[nr][nc];
				cr = nr;
				cc = nc;
			}
		}
		if (ch) {
			ball[cr][cc] += ball[r][c];
			ball[r][c] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			ball[i][j] = 1;
			q.push({ map[i][j],{i,j } });
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ball[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

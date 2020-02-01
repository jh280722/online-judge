#include <iostream>
#include <queue>
#include <deque>
#define ll long long
using namespace std;

struct DATA {
	int r, c;
	int dir;
};

const int MAX = 101;
const int INF = 2147400000;
int map[MAX][MAX];
int visit[MAX][MAX];

//0 up 1 right 2 down 3 left
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;
int aidx;
int didx;
pair<int, char> cdir[MAX];
DATA tail;
int bfs() {
	int cnt = 0;
	deque<DATA> q;
	q.push_back({ 1,1,1});
	tail = { 1,1,1 };
	map[1][1] = 1;
	while (!q.empty()) {
		int r = q.back().r;
		int c = q.back().c;
		int dir = q.back().dir;
		cnt++;

		int nr = r + dr[dir];
		int nc = c + dc[dir];
		if (nr <= 0 || nr > n || nc <= 0 || nc > n) return cnt;

		for (int i = 0; i < l; i++) {
			if (cdir[i].first == cnt) {
				if (cdir[i].second == 'L') {
					dir -= 1;
					if (dir == -1)
						dir = 3;
				}
				else {
					dir = (dir + 1) % 4;
				}
				break;
			}
		}

		if (map[nr][nc] == 2) {
			map[nr][nc] = 1;
			q.push_back({ nr,nc,dir });
		}
		else if(map[nr][nc]==1){
			return cnt;
		}
		else {
			map[nr][nc] = 1;
			q.push_back({ nr,nc,dir });
			map[q.front().r][q.front().c] = 0;
			q.pop_front();
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//뱀 처음 오른쪽 방향 1,1 시작 N * N 보드 
	cin >> n >> k; //k 사과 갯수
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		map[r][c] = 2;//apple
	}
	cin >> l;//dir num
	for (int i = 0; i < l; i++) {
		cin >> cdir[didx].first >> cdir[didx].second;
		didx++;
	}

	cout << bfs() << '\n';
	return 0;
}
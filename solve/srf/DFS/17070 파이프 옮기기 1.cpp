#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#define MAX 17
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int ans;
int map[MAX][MAX];
pii pipe = { 0,1 };
int dir = 0; // 0 가로 1 세로 2 대각선
void dfs() {
	int r = pipe.first;
	int c = pipe.second;
	if (r == n - 1 && c == n - 1) {
		ans++;
		return;
	}

	int nr = r;
	int nc = c;
	if (dir == 0) {
		nc++;
		if (nc < n && map[nr][nc] == 0) {
			pipe.first = nr;
			pipe.second = nc;
			dfs();
			nr++;
			if (nr < n && map[nr][nc] == 0 && map[nr][nc - 1] == 0) {
				pipe.first = nr;
				pipe.second = nc;
				dir = 2;
				dfs();
			}
		}
	}
	else if (dir == 1) {
		nr++;
		if (nr < n && map[nr][nc] == 0) {
			pipe.first = nr;
			pipe.second = nc;
			dfs();
			nc++;
			if (nc < n && map[nr][nc] == 0 && map[nr - 1][nc] == 0) {
				pipe.first = nr;
				pipe.second = nc;
				dir = 2;
				dfs();
			}
		}
	}
	else {
		if (nc + 1 < n && map[nr][nc + 1] == 0) {
			pipe.first = nr;
			pipe.second = nc + 1;
			dir = 0;
			dfs();
		}
		if (nr + 1 < n && map[nr + 1][nc] == 0) {
			pipe.first = nr + 1;
			pipe.second = nc;
			dir = 1;
			dfs();
		}
		if (nr + 1 < n && nc + 1 < n && map[nr + 1][nc] == 0 && map[nr][nc + 1] == 0 && map[nr + 1][nc + 1] == 0) {
			pipe.first = nr + 1;
			pipe.second = nc + 1;
			dir = 2;
			dfs();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	f(i, 0, n) {
		f(j, 0, n) {
			cin >> map[i][j];
		}
	}
	dfs();
	cout << ans;
	return 0;
}
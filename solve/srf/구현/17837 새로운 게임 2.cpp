#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 13
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0, 0, -1,1 };
int dc[] = { 1,-1,0,0 };
int ans;
int map[MAX][MAX];
vi vis[MAX][MAX];
struct horse {
	int r, c, d;
	int h;
};
horse h[11];

void solve() {
	int turn = 0;
	ans = -1;
	while (turn <= 1000) {
		turn++;
		f(idx,0,k) {
			int r = h[idx].r;
			int c = h[idx].c;
			int d = h[idx].d;
			int hh = h[idx].h;

			vector<int> seq;
			f(i, hh, vis[r][c].size()) {
				seq.push_back(vis[r][c][i]);
			}
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == 2) {
				if (d == 0 || d == 2) d++;
				else d--;
				nr = r + dr[d];
				nc = c + dc[d];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == 2) {
					nr = r, nc = c;
				}
			}
			h[idx].d = d;
			if (r == nr && c == nc) continue;
			vis[r][c].erase(vis[r][c].begin() + hh, vis[r][c].end());

			int hi = vis[nr][nc].size();
			if (hi + seq.size() >= 4) {
				ans = turn;
				return;
			}
			if (map[nr][nc] == 1) {
				reverse(all(seq));
			}
			f(i, 0, seq.size()) {
				int idx2 = seq[i];
				vis[nr][nc].push_back(idx2);
				h[idx2].h = hi + i;
				h[idx2].r = nr;
				h[idx2].c = nc;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	f(i, 0, n) {
		f(j, 0, n) {
			cin >> map[i][j];
		}
	}
	f(i, 0, k) {
		int a, b, c;
		cin >> a >> b >> c;
		h[i] = { a - 1,b - 1,c - 1, 0 };
		vis[a - 1][b - 1].push_back(i);
	}
	solve();
	cout << ans;

	return 0;
}
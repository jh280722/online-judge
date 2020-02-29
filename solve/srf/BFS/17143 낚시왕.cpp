#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,1,-1 };
int ans;
int map[MAX][MAX];
int vis[2][MAX][MAX];
struct shark {
	int r, c;
	int s, d, z;
};
queue<shark> q;
void bfs(int loc) {
	memset(vis[1], 0, sizeof vis[1]);
	int qs = q.size();
	int catchr = MAX;
	f(i, 0, n) {
		if (vis[0][i][loc]) {
			catchr = i;
			break;
		}
	}
	qs = q.size();
	while (qs--) {
		int r = q.front().r;
		int c = q.front().c;
		int s = q.front().s;
		int d = q.front().d;
		int z = q.front().z;
		q.pop();
		if (vis[0][r][c] != z)
			continue;
		if (r == catchr && c == loc) {
			ans += z;
			continue;
		}
		int nr = r, nc = c;
		if (d == 0 || d==1) {
			s %= (n-1) * 2;
			f(i, 1, s + 1) {
				if (nr + dr[d] < 0 || nr + dr[d] >= n || nc + dc[d] < 0 || nc + dc[d] >= m) {
					if (d == 0 || d == 2)
						d++;
					else
						d--;
				}
				nr += dr[d];
				nc += dc[d];
			}
		}
		else {
			s %= (m-1) * 2;			
			f(i, 1, s + 1) {
				if (nr + dr[d] < 0 || nr + dr[d] >= n || nc + dc[d] < 0 || nc + dc[d] >= m) {
					if (d == 0 || d == 2)
						d++;
					else
						d--;
				}
				nr += dr[d];
				nc += dc[d];
			}
		}
		if (vis[1][nr][nc] < z) {
			q.push({ nr,nc,s,d,z });
			vis[1][nr][nc] = z;
		}
	}
	memcpy(vis[0], vis[1], sizeof vis[0]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	f(i, 0, k) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--; c--; d--;
		q.push({ r,c,s,d,z });
		vis[0][r][c] = z;
	}

	f(i, 0, m) {
		bfs(i);
	}
	cout << ans;

	return 0;
}
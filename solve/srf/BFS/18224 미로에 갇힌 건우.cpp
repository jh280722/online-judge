#include <bits/stdc++.h>
#define MAX 501
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m, k, t;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int ans;
int Max = -INF, Min = INF;

bool day;
int Map[MAX][MAX];
bool vis[MAX][MAX][20];

queue<pii> q;
void bfs() {
	int lev = 0;
	int d = day;
	while (!q.empty()) {
		int qs = q.size();
		d = (lev / m) % 2;
		int nd = ((lev+1) / m) % 2;
		while (qs--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (r == n - 1 && c == n - 1) {
				day = d;
				ans = lev / (2 * m) + 1;
				return;
			}
			f(k, 0, 4) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				if (vis[nr][nc][lev%(2*m)]) continue;
				bool flg = false;
				if (Map[nr][nc] == 1) {
					if (d == 0)
						continue;
					while (true) {
						nr += dr[k];
						nc += dc[k];
						if (nr < 0 || nr >= n || nc < 0 || nc >= n) break;
						if (vis[nr][nc][lev % (2 * m)]) break;
						if (Map[nr][nc]) continue;
						vis[nr][nc][lev % (2 * m)] = true;
						q.push({ nr,nc });
						break;
					}
				}
				else {
					vis[nr][nc][lev % (2 * m)] = true;
					q.push({ nr,nc });
				}
			}
		}
		lev++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ans = -1;
	cin >> n >> m;
	f(i, 0, n) {
		f(j, 0, n) {
			cin >> Map[i][j];
		}
	}
	vis[0][0][0] = true;
	q.push({ 0, 0 });
	bfs();
	if (ans == -1) {
		cout << -1;
		return 0;
	}
	cout << ans << ' ';
	cout << (day ? "moon" : "sun");
	return 0;
}

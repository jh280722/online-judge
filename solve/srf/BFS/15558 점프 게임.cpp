#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#define MAX 100001
#define INF 2147000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { -2,-2,0,0,2,2 };
int dc[] = { -1,1,-2,2,-1,1 };

bool vis[2][MAX];
char map[2][MAX];
int ans;
bool bfs(int r, int c) {
	queue<pii> q;
	q.push({ r,c });
	vis[r][c] = true;
	int lev = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			r = q.front().first;
			c = q.front().second;
			q.pop();
			if (c < lev) continue;
			if (c >= n || c + k >= n || c + 1 >= n) {
				return true;
			}
			if (c - 1 >= 0 && map[r][c - 1] == '1' && !vis[r][c - 1]) {
				vis[r][c - 1] = true;
				q.push({ r,c - 1 });
			}
			if (map[r][c + 1] == '1' && !vis[r][c + 1]) {
				vis[r][c + 1] = 1;
				q.push({ r,c + 1 });
			}
			if (r == 0 && map[1][c + k] == '1' && !vis[1][c + k]) {
				vis[1][c + k] = 1;
				q.push({ 1,c + k });
			}
			else if (r == 1 && map[0][c + k] == '1' && !vis[0][c + k]) {
				vis[0][c + k] = 1;
				q.push({ 0,c + k });
			}
		}
		lev++;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	f(i, 2) {
		f(j, n) {
			cin >> map[i][j];
		}
	}
	cout << bfs(0, 0);
	return 0;
}
#include <bits/stdc++.h>
#define MAX 1001
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0, 1, -1, 0, 0 };
int dc[] = { 0, 0, 0, -1, 1 };
int ans;
int dir[MAX][MAX];//0 X 1 U 2 D 3 R 4 L
pii board[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(dir, -1, sizeof dir);
	queue<pii> q;
	f(i, 0, n) {
		f(j, 0, n) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			board[i][j].first = x, board[i][j].second = y;
			if (x == i && y == j) {
				dir[i][j] = 0;
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		f(k, 1, 5) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (dir[nr][nc] != -1) continue;
			if (board[nr][nc] == board[r][c]) {
				dir[nr][nc] = k;
				q.push({ nr,nc });
			}
		}
	}
	f(i, 0, n) {
		f(j, 0, n) {
			if (dir[i][j]==-1 && board[i][j] == pii(-2,-2)) {
				f(k, 1, 5) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
					if (dir[nr][nc] != -1) continue;
					if (board[nr][nc] != board[i][j]) continue;
					dir[nr][nc] = k;
					q.push({ nr,nc });
					q.push({ i,j });
					if (k == 1 || k == 3) {
						dir[i][j] = k + 1;
					}
					else
						dir[i][j] = k - 1;
					while (!q.empty()) {
						int r = q.front().first;
						int c = q.front().second;
						q.pop();
						f(k, 1, 5) {
							int nr = r + dr[k];
							int nc = c + dc[k];
							if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
							if (dir[nr][nc] != -1) continue;
							if (board[nr][nc] != board[r][c]) continue;
							dir[nr][nc] = k;
							q.push({ nr,nc });
						}
					}
					break;
				}
			}
		}
	}
	f(i, 0, n) {
		f(j, 0, n) {
			if (dir[i][j] == -1) {
				cout << "INVALID\n";
				return 0;
			}
		}
	}
	cout << "VALID\n";
	f(i, 0, n) {
		f(j, 0, n) {
			if (dir[i][j] == 0)
				cout << 'X';
			else if (dir[i][j] == 1)
				cout << 'U';
			else if (dir[i][j] == 2)
				cout << 'D';
			else if (dir[i][j] == 3)
				cout << 'R';
			else
				cout << 'L';
		}
		cout << '\n';
	}

	return 0;
}

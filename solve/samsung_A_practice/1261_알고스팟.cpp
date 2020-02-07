#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
#define ll long long
#define pii pair<int,int>
using namespace std;
constexpr char ENDL = '\n';
constexpr char SP = ' ';
const int INF = 2147000000;

int map[MAX][MAX];
bool ch[MAX][MAX];
int dis[MAX + 1][MAX + 1];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };
int m, n, t;

void bfs(int r, int c) {
    queue<pii > q;
    q.push({ r,c });
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dis[i][j] = INF;
    dis[r][c] = 0;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                if (dis[nr][nc] > dis[r][c] + map[nr][nc]) {
                    dis[nr][nc] = dis[r][c] + map[nr][nc];
                    q.push({ nr,nc });
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    bfs(0, 0);
    cout << dis[n - 1][m - 1];
    return 0;
}

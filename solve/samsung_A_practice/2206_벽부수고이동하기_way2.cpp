//2206 - 벽 부수고 이동하기
#include <iostream>
using namespace std;
int n, m, f = 0, res = 2147000000, path[1001][1001];
bool ch[1001][1001];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
char map[1001][1001];
//bfs로 할시 queue에 집어넣는게 많아서 dfs가 더 빠르다.
void DFS(int x, int y, int L) {
        if (res < L + (n - x) + (m - y)) return;
        if (x == n - 1 && y == m - 1) {
                if (res > L) res = L;
        }
        else {
                for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m && ch[nx][ny] == 0) {
                                if (map[nx][ny] == '0') {
                                        ch[nx][ny] = 1;
                                        path[nx][ny] = L;
                                        DFS(nx, ny, L + 1);
                                        ch[nx][ny] = 0;
                                }
                                else if (f == 0) {
                                        ch[nx][ny] = 1;
                                        f = 1;
                                        path[nx][ny] = L;
                                        DFS(nx, ny, L + 1);
                                        f = 0;
                                        ch[nx][ny] = 0;
                                }
                        }
                }
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> map[i];
        ch[0][0] = 1;
        DFS(0, 0, 1);
        if (res == 2147000000) cout << "-1\n";
        else cout << res << '\n';
        return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
constexpr char ENDL = '\n';
constexpr char SP   = ' ';
const int MAX = 101;
const int INF =2147000000;
int a[101][101];
bool ch[101][101];
int dis[MAX + 1][MAX+1];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int m,n,t;
int bfs(int x, int y){
        queue<pii > q;
        q.push({x,y});
        for (int i = 0; i < MAX; i++)
                for(int j=0; j<MAX; j++)
                        dis[i][j] = INF;
        dis[x][y]=0;
        while (!q.empty()) {
                x = get<0>(q.front());
                y = get<1>(q.front());
                q.pop();
                for (int k = 0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                                if(dis[nx][ny] > dis[x][y]+a[nx][ny]) {
                                        dis[nx][ny]=dis[x][y]+a[nx][ny];
                                        q.push({nx,ny});
                                }
                        }
                }
        }
}

int main() {
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
                for(int j=0; j<m; j++) {
                        scanf("%1d", &a[i][j]);
                }
        }
        bfs(0,0);
        cout<<dis[n-1][m-1];
        return 0;
}

// 12 12
// 001111001111
// 010000010000
// 001111001111
// 110001110001
// 011010011010
// 100010100010
// 001111001111
// 010000010000
// 001111001111
// 110001110001
// 011010011010
// 100010100010

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1000;
const int INF =2147000000;
char a[MAX][MAX+1];
int dis[MAX][MAX];
ll cnt = 0;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
struct point {
        int x, y;
        point(int x, int y) {
                this->x = x;
                this->y = y;
        }
        point() {
        }
};

int t;
int n, m, k, l,ans;

int bfs(int x, int y){
        queue<point> q;
        q.push({x,y});
        for (int i = 0; i < n; i++)
                for(int j=0; j<m; j++)
                        dis[i][j] = INF;
        dis[x][y] = 0;
        while (!q.empty()) {
                t=q.size();
                cnt++;
                while(t--) {
                        x = q.front().x;
                        y = q.front().y;
                        q.pop();
                        if(x==n-1 && y==m-1)
                                return cnt;
                        for (int i = 0; i<4; i++) {
                                int nx = x + dx[i];
                                int ny = y + dy[i];
                                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                                        if (a[nx][ny] & 1 << dis[x][y]) continue;
                                        if(a[nx][ny] == '0' && dis[nx][ny] > dis[x][y]) {
                                                dis[nx][ny]=dis[x][y];
                                                q.push({nx,ny});
                                        }
                                        if (a[nx][ny] == '1'&& dis[x][y] <k && dis[nx][ny] > dis[x][y]+1) {
                                                dis[nx][ny]=dis[x][y]+1;
                                                q.push({nx,ny});
                                        }
                                }
                        }
                }
        }
        if(dis[n-1][m-1]==INF)
                return -1;
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n >> m >> k;
        for( int i = 0; i < n; i++)
        {
                cin >> a[i];
        }
        cout<<bfs(0,0)<<'\n';
        // for (int i = 0; i < n; i++) {
        //         for(int j=0; j<m; j++)
        //                 cout<<dis[i][j]<<' ';
        //         cout<<'\n';
        // }
        return 0;
}

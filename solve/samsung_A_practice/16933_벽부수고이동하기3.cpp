#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1000;
const int INF =2147000000;
char a[MAX][MAX+1];
bool visit[MAX][MAX][11];
ll cnt = 0;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
struct point {
        int x, y,w;
        point(int x, int y, int w) {
                this->x = x;
                this->y = y;
                this->w=w;
        }
        point() {
        }
};

int t;
int n, m, k, l,ans;

int bfs(int x, int y){
        queue<point> q;
        q.push({x,y,0});
        visit[x][y][0] = true;
        bool d =false;
        while (!q.empty()) {
                d=!d;
                t=q.size();
                cnt++;
                while(t--) {
                        x = q.front().x;
                        y = q.front().y;
                        int w = q.front().w;
                        q.pop();
                        if(x==n-1 && y==m-1)
                                return cnt;

                        for (int i = 0; i<4; i++) {
                                int nx = x + dx[i];
                                int ny = y + dy[i];
                                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                                        if(a[nx][ny] == '0' && !visit[nx][ny][w]) {
                                                visit[nx][ny][w]=true;
                                                q.push({nx,ny, w});
                                        }
                                        if(a[nx][ny]=='1') {
                                                if (w <k && !visit[nx][ny][w+1]) {
                                                        if(d) {
                                                                visit[nx][ny][w+1]=true;
                                                                q.push({nx,ny, w+1});
                                                        }
                                                        else{
                                                                q.push({x,y, w});
                                                        }

                                                }
                                        }
                                }
                        }
                }
        }
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
        return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch1[101];
bool ch2[1001][1001][2];
char a[1001][1001];
int a1[101];
int a2[301][301];
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
int n, m, l,ans;

void readMap( void)
{
        cin >> n >> m;
        for( int i = 0; i < n; i++)
        {
                cin >> a[i];
        }
}
int bfs(int x, int y){
        queue<tuple<int, int,bool > > q;
        q.push({x,y,false});
        ch2[x][y][0] = true;
        ch2[x][y][1]=true;
        while (!q.empty()) {
                t=q.size();
                cnt++;
                while(t--) {
                        x = get<0>(q.front());
                        y = get<1>(q.front());
                        bool wall=get<2>(q.front());
                        //printf("%d %d %d cnt='%d'\n",x,y,wall,cnt);
                        q.pop();
                        if(x==n-1 && y==m-1)
                                return cnt;
                        for (int k = 0; k<4; k++) {
                                int nx = x + dx[k];
                                int ny = y + dy[k];
                                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                                        if (a[nx][ny] == '0' && ch2[nx][ny][wall] == false) {
                                                q.push({nx,ny,wall});
                                                ch2[nx][ny][wall] = true;
                                        }
                                        if (a[nx][ny] == '1' && !wall && ch2[nx][ny][wall] == false) {
                                                q.push({nx,ny,!wall});
                                                ch2[nx][ny][wall] = true;
                                        }
                                }
                        }
                }
        }
        if(ch2[n-1][m-1][0]==false && ch2[n-1][m-1][1]==false)
                return -1;
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        readMap();
        cout<<bfs(0,0);
        return 0;
}

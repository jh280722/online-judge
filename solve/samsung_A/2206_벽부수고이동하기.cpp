#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch1[101];
bool ch2[1001][1001];
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
int bfs(){
        queue<pii > q;
        q.push({0,0});
        int cnt=0;
        while(!q.empty()) {
                t=q.size();
                while(t--) {
                        int x =q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int i=0; i<4; i++) {
                                int nx=x+dx[i];
                                int ny=y+dy[i];
                                if(ch2[nx][ny]!=true && a2[nx][ny]==0) {
                                }
                        }
                }
                cnt++;
        }
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>n;
        cout<<bfs();
        return 0;
}

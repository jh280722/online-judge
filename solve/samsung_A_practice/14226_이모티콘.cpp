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
int bfs(int n){
        queue<pii > q;
        q.push({0,1});
        int cnt=0;
        while(!q.empty()) {
                t=q.size();
                while(t--) {
                        auto a =q.front();
                        q.pop();
                        if(a.second==n) {
                                return cnt;
                        }
                        else if(ch2[a.first][a.second]!=true && a.second <n) {
                                ch2[a.first][a.second]=true;
                                q.push({a.second,a.second});
                                q.push({a.first, a.first+a.second});
                                if(a.second>0)
                                        q.push({a.first,a.second-1});
                        }
                }
                cnt++;
        }
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>n;
        cout<<bfs(n);
        return 0;
}

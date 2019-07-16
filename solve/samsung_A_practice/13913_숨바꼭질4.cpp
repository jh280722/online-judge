#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
constexpr char ENDL = '\n';
constexpr char SP   = ' ';
const int MAX = 100001;
int dis[MAX + 1];
int trace[MAX+1];
void bfs(int n, int k) {
        for (int i = 0; i < MAX; i++) dis[i] = 2147000000;
        queue<int> q;
        q.push(n);
        dis[n]=0;
        while (!q.empty()) {
                int a = q.front();
                if (dis[a] > dis[k] || a==k )
                        break;
                q.pop();
                if (a-1>=0 && dis[a-1]>dis[a]+1) {
                        q.push(a - 1);
                        dis[a - 1]= dis[a]+1;
                        trace[a-1]=a;
                        if (a - 1 == k) break;
                }
                if (a + 1<=k && dis[a+1]>dis[a]+1) {
                        q.push(a + 1);
                        dis[a+1]=dis[a]+1;
                        trace[a+1]=a;
                        if (a + 1 == k) break;
                }
                if (2 * a <= k+1 && dis[a*2]>dis[a] +1) {
                        q.push(a *2);
                        dis[a*2]=dis[a] + 1;
                        trace[2*a]=a;
                        if (a *2 == k) break;
                }
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, k;
        cin >> n >> k;
        if(k <= n) {
                cout<<n - k<<ENDL;
                for(int i=n; i>=k; i--)
                        cout<<i<<' ';
        }
        else{
                bfs(n, k);
                cout << dis[k]<<ENDL;
                vector<int> list;
                while(k!=n) {
                        list.push_back(k);
                        k=trace[k];
                }
                cout<<k<<' ';
                for (int i = list.size()-1; i >= 0; i--)
                        cout<<list[i]<<' ';
        }
        return 0;
}

//stl queue 8ms array queue 4ms
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// int n, k, route[100000], d;
// char buf[600000];
// int chk[100002];
// int bfs() {
//  int que[100000] = { 0, };
//  int f = 0, r = 0, cnt = 0;
//  que[r++] = n;
//  chk[n]=-2;
//  while(f<r){
//      int qsize = r - f; cnt++;
//      while (qsize--) {
//          int w = que[f++];
//          if (w < k && chk[w+1]==-1) {
//              chk[w + 1] = w;
//              if (w + 1 == k) return cnt;
//              que[r++] = w + 1;
//          }
//          if (w > 0 && chk[w - 1]==-1) {
//              chk[w - 1] = w;
//              if (w - 1 == k) return cnt;
//              que[r++] = w - 1;
//          }
//          if (w * 3 <= k * 2 && chk[w * 2]==-1) {
//              chk[w * 2] = w;
//              if (w * 2 == k) return cnt;
//              que[r++] = w * 2;
//          }
//      }
//  }
//  return -1;
// }
// int main() {
//  int i;
//  scanf("%d%d", &n, &k);
//  if (n == k) { printf("0\n%d",k); return 0; }
//  for (i = 0; i < 100002; ++i) chk[i] = -1;
//  int cnt = bfs();
//  int x = k,d=cnt+1;
//  printf("%d\n", cnt);
//  while (x != -2) {
//      route[d--] = x;
//      x = chk[x];
//  }
//  d = 0;
//  for (i = 1; i < cnt+2; ++i) {
//      x = route[i];
//      int tmp = 1;
//      while (tmp*10<=x)tmp*=10;
//      while (tmp) {
//          buf[d++] = '0' + x / tmp;
//          x %= tmp;
//          tmp /= 10;
//      }
//      buf[d++] = ' ';
//  }
//  printf("%s",buf);
// }

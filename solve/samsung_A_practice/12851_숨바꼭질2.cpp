#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
constexpr char ENDL = '\n';
constexpr char SP   = ' ';
const int MAX = 202020;
int dis[MAX + 1];
int cnt[MAX+1];
//1697 숨박꼭질
void bfs(int n, int k) {
        for (int i = 0; i < MAX; i++) dis[i] = 2147000000;
        queue<int> q;
        q.push(n);
        dis[n]=0;
        cnt[n]=1;
        while (!q.empty()) {
                int a = q.front();
                if (dis[a] > dis[k] || a==k)
                        break;
                q.pop();
                if (a-1>=0 && dis[a-1]>=dis[a]+1) {
                        cnt[a - 1] = cnt[a] + cnt[a-1];
                        if(dis[a-1]>dis[a]+1) {
                                q.push(a - 1);
                                dis[a - 1]= dis[a]+1;
                        }
                }
                if (a + 1<MAX && dis[a+1]>=dis[a]+1) {
                        cnt[a + 1] = cnt[a] + cnt[a+1];
                        if(dis[a+1]>dis[a]+1) {
                                q.push(a + 1);
                                dis[a+1]=dis[a]+1;
                        }

                }
                if (2 * a < MAX && dis[a*2]>=dis[a]+1) {
                        cnt[a *2] = cnt[a] + cnt[a*2];
                        if(dis[a*2]>dis[a]+1) {
                                q.push(a *2);
                                dis[a*2]=dis[a]+1;
                        }
                }
        }
}


int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, k;
        cin >> n >> k;
        bfs(n, k);
        cout << dis[k] << endl<<cnt[k]<<endl;
        return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <queue>
//
// #define max_val 100000
//
// using namespace std;
//
// int X = 0, Y = 0;
// int visit[max_val + 1] = { 0, };
// int min_result = 999999;
// int min_cnt = 0;
// int bfs() {
//  int next = 0;
//  int cnt = 0;
//  if (X == Y) {
//      min_result = 0;
//      min_cnt++;
//      return 0;
//  }
//  vector<pair<int, int>> x;
//  queue<pair<int,int>> q;
//  q.push({ X,cnt });
//  while (!q.empty()) {
//      int tmp = q.front().first;
//      int t_cnt = q.front().second;
//      q.pop();
//
//      if (visit[tmp] != 0) { // 이미 방문한 곳
//          if(visit[tmp] < t_cnt)
//              continue;
//      }
//      if (t_cnt + 1 > min_result) {
//          break;
//      }
//
//      visit[tmp] = t_cnt;
//
//      for (int i = 0; i < 3; i++) {
//
//          switch (i) {
//          case 0: next = tmp - 1;
//              break;
//          case 1: next = tmp + 1;
//              break;
//          case 2: next = tmp * 2;
//              break;
//
//          }
//          if (next == Y) {
//              if (min_result >= t_cnt + 1) {
//                  min_result = t_cnt + 1;
//                  min_cnt++;
//                  continue;
//              }
//          }
//
//          if (0 <= next && next <= max_val) {
//              if(visit[next] == false)
//                  q.push({ next, t_cnt+1 });
//          }
//      }
//  }
//  return 0;
// }
//
// int main() {
//  int i = 0, j = 0;
//  scanf("%d %d", &X, &Y);
//  bfs();
//  printf("%d\n", min_result);
//  printf("%d\n", min_cnt);
//  return 0;
// }

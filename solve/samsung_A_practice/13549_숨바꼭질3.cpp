#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
constexpr char ENDL = '\n';
constexpr char SP   = ' ';
const int MAX = 200000;
int dis[MAX + 1];
//1697 숨박꼭질
void bfs(int n, int k) {
        for (int i = 0; i < MAX; i++) dis[i] = 2147000000;
        queue<int> q;
        q.push(n);
        dis[n]=0;
        while (!q.empty()) {
                int a = q.front();
                if (dis[a] > dis[k] || a==k)
                        break;
                q.pop();
                if (a-1>=0 && dis[a-1]>dis[a]+1) {
                        q.push(a - 1);
                        dis[a - 1]= dis[a]+1;
                }
                if (a + 1<MAX && dis[a+1]>dis[a]+1) {
                        q.push(a + 1);
                        dis[a+1]=dis[a]+1;
                }
                if (2 * a < MAX && dis[a*2]>dis[a]) {
                        q.push(a *2);
                        dis[a*2]=dis[a];
                }
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, k;
        cin >> n >> k;
        if(k <= n)
                cout<<n - k;
        else{
                bfs(n, k);
                cout << dis[k];
        }
        return 0;
}

// #include <stdio.h>
// #include <queue>
//
// int main()
// {
//  int n, k;
//  static int visit[200000];
//  scanf("%d%d", &n, &k);
//  if(k <= n) printf("%d\n", n - k);
//  else
//  {
//      std::queue<int> queue;
//      queue.push(n);
//      visit[n] = 1;
//      for(; ; )
//      {
//          int s = queue.front(); queue.pop();
//          int p = visit[s];
//          if(s == k)
//          {
//              printf("%d\n", p - 1);
//              break;
//          }
//          for( ; ; )
//          {
//              if(s > 0 && !visit[s - 1]) queue.push(s - 1), visit[s - 1] = p + 1;
//              if(s < k && !visit[s + 1]) queue.push(s + 1), visit[s + 1] = p + 1;
//              if(s > k || s == 0) break;
//              while(visit[s] && s < k) s <<= 1;
//              if(visit[s]) break;
//              if(s == k) break;
//              visit[s] = p;
//          }
//          if(s == k)
//          {
//              printf("%d\n", p - 1);
//              break;
//          }
//      }
//  }
//  return 0;
// }

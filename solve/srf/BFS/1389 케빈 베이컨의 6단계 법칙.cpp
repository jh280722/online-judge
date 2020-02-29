#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#define MAX 101
#define INF 2147000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { -2,-2,0,0,2,2 };
int dc[] = { -1,1,-2,2,-1,1 };

vi fr[MAX];
bool vis[MAX];
int ans;
int CB = INF;
void bfs(int oidx) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push({ oidx });
	vis[oidx] = true;
	int cabin = 0;
	int lev = 0;
	while (!q.empty()) {
		lev++;
		int qs = q.size();
		while (qs--) {
			int idx = q.front();
			q.pop();

			f(k, fr[idx].size()) {
				if (vis[fr[idx][k]]) continue;
				q.push({ fr[idx][k] });
				vis[fr[idx][k]] = true;
				cabin += lev;
			}
		}
	}
	if (CB > cabin) {
		CB = cabin;
		ans = oidx;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m;
	f(i, m) {
		int a, b;
		cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}
	f(i, n) {
		bfs(i+1);
	}

	cout << ans << '\n';

	return 0;
}
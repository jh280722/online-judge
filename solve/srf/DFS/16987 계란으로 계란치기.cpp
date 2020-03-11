#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#define MAX 4097
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

struct Egg {
	bool broken;
	int s, w;
};
int n, m, k, t;
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
Egg e[9];
int ans;
void dfs(int idx, int cnt) {
	if (idx == n) {
		ans = max(ans, cnt);
		return;
	}
	if (e[idx].broken)
		dfs(idx + 1, cnt);
	else {
		bool flg = false;
		f(i, 0, n) {
			if (i == idx || e[i].broken) continue;
			flg = true;
			e[idx].s -= e[i].w;
			e[i].s -= e[idx].w;
			int ncnt = cnt;
			if (e[idx].s <= 0){
				e[idx].broken = true; ncnt++;
			}
			if (e[i].s <= 0) {
				e[i].broken = true; ncnt++;
			}
			dfs(idx + 1, ncnt);
			e[idx].s += e[i].w;
			e[i].s += e[idx].w;
			e[idx].broken = false;
			e[i].broken = false;
		}
		if (!flg)
			dfs(idx + 1, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	f(i, 0, n) {
		cin >> e[i].s >> e[i].w;
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}

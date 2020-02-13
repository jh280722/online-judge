#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 100001
#define INF 2147483647
typedef long long ll;
using namespace std;

struct DATA {
	int w;
	int v1, v2;
};
int n, m, t, k;
ll ans = 0;
int cnt;

int par[MAX];
int rank_[MAX];
DATA v[MAX * 2];
int Find(int x) {
	if (par[x] == x) {
		return x;
	}
	return par[x] = Find(par[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)
		return false;
	if (rank_[y] > rank_[x]) {
		par[x] = y;
		rank_[x]++;
	}
	else {
		par[y] = x;
		rank_[y]++;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		cnt = 0;
		int e;
		cin >> n >> e;
		for (int i = 1; i <= n; i++) {
			rank_[i] = 0;
			par[i] = i;
		}
		for (int i = 0; i < e; i++) {
			int v1, v2, w;
			cin >> v1 >> v2 >> w;
			v[i] = { w, v1,v2 };
		}

		sort(v, v + e, [](DATA a, DATA b) {return a.w < b.w; });

		for (int i = 0; i < e; i++) {
			int w = v[i].w;
			int v1 = v[i].v1, v2 = v[i].v2;
			if (Union(v1, v2)) {
				ans += w;
				cnt++;
				if (cnt == n - 1)
					break;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
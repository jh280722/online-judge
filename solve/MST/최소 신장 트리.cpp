#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 10001
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
struct DATA {
	int w;
	int v1, v2;
};
int dr[] = { -1,0,0,1 };
int dc[] = { 0,-1,1,0 };
int cnt;

int par[MAX];
int rank_[MAX];

int Find(int x) {
	if (par[x] == x) {
		return x;
	}
	return par[x]=Find(par[x]);
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
	int e;
	cin >> n >> e;
	for (int i = 1; i <= n; i++)
		par[i] = i;
	vector < pair<int, pair<int, int>>> v;
	for (int i = 0; i < e; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		v.push_back({ w,{v1,v2} });
	}
	sort(all(v));

	for (int i = 0; i < v.size(); i++) {
		int v1 = v[i].second.first, v2 = v[i].second.second;
		int w = v[i].first;
		if (Union(v1, v2)) {
			ans += w;
			cnt++;
			if (cnt == n - 1)
				break;
		}
	}

	cout << ans << '\n';
	return 0;
}
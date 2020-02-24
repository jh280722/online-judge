#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#define MAX 1000001
#define INF 2147000000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j,l) for(int i=0;i<j;i+=l)
using namespace std;

int n, m, k, t;
ll ans = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int v[MAX];
pair<int, int> seg[MAX * 4];

void init(int idx, int l, int r) {
	if (l != r) {
		init(idx << 1, l, (l + r) >> 1);
		init(idx << 1 | 1, ((l + r) >> 1) + 1, r);
		seg[idx].first = min(seg[idx << 1].first, seg[idx << 1 | 1].first);
		seg[idx].second = max(seg[idx << 1].second, seg[idx << 1 | 1].second);
	}
	else {
		seg[idx].first = v[l];
		seg[idx].second = v[l];
	}
}

void update(int idx, int l, int r, int i, int val) {
	if (i<l || i>r) return;
	if (l == r) {
		seg[idx].first = val;
		seg[idx].second = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(idx << 1, l, mid, i, val);
	update(idx << 1 | 1, mid + 1, r, i, val);
	seg[idx].first = min(seg[idx << 1].first, seg[idx << 1 | 1].first);
	seg[idx].second = max(seg[idx << 1].second, seg[idx << 1 | 1].second);
}

ll getmin(int idx, int l, int r, int i, int j) {
	if (r < i || l > j) return 1000000001;
	if (i <= l && r <= j) return seg[idx].first;

	int mid = (l + r) >> 1;
	return min(getmin(idx << 1, l, mid, i, j), getmin(idx << 1 | 1, mid + 1, r, i, j));
}
ll getmax(int idx, int l, int r, int i, int j) {
	if (r < i || l > j) return -1;
	if (i <= l && r <= j) return seg[idx].second;

	int mid = (l + r) >> 1;

	return max(getmax(idx << 1, l, mid, i, j), getmax(idx << 1 | 1, mid + 1, r, i, j));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << getmin(1, 1, n, a, b) << ' ' << getmax(1, 1, n, a, b) << '\n';
	}
	return 0;
}
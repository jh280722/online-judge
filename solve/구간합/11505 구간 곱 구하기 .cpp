#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 1000001
#define INF 214700000
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
ll seg[MAX * 4];

void init(int idx, int l, int r) {
	if (l != r) {
		init(idx << 1, l, (l + r) >> 1);
		init(idx << 1 | 1, ((l + r) >> 1) + 1, r);
		seg[idx] = (seg[idx << 1] * seg[idx << 1 | 1]) % 1000000007;
	}
	else
		seg[idx] = v[l];
}

void update(int idx, int l, int r, int i, int val) {
	if (i<l || i>r) return;
	if (l == r) {
		seg[idx] = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(idx << 1, l, mid, i, val);
	update(idx << 1 | 1, mid + 1, r, i, val);
	seg[idx] = (seg[idx << 1] * seg[idx << 1 | 1]) % 1000000007;
}

ll getval(int idx, int l, int r, int i, int j) {
	if (r < i || l > j) return 1;
	if (i <= l && r <= j) return seg[idx];

	int mid = (l + r) >> 1;
	return (getval(idx << 1, l, mid, i, j) % 1000000007) * (getval(idx << 1 | 1, mid + 1, r, i, j) % 1000000007);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else {
			cout << getval(1, 1, n, b, c) % 1000000007 << '\n';
		}
	}
	return 0;
}
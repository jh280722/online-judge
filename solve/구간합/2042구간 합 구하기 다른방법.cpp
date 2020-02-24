#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 1000001
#define INF 214700000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j,l) for(int i=0;i<=j;i+=l)
using namespace std;

int n, m, k, t;
ll ans = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int v[MAX];
ll seg[MAX * 2];

void init() {
	for (int i = n - 1; i > 0; i--)
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

void update(int idx, ll val) {
	for (seg[idx += n - 1] = val; idx > 1; idx >>= 1)
		seg[idx >> 1] = seg[idx] + seg[idx ^ 1];
}

ll getval(int l, int r) {
	long long ans = 0LL;
	for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1LL) ans += seg[l++];
		if (r & 1LL) ans += seg[--r];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> seg[n + i];
	}
	init();
	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else {
			cout << getval(b, c) << '\n';
		}
	}
	return 0;
}
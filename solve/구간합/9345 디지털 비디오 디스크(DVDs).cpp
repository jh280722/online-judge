#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 998244353
#define MOD2 1000000021
#define INF 1e9
#define N 100001
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); };
int n, m, k, t;
int dr[] = { 0,0,1,-1, -1,1,1,-1 };
int dc[] = { -1,1,0,0, 1,1,-1,-1 };

pii seg[4 * N];
int seq[N];

void init(int idx, int l, int r) {
	if (l == r) {
		seg[idx].first = l;
		seg[idx].second = l;
		seq[l] = l;
	}
	else {
		init(idx << 1, l, (l + r) >> 1);
		init(idx << 1 | 1, ((l + r) >> 1) + 1, r);
		seg[idx].first = min(seg[idx << 1].first, seg[idx << 1 | 1].first);
		seg[idx].second = max(seg[idx << 1].second, seg[idx << 1 | 1].second);
	}
}

void update(int idx, int l, int r, int i, int val) {
	if (i > r || i < l) return;
	if (l == r) {
		seg[idx].first = seq[val];
		seg[idx].second = seq[val];
		return;
	}
	int mid = (l + r) >> 1;
	update(idx << 1, l, mid, i, val);
	update(idx << 1 | 1, mid + 1, r, i, val);
	seg[idx].first = min(seg[idx << 1].first, seg[idx << 1 | 1].first);
	seg[idx].second = max(seg[idx << 1].second, seg[idx << 1 | 1].second);
}

int getval(int idx, int l, int r, int i, int j, bool type) {
	if (r < i || l > j) {
		if (!type)
			return INF;
		else
			return -1;
	}
	if (i <= l && r <= j) {
		if (!type)
			return seg[idx].first;
		else
			return seg[idx].second;
	}

	int mid = (l + r) >> 1;

	if (!type)
		return min(getval(idx << 1, l, mid, i, j, type), getval(idx << 1 | 1, mid + 1, r, i, j, type));
	else
		return max(getval(idx << 1, l, mid, i, j, type), getval(idx << 1 | 1, mid + 1, r, i, j, type));
}

int main() {
	SYNC;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		init(1, 1, n);
		while (k--) {
			int q, a, b;
			cin >> q >> a >> b;
			a++, b++;
			if (q) {
				if (getval(1, 1, n, a, b, 0) == a && getval(1, 1, n, a, b, 1) == b)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
			else {
				update(1, 1, n, a, b);
				update(1, 1, n, b, a);
				swap(seq[a], seq[b]);
			}
		}
	}
	return 0;
}

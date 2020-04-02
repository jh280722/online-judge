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

int A[N];
int B[N];
ll seg[4 * N];

void init(int idx, int l, int r) {
	if (l != r) {
		init(idx << 1, l, (l + r) >> 1);
		init(idx << 1 | 1, ((l + r) >> 1) + 1, r);
		seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
	}
	else
		seg[idx] = B[l];
}

void update(int idx, int l, int r, int i, int val) {
	if (r < i || i < l) return;
	if (l == r) {
		seg[idx] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(idx << 1, l, mid, i, val);
	update(idx << 1 | 1, mid + 1, r, i, val);
	seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
}

ll getval(int idx, int l, int r, int s, int e) {
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) {
		return seg[idx];
	}
	int mid = (l + r) >> 1;
	return getval(idx << 1, l, mid, s, e) + getval(idx << 1 | 1, mid + 1, r, s, e);
}

//구간에 v를 더하고 한 점의 값을 받아오는 쿼리는 
//한 점에 v를 더하고 구간의 합을 받아오는 쿼리로 바꿀 수 있다.
//1.[a, b]에 v를 더하는 쿼리를, a에 v를 더하는 쿼리와 b + 1에 - v를 더하는 쿼리로 변경
//2. x의 값을 구하는 쿼리를, 처음부터 x까지의 구간 합을 구하는 쿼리로 변경
int main() {
	SYNC;
	cin >> n;
	fu(i, 1, n + 1)
		cin >> A[i];
	fu(i, 1, n + 1) {
		B[i] = A[i] - A[i - 1];
	}
	init(1, 1, n);
	cin >> k;
	while (k--) {
		int q, a, b, val;
		cin >> q;
		if (q == 2) {
			cin >> a;
			cout << getval(1, 1, n, 1, a) << '\n';
		}
		else {
			cin >> a >> b >> val;
			update(1, 1, n, a, val);
			update(1, 1, n, b + 1, -val);
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1e9+9
#define MOD2 1000000021
#define INF 1e9
#define N 41
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
int dr[] = { 1,0,-1,0, -1,1,1,-1 };
int dc[] = { 0,1,0,-1, 1,1,-1,-1 };

struct SK {
	int n, m;
	int Map[N][N];
};

int ans;
int Map[N][N];
SK sk[101];
int rot[N][N];

void rotate(int k) {
	memcpy(rot, sk[k].Map, sizeof rot);
	int n = sk[k].n;
	int m = sk[k].m;
	fu(i, 1, m + 1) {
		fu(j, 1, n + 1) {
			sk[k].Map[i][j] = rot[n + 1 - j][i];
		}
	}
	swap(sk[k].n, sk[k].m);
}

bool stick(int k) {
	int sn = sk[k].n, sm = sk[k].m;
	int i, j;
	bool flg = true;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			flg = true;
			fu(l, 1, sn + 1) {
				fu(d, 1, sm + 1) {
					if (i + l - 1 <= 0 || i + l - 1 > n || j + d - 1 <= 0 || j + d - 1 > m) {
						flg = false;
						break;
					}
					if (sk[k].Map[l][d] == 1 && Map[i + l - 1][j + d - 1] == 1) {
						flg = false;
						break;
					}
				}
				if (!flg)
					break;
			}
			if (flg) {
				break;
			}
		}
		if (flg) {
			break;
		}
	}
	if (!flg)
		return false;
	else {
		fu(l, 1, sn + 1) {
			fu(d, 1, sm + 1) {
				if (sk[k].Map[l][d] == 1) {
					ans++;
					Map[i + l - 1][j + d - 1] = 1;
				}
			}
		}
		return true;
	}
}


int main() {
	SYNC;
	cin >> n >> m >> k;
	fu(i, 0, k) {
		int sn, sm;
		cin >> sn >> sm;
		sk[i].n = sn, sk[i].m = sm;
		fu(j, 1, sn + 1) {
			fu(l, 1, sm + 1) {
				cin >> sk[i].Map[j][l];
			}
		}
		if ((sn > n&& sn > m) || (sm > n&& sm > m))
			continue;

		for (int j = 0; j < 4; j++) {
			if (stick(i))
				break;
			rotate(i);
		}
	}

	cout << ans;

	return 0;
}
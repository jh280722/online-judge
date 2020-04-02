#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000009
#define MOD2 1000000021
#define INF 1000000000
#define N 200001
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
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

ll pre1[1000001], suf1[1000001];
ll pre2[1000001], suf2[1000001];
ll p1[1000001], p2[1000001];

bool pal(int l, int r)
{
	int len = r - l + 1;
	pll T1, T2;
	T1.first = (pre1[r] - pre1[l - 1] * p1[len]) % MOD;
	T1.second = (pre2[r] - pre2[l - 1] * p2[len]) % MOD2;
	if (T1.first < 0)T1.first += MOD;
	if (T1.second < 0)T1.second += MOD2;
	T2.first = (suf1[l] - suf1[r + 1] * p1[len]) % MOD;
	T2.second = (suf2[l] - suf2[r + 1] * p2[len]) % MOD2;
	if (T2.first < 0)T2.first += MOD;
	if (T2.second < 0)T2.second += MOD2;
	return T1 == T2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	p1[0] = p2[0]= 1;
	fu(i, 1, 1000001)
	{
		p1[i] = (p1[i - 1] * 29) % MOD;
		p2[i] = (p2[i - 1] * 32) % MOD2;
	}
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		n = s.size();
		if (n == 1) {
			cout << s << '\n';
			continue;
		}
		int k = 0;
		fu(i, 0, n / 2) {
			if (s[i] == s[n - i - 1]) {
				k++;
			}
			else {
				break;
			}
		}
		string p = s.substr(0, k);
		s = " " + s.substr(k, n - 2 * k);
		n = s.size() - 1;
		string mid;
		pre1[0] = suf1[n + 1] = 0;
		pre2[0] = suf2[n + 1] = 0;
		ll key;
		fu(i, 1, n + 1) {
			pre1[i] = ((pre1[i - 1] * 29) + s[i] - 'a' + 1) % MOD;
			pre2[i] = ((pre2[i - 1] * 32) + s[i] - 'a' + 1) % MOD2;
		}
		fd(i, n, 1) {
			suf1[i] = ((suf1[i + 1] * 29) + s[i] - 'a' + 1) % MOD;
			suf2[i] = ((suf2[i + 1] * 32) + s[i] - 'a' + 1) % MOD2;
		}
		int l = 0, r = n;
		suf1[n + 1] = suf2[n + 1] = 0;
		fd(i, n, 1) {
			if (pal(1, i)) {
				r = i;
				break;
			}
		}
		pre1[0] = pre2[0] = 0;
		fu(i, 1, n + 1) {
			if (pal(i, n)) {
				l = i;
				break;
			}
		}
		if (n - l > r - 1) {
			mid = s.substr(l, n);
		}
		else
			mid = s.substr(1, r);
		string ans = p + mid;
		reverse(all(p));
		cout << ans + p << '\n';
	}
	return 0;
}

#include <bits/stdc++.h>
#define MAX 501
#define MOD 1000000
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m, k, t;
int dr[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int ans;
int Max = -INF, Min = INF;

int dp[2001][2001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, l, r;
	cin >> n >> h >> l >> r;
	vi a(n+1);
	int sum = 0;
	fu(i, 1, n+1) {
		cin >> a[i];
		fu(j, 0, i + 1) {
			int tmp = (h + sum - j + a[i])%h;
			int ptmp = (h + tmp - a[i]) % h;
			if (l <= tmp && tmp <= r) {
				dp[i][tmp] = max(dp[i - 1][ptmp], dp[i - 1][(ptmp + 1) % h]) + 1;
			}
			else {
				dp[i][tmp] = max(dp[i - 1][ptmp],dp[i-1][(ptmp + 1) % h]);
			}
		}
		sum += a[i];
		sum %= h;
	}
	Max = *max_element(dp[n], dp[n] + h);
	cout << Max;
	return 0;
}
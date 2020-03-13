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
#define fd(i,a,j) for(int i=a-1;i>=j;i--)
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m, k, t;
int dr[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int ans;
int Max = -INF, Min = INF;
int dp[1001][2][3];

int f(int date, int late, int absence) {
	if (late == 2) return 0;
	else if (absence == 3) return 0;

	if (date == n) return 1;

	int& ret = dp[date][late][absence];
	if (ret != -1) return ret;
	ret = f(date + 1, late + 1, 0) + f(date + 1, late, absence + 1) + f(date + 1, late, 0);

	return ret % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, 0);
	return 0;
}

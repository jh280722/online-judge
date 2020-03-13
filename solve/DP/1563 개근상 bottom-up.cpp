#include <bits/stdc++.h>
#define MAX 501
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m, k, t;
int dr[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int ans;
int Max = -INF, Min = INF;
int d[1001][2][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	d[0][0][0] = 1;
	d[0][1][0] = 1;
	d[0][0][1] = 1;
	f(i, 1, n) {
		d[i][0][0] = d[i - 1][0][0] + d[i - 1][0][1] + d[i - 1][0][2];
		d[i][0][1] = d[i - 1][0][0];
		d[i][0][2] = d[i - 1][0][1];
		d[i][1][0] = d[i - 1][0][0] + d[i - 1][0][1] + d[i - 1][0][2];
		d[i][1][0] += d[i - 1][1][0] + d[i - 1][1][1] + d[i - 1][1][2];
		d[i][1][1] = d[i - 1][1][0];
		d[i][1][2] = d[i - 1][1][1];

		f(j, 0, 2) {
			f(k, 0, 3) {
				d[i][j][k] %= 1000000;
			}
		}
	}
	ll sum = 0;
	f(i, 0, 2) {
		f(j, 0, 3) {
			sum += d[n - 1][i][j]%1000000;
		}
	}
	cout << sum % 1000000;

	return 0;
}

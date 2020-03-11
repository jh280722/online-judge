#include <bits/stdc++.h>
#define MAX 1001
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0, 1, -1, 0, 0 };
int dc[] = { 0, 0, 0, -1, 1 };
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		vi a(n);
		f(i, 0, n) {
			cin >> a[i];
		}
		sort(all(a),greater<int>());
		f(i, 0, n)
			cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}

#include <bits/stdc++.h>
#define MAX 4097
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int sum = 0;
		f(i, 0, n) {
			int a;
			cin >> a;
			sum += a;
		}
		cout << min(m, sum) << '\n';
	}
	return 0;
}

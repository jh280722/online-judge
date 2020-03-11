#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define MAX 17
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
ll ans;
int b[200001];
int c[200001];
map<int, ll> sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	f(i, 0, n) {
		cin >> b[i];
		c[i] = b[i] - i;
	}
	f(i, 0, n) {
		sum[c[i]] += b[i];
		if (ans < sum[c[i]])
			ans = sum[c[i]];
	}
	cout << ans;
	return 0;
}
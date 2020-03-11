#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
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
int ans;
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vi a(n);
	int e=0;
	int sum = 0;
	f(i, 0, n) {
		cin >> a[i];
		sum += a[i];
		while (sum > m)
			sum -= a[e++];

		ans += sum == m;
	}
	cout << ans;
	return 0;
}
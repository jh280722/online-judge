#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
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
int ans;
int map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vi ri(n), bi(n);
	f(i, 0, n) {
		cin >> ri[i];
	}
	int cnt = 0;
	int num = 0;
	f(i, 0, n) {
		cin >> bi[i];
		if (ri[i] && bi[i]) continue;
		if (!ri[i] && !bi[i]) continue;
		if (!ri[i] && bi[i]) num++;
		if (ri[i] && !bi[i]) cnt++;
	}
	if (cnt == 0)
		ans = -1;
	else {
		ans= num / cnt +1;
	}
	cout << ans;
	return 0;
}
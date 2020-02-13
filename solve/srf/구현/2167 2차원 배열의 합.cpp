#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 100001
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
ll ans = 0;
int map[301][301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	}
	cin >> k;
	int sr, sc, dr, dc;
	for (int t = 0; t < k; t++) {
		int sum = 0;
		cin >> sr >> sc >> dr >> dc;
		for (int i = sr; i <= dr; i++) {
			for (int j = sc; j <= dc; j++) {
				sum+= map[i][j];
			}
		}
		cout << sum << '\n';
	}

	return 0;
}
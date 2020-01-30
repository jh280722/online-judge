#include <iostream>
#include <stack>
#define MAX 101
#define INF 214700000
typedef long long ll;
using namespace std;

int n, t, ans;
char map[MAX][MAX];
int dis[MAX][MAX];

struct DATA {
	int h, idx;
};

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

int b[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	t = 10;
	for (int tc = 0; tc < t; tc++) {
		ans = 0;
		cin >> n;
		int r=0, l=0, max=0;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			if (i >=2) {
				l = b[i - 1] > b[i - 2] ? b[i - 1] : b[i - 2];
				r = b[i + 1] > b[i + 2] ? b[i + 1] : b[i + 2];
				max = l > r ? l : r;
				if (b[i] - max > 0) {
					ans += b[i] - max;
				}
			}
		}
		cout << '#' << tc + 1 << ' ' << ans << '\n';
	}
	return 0;
}
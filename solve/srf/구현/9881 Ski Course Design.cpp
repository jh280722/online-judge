#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define MAX 51
using namespace std;

int n, m;
int ans;

struct DATA {
	int r, c;
};

int ski[1001];

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	//가장 높은 언덕과 가장 낮은 언덕이 17보다 커야한다. 그럼 세금을 낸다
	//언덕 높이를 x만큼 바꾸는데 x^2만큼 돈이 든다.
	//지불해야할 최소금액
	for (int i = 0; i < n; i++) {
		cin >> ski[i];
	}
	sort(ski, ski + n);
	if (ski[n - 1] - ski[0] > 17) {
		ans = INF;
		for (int kmin = ski[0]; kmin <= ski[n - 1] && ski[n - 1] - kmin > 17; kmin++) {
			int kmax = kmin + 17;
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				if (ski[i] > kmax) {
					tmp += (kmax - ski[i]) * (kmax - ski[i]);
				}
				else if (ski[i] < kmin) {
					tmp += (ski[i] - kmin) * (ski[i] - kmin);
				}
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << '\n';
	return 0;
}

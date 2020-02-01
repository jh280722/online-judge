#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
using namespace std;

int n, m, k;
int ans;

int sum[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	// 2,000,000 이동가능
	int maxX = 0;
	for (int i = 0; i < n; i++) {
		int num, x;
		cin >> num >> x;
		if (maxX < x)
			maxX = x;
		sum[x] = num;
	}

	k = 2 * k + 1;
	int cnt = 0;
	for (int i = 0; i < k && i <= 1000000; i++) {
		cnt += sum[i];
	}//최소 sum
	ans = cnt;
	for (int i = 0; i + k <= 1000000; i++) {
		cnt += sum[i + k] - sum[i];
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}

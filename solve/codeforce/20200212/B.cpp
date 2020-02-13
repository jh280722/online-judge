#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
ll ans = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
int map[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	//좋은 계절이 시작될때 수리 시작, 나쁜날 수리는 나쁜 품질
	//절반이상이 고품질 수리를 완료하는데 최소 일자
	for (int tc = 0; tc  < t; tc++) {
		ans = 0;
		int n, g, b;//good bad
		cin >> n >> g >> b;
		ll remain = n/2;
		if (n % 2 == 1)
			remain++;
		//g day b day 반복
		if (remain <= g) {
			cout << n << '\n';
			continue;
		}

		ll cnt=remain / g;
		ans += cnt * (g + b);
		if (remain % g == 0)
			ans -= b;
		else {
			ans += remain % g;
		}
		if (ans <= n)
			ans += n - ans;

		cout << ans << '\n';
	}
	return 0;
}
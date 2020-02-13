#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#define all(v) v.begin(), v.end()
#define MAX 100001
#define INF 2147483647
#define PIE 3.14159265359
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
char map[31][31];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	bool ma = false, mb = false;
	bool minus = false;
	if (a[0] == '-')
		a = a.substr(1, a.size()), ma = true;
	if (b[0] == '-')
		b = b.substr(1, b.size()), mb = true;
	string ans = "";
	int ai = a.size() - 1, bi = b.size() - 1;
	n = ai, m = bi;
	if (ma && n > m && !mb) {
		ma = false, mb = true;
		minus = true;
	}
	else if (!ma && n < m && mb) {
		ma = true, mb = false;
		minus = true;
	}
	else if (ma && mb) {
		ma = false, mb = false;
		minus = true;
	}
	else if (n == m) {
		bool abig = false;
		bool bbig = false;
		for (int i = 0; i <= n; i++) {
			if (a[i] > b[i]) {
				abig = true;
				break;
			}
			else if (a[i] < b[i]) {
				bbig = true;
				break;
			}
		}
		if (mb && bbig) {
			mb = false, ma = true, minus = true;
		}
		else if (ma && abig) {
			mb = true, ma = false, minus = true;
		}
	}
	int c = 0;
	while (ai >= 0 || bi >= 0) {
		int n1 = 0, n2 = 0;
		if (bi >= 0)
			n2 = b[bi] - '0';
		if (ai >= 0)
			n1 = a[ai] - '0';
		if (ma && !mb)
			n1 = -n1;
		if (!ma && mb)
			n2 = -n2;
		if (n1 + n2 + c > 9) {
			ans += (n1 + n2 + c - 10) + '0';
			c = 1;
		}
		else if (n1 + n2 + c < 0) {
			if (ai != 0 || bi != 0)
				ans += (n1 + n2 + c + 10) + '0';
			else
				ans += -(n1 + n2) + '0';
			c = -1;
		}
		else {
			ans += (n1 + n2 + c) + '0';
			c = 0;
		}
		ai--, bi--;
	}
	if (c)
		ans += '1';
	reverse(all(ans));
	while (1) {
		if (ans.size() == 1)
			break;
		if (ans[0] != '0') {
			break;
		}
		else {
			ans = ans.substr(1, ans.size());
		}
	}
	if (minus)
		cout<<'-';
	cout << ans << '\n';
	return 0;
}
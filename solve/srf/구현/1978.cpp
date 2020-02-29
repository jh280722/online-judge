#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> s;
	while (n--) {
		int a;
		cin >> a;
		s.push_back(a);
	}
	int cnt = 0;
	for (auto i : s) {
		int ch = 0;
		for (int j = 1; j <= i; j++) {
			if (i%j == 0) {
				ch++;
			}
		}
		if (ch == 2)
			cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int s[100000];
char ans[200000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int p = 0, q = 0, k = 0;
    int a;
	for (int i = 0; i < n; i++) {
        cin>>a;
		while (q < a) {
			s[p++] = ++q;
			ans[k++] = '+';
		}
		if (s[--p] != a) {
			cout << "NO\n";
			return 0;
		}
		ans[k++] = '-';
	}
	for (int i = 0; i < k; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}

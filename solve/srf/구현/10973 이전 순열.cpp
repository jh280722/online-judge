#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <string>
#include <bitset>
typedef long long ll;
using namespace std;
bool prev_permutation(vector<int> &a) {
	int n = a.size() - 1;
	int i = n;
	int j = n;
	while (i > 0 && a[i - 1] <= a[i])
		i--;
	if (i <= 0) return false;
	while (a[j] > a[i-1]) j--;
	if (j <= 0) return false;
	swap(a[i-1], a[j]);
	j = n;
	while (j > i) {
		swap(a[i], a[j]);
		i++; j--;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (prev_permutation(a)) {
		for (auto i : a)
			cout << i << ' ';
	}
	else
		cout << "-1\n";
	return 0;
}
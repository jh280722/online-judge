#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//1654번 랜선 자르기
int n;
bool num(vector<ll> &a, ll x) {
	int sum = 0;
	for (auto i : a) {
		sum+=i / x;
	}
	return sum >= n;
}
int binary_search(vector<ll> &a) {
	ll ans = 0;
	ll left = 1;
	ll right = *max_element(a.begin(), a.end());
	ll mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num(a, mid)) {
			left = mid + 1; 
			if (ans < mid) {
				ans = mid;
			}
		}
		else {
			right = mid-1;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k >> n;
	vector<ll> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	cout << binary_search(a);

	return 0;
}

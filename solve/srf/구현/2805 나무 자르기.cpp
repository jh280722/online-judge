#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define all(v) v.begin(), v.end()
#define MAX 201
#define INF 1000000000
using namespace std;
typedef long long ll;

struct POINT {
	int r, c;
};

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

ll n, m, k, t;
ll ans;
int tree[1000001];

int bs() {
	ll l = 0, r = *max_element(tree,tree+n);
	ll ans = 0;
	ll h;
	while (l <= r) {
		h = (l + r) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > h)
				sum += tree[i] - h;
		}
		if (sum >= m) {
			l = h + 1;
			if (ans < h) {
				ans = h;
			}
		}
		else
			r = h-1;
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	cout << bs();

	return 0;
}

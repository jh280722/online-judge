#include <iostream>
#include <algorithm>
#include <queue>
#define all(v) v.begin(), v.end()
#define MAX 201
#define INF 1000000000
using namespace std;
typedef long long ll;

struct POINT {
	int c, r;
};

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int n, m, k, t;
int ans;
int v[2001];

int sum() {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i];
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int tsum = sum();
		if (tsum % 2 == 1) {
			cout << "YES" << '\n';
			continue;
		}
		bool possible = false;
		for (int i = 0; i < n; i++) {
			if (v[i] % 2 == 1) {
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (v[j] % 2 == 0) {
						possible = true;
						break;
					}
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (v[j] % 2 == 1) {
						possible = true;
						break;
					}
				}
			}
			if (possible) {
				break;
			}
		}

		if (possible) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}


	return 0;
}

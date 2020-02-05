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
int pow(int a, int b) {
	if (b == 0)
		return 1;
	while (--b) {
		a *= a;
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--) {
		cin >> n;
		int money = n;
		int buy = 0;
		while (money/10) {
			int cashback = money / 10;
			buy += money - money%10;
			money -= money - money % 10;
			money += cashback;
		}
		buy += money;
		cout << buy << '\n';
	}

	return 0;
}

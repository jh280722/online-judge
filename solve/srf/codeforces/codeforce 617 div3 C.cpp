#include <iostream>
#include <algorithm>
#include <queue>
#define all(v) v.begin(), v.end()
#define MAX 201
#define INF 1000000000
using namespace std;
typedef long long ll;

struct POINT {
	int x, y;
};

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int n, m, k, t;
bool ans;

POINT cal(string s) {
	int x = 0, y = 0;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'L':
			x--;
			break;
		case 'R':
			x++;
			break;
		case 'U':
			y++;
			break;
		case 'D':
			y--;
			break;
		}
	}
	return { x,y };
}

POINT sum[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		POINT p;
		p = cal(s);
		int x = p.x;
		int y = p.y;
		int l = 0, r = 0;
		int size = s.size();

		for (int i = 0; i < size; i++) {
			sum[i+1] = sum[i];
			switch (s[i]) {
			case 'L':
				sum[i].x--;
				break;
			case 'R':
				sum[i].x++;
				break;
			case 'U':
				sum[i].y++;
				break;
			case 'D':
				sum[i].y--;
				break;
			}
		}

		for (int i = 0; i <= size; i++) {
			for (int j = 0; j < i; j++) {
				if (i == j)continue;
				if (sum[i].x - sum[j].x == x && sum[i].y - sum[j].y == y) {
					l = j + 1; r = i + 1;
					ans = true;
					break;
				}
			}
		}
		if (ans)
			cout << l << ' ' << r << '\n';
		else
			cout << -1 << '\n';

	}

	return 0;
}

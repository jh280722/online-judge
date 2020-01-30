#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point {
	int x, y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	point() {
	}
};

const int MAX = 103;
const int INF = 2147000000;
point a[MAX];
bool ch[MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;

bool BFS() {
	queue<int> q;
	q.push(0);
	ch[0] = true;
	while (!q.empty()) {
		int ind=q.front();
		q.pop();
		for (int i = 1; i < n + 2; i++) {
			if (ch[i])
				continue;
			if ((abs(a[ind].x - a[i].x) + abs(a[ind].y - a[i].y)) <= 1000) {
				if (i == n + 1)
					return true;
				ch[i] = true;
				q.push(i);
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(ch, false, sizeof(ch));
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			cin >> a[i].x >> a[i].y;
		}
		if(BFS())
			cout << "happy" << '\n';
		else
			cout << "sad" << '\n';
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#define all(v) v.begin(), v.end()
#define MAX 301
#define INF 1000000000
using namespace std;
typedef long long ll;

struct POINT {
	int r, c;
};

int n, m, v, t;
int A[MAX][MAX]; //H * W 
int B[MAX+ MAX][MAX+MAX]; // H+x * W+y

int dr[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dc[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w, x, y;
	cin >> h >> w >> x >> y;

	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (x <= i && y <= j) {
				if (B[i][j] != 0) {
					A[i][j] += B[i][j]-A[i-x][j-y];
				}
			}
			else {
				A[i][j] += B[i][j];
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

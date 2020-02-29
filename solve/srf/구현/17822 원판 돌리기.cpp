#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#define MAX 51
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0, 0, -1,1 };
int dc[] = { 1,-1,0,0 };
int ans;
int map[MAX][MAX];
int total;
int cnt;

void rotate(int x, int dir, int k) {
	int tmp[MAX];
	for (int i = x; i <= n; i += x) {
		memcpy(tmp, map[i - 1], sizeof tmp);
		if (dir == 0) { //시계방향
			for (int j = 0; j < m; j++) {
				map[i - 1][j] = tmp[(m + j - k) % m];
			}
		}
		else { //반시계
			for (int j = 0; j < m; j++) {
				map[i - 1][j] = tmp[(j + k) % m];
			}
		}
	}
}

void same() {
	//(i, j)는(i, j - 1), (i, j + 1)과 인접하다. (2 ≤ j ≤ M - 1)
	//(i, j)는(i - 1, j), (i + 1, j)와 인접하다. (2 ≤ i ≤ N - 1)
	set<pii> idx;
	f(i, 0, n) {
		f(j, 0, m) {
			if (map[i][j] != 0) {
				int tmp = map[i][j];
				if (i - 1 >= 0 && tmp == map[i - 1][j]) {
					idx.insert({ i,j });
					idx.insert({ i - 1,j });
				}
				if (i + 1 < n && tmp == map[i + 1][j]) {
					idx.insert({ i,j });
					idx.insert({ i + 1,j });
				}
				if (tmp == map[i][(m + j - 1) % m]) {
					idx.insert({ i,j });
					idx.insert({ i,(m + j - 1) % m });
				}
				if (tmp == map[i][(j + 1) % m]) {
					idx.insert({ i,j });
					idx.insert({ i,(j + 1) % m });
				}
			}
		}
	}
	if (idx.size() == 0) {
		if (cnt == 0)
			return;
		double avg = (double)total / cnt;
		f(i, 0, n) {
			f(j, 0, m) {
				if (map[i][j] != 0) {
					if (map[i][j] > avg) {
						map[i][j]--;
						total--;
					}
					else if (map[i][j] < avg) {
						map[i][j]++;
						total++;
					}
				}
			}
		}
	}
	else {
		cnt -= idx.size();
		for (auto i = idx.begin(); i != idx.end(); i++) {
			total -= map[(*i).first][(*i).second];
			map[(*i).first][(*i).second] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> t;
	cnt = n * m;
	f(i, 0, n) {
		f(j, 0, m) {
			cin >> map[i][j];
			total += map[i][j];
		}
	}
	f(i, 0, t) {
		int x, d, k; //d 0 시계방향 1 반시계 k 칸 움직임
		cin >> x >> d >> k;
		rotate(x, d, k);
		same();
	}
	cout << total;

	return 0;
}
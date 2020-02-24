#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 214700000
typedef long long ll;
using namespace std;

int n, t, ans;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dis[MAX][MAX];

struct DATA {
	int r, c;
};

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

void floyWarshall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = map[i][j];
			if (map[i][j] == 0)
				dis[i][j] = INF;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	floyWarshall();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dis[i][j]!=INF)
				cout << 1 << ' ';
			else
				cout<< 0 <<' ';
		}
		cout << '\n';
	}
	return 0;
}
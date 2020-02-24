#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 214700000
typedef long long ll;
using namespace std;

int n, m, t, ans;
int graph[MAX][MAX];
int dis[MAX][MAX];

struct DATA {
	int r, c;
};

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

void floyWarshall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = graph[i][j];
			if (graph[i][j] == 0)
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (graph[u - 1][v - 1] == 0)
			graph[u - 1][v - 1] = w;
		else if (graph[u - 1][v - 1] > w) {
			graph[u - 1][v - 1] = w;
		}
	}
	floyWarshall();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && dis[i][j] != INF)
				cout << dis[i][j] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
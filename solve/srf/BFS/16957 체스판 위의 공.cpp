#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 501
#define INF 1000000000
using namespace std;
typedef long long ll;

struct BALL {
	int n;
	pair<int,int> rc;
};

int n, m, v, t;
int map[MAX][MAX];
int ball[MAX][MAX];

int dr[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dc[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

//ü������ �� ĭ ���� ���� �ϳ��� ���´�.���� ���� ������ ���� ��Ģ�� ���ؼ� �ڵ����� �����δ�.
//������ 8����(����, ����, �밢��)�� ���� ��� ������ ���� ĭ�� ���� ������ ũ�� �̵��� �����.
//�� ���� ��쿡�� ���� ���� ������ �ִ� ĭ���� ���� �̵��Ѵ�.
//���� ũ��� �ſ� �۾Ƽ�, ü������ �� ĭ ���� ���� ���� ���� ���� �� �ִ�.ü������ ���°� �־�����.
//���� �� �̻� �������� ���� ��, �� ĭ�� ���� �� �� �ִ��� ���غ���

//���� �������� �ٸ������� ���µ� ���� ������ ���Ƿ� �켱���� ť�� ���� �ѹ����� ���Ѵ�.
priority_queue<pair<int,pair<int,int>>> q;
void bfs() {
	while (!q.empty()) {
		int num = q.top().first;
		int r = q.top().second.first;
		int c = q.top().second.second;
		q.pop();
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ball[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
		int min = num;
		bool ch = false;
		int cr, cc;
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (min > map[nr][nc]) {
				ch = true;
				min = map[nr][nc];
				cr = nr;
				cc = nc;
			}
		}
		if (ch) {
			ball[cr][cc] += ball[r][c];
			ball[r][c] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			ball[i][j] = 1;
			q.push({ map[i][j],{i,j } });
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ball[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

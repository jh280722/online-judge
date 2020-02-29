#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#define MAX 6
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int ans;
char map[MAX][3][3];
char tmp[MAX][3][3];
string col = { "wyrogb" };
string pos = { "UDFBLR" };
void rotate(char loc, char dir) {
	int p = pos.find(loc);
	int seq[4];
	char tmp[3];
	if (dir == '+') {
		f(k, 0, 2) {
			char tmp = map[p][0][0];
			for (int i = 0; i < 2; i++) {
				map[p][i][0] = map[p][i + 1][0];
			}
			for (int i = 0; i < 2; i++) {
				map[p][2][i] = map[p][2][i + 1];
			}
			for (int i = 2; i > 0; i--) {
				map[p][i][2] = map[p][i - 1][2];
			}
			for (int i = 2; i > 0; i--) {
				map[p][0][i] = map[p][0][i - 1];
			}
			map[p][0][1] = tmp;
		}
	}
	else {
		f(k, 0, 2) {
			char tmp = map[p][0][0];
			for (int i = 0; i < 2; i++) {
				map[p][0][i] = map[p][0][i + 1];
			}
			for (int i = 0; i < 2; i++) {
				map[p][i][2] = map[p][i + 1][2];
			}
			for (int i = 2; i > 0; i--) {
				map[p][2][i] = map[p][2][i - 1];
			}
			for (int i = 2; i > 0; i--) {
				map[p][i][0] = map[p][i - 1][0];
			}
			map[p][1][0] = tmp;
		}

	}
	switch (loc) {
	case'U':
		seq[0] = 3, seq[1] = 5, seq[2] = 2, seq[3] = 4;
		if (dir == '-')
			reverse(seq, seq + 4);
		memcpy(tmp, map[seq[3]][0], sizeof tmp);
		for (int k = 3; k > 0; k--) {
			memcpy(map[seq[k]][0], map[seq[k - 1]][0], sizeof map[seq[k]][0]);
		}
		memcpy(map[seq[0]][0], tmp, sizeof tmp);
		break;
	case'D':
		seq[0] = 2, seq[1] = 5, seq[2] = 3, seq[3] = 4;
		if (dir == '-')
			reverse(seq, seq + 4);
		memcpy(tmp, map[seq[3]][2], sizeof tmp);
		for (int k = 3; k > 0; k--) {
			memcpy(map[seq[k]][2], map[seq[k - 1]][2], sizeof map[seq[k]][2]);
		}
		memcpy(map[seq[0]][2], tmp, sizeof tmp);
		break;
	case'F':
		seq[0] = 0, seq[1] = 5, seq[2] = 1, seq[3] = 4;
		if (dir == '+') {
			memcpy(tmp, map[0][2], sizeof tmp);
			f(i, 0, 3) {
				map[0][2][i] = map[4][2 - i][2];
			}
			f(i, 0, 3) {
				map[4][i][2] = map[1][0][i];
			}
			f(i, 0, 3) {
				map[1][0][i] = map[5][2 - i][0];
			}
			f(i, 0, 3) {
				map[5][i][0] = tmp[i];
			}
		}
		else {
			seq[0] = 4, seq[1] = 1, seq[2] = 5, seq[3] = 0;
			f(i, 0, 3) {
				tmp[i] = map[4][i][2];
			}
			f(i, 0, 3) {
				map[4][2 - i][2] = map[0][2][i];
			}
			f(i, 0, 3) {
				map[0][2][i] = map[5][i][0];
			}
			f(i, 0, 3) {
				map[5][2 - i][0] = map[1][0][i];
			}
			f(i, 0, 3) {
				map[1][0][i] = tmp[i];
			}
		}
		break;
	case'B':
		seq[0] = 4, seq[1] = 1, seq[2] = 5, seq[3] = 0;
		if (dir == '+') {
			memcpy(tmp, map[0][0], sizeof tmp);
			f(i, 0, 3) {
				map[0][0][i] = map[5][i][2];
			}
			f(i, 0, 3) {
				map[5][2 - i][2] = map[1][2][i];
			}
			f(i, 0, 3) {
				map[1][2][i] = map[4][i][0];
			}
			f(i, 0, 3) {
				map[4][i][0] = tmp[2 - i];
			}
		}
		else {
			seq[0] = 0, seq[1] = 5, seq[2] = 1, seq[3] = 4;
			memcpy(tmp, map[0][0], sizeof tmp);
			f(i, 0, 3) {
				map[0][0][i] = map[4][2 - i][0];
			}
			f(i, 0, 3) {
				map[4][i][0] = map[1][2][i];
			}
			f(i, 0, 3) {
				map[1][2][i] = map[5][2 - i][2];
			}
			f(i, 0, 3) {
				map[5][i][2] = tmp[i];
			}
		}
		break;
	case'L':
		seq[0] = 0, seq[1] = 2, seq[2] = 1, seq[3] = 3;
		if (dir == '+') {
			f(i, 0, 3) {
				tmp[i] = map[0][i][0];
			}
			f(i, 0, 3) {
				map[0][i][0] = map[3][2 - i][2];
			}
			f(i, 0, 3) {
				map[3][2 - i][2] = map[1][i][0];
			}
			f(i, 0, 3) {
				map[1][i][0] = map[2][i][0];
			}
			f(i, 0, 3) {
				map[2][i][0] = tmp[i];
			}
		}
		else {
			seq[0] = 3, seq[1] = 1, seq[2] = 2, seq[3] = 0;
			f(i, 0, 3) {
				tmp[i] = map[0][i][0];
			}
			f(i, 0, 3) {
				map[0][i][0] = map[2][i][0];
			}
			f(i, 0, 3) {
				map[2][i][0] = map[1][i][0];
			}
			f(i, 0, 3) {
				map[1][i][0] = map[3][2 - i][2];
			}
			f(i, 0, 3) {
				map[3][2 - i][2] = tmp[i];
			}
		}
		break;
	case'R':
		seq[0] = 3, seq[1] = 1, seq[2] = 2, seq[3] = 0;
		if (dir == '+') {
			f(i, 0, 3) {
				tmp[i] = map[0][i][2];
			}
			f(i, 0, 3) {
				map[0][i][2] = map[2][i][2];
			}
			f(i, 0, 3) {
				map[2][i][2] = map[1][i][2];
			}
			f(i, 0, 3) {
				map[1][i][2] = map[3][2 - i][0];
			}
			f(i, 0, 3) {
				map[3][2 - i][0] = tmp[i];
			}
		}
		else {
			seq[0] = 0, seq[1] = 2, seq[2] = 1, seq[3] = 3;
			f(i, 0, 3) {
				tmp[i] = map[0][i][2];
			}
			f(i, 0, 3) {
				map[0][i][2] = map[3][2 - i][0];
			}
			f(i, 0, 3) {
				map[3][2 - i][0] = map[1][i][2];
			}
			f(i, 0, 3) {
				map[1][i][2] = map[2][i][2];
			}
			f(i, 0, 3) {
				map[2][i][2] = tmp[i];
			}
		}
		break;
	}


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	f(k, 0, 6)
		f(i, 0, 3)
		f(j, 0, 3)
		tmp[k][i][j] = col[k];
	cin >> t;
	while (t--) {
		//흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.
		//		U			D			F			B			L			R
		memcpy(map, tmp, sizeof map);
		cin >> n;
		f(i, 0, n) {
			char loc, dir;
			cin >> loc >> dir;
			rotate(loc, dir);
		}
		f(i, 0, 3) {
			f(j, 0, 3) {
				cout << map[0][i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
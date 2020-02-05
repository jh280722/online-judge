#include <iostream>
#include <algorithm>
#include <queue>
#define all(v) v.begin(), v.end()
#define MAX 201
#define INF 1000000000
using namespace std;
typedef long long ll;
enum DIR {
	DOWN = 0, LEFT, RIGHT, UP
};
struct POINT {
	bool check;
	int c, r;
};
struct DATA {
	bool check;
	int idx;
	POINT l, r;
};

POINT v[5001];
DATA hole[2501];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int n, m, k, t;
int ans;
//(��, ��)

int calArea(int& idx) {
	bool rh = false;
	int r = v[idx].r, c = v[idx].c;
	int left = 0, right = 0, hight = 0;
	for (int j = idx - 1; j >= 0; j--) {
		int nr = v[j].r, nc = v[j].c;
		if (r > nr) {
			hight = nr;
			left = nc;
			idx = j;
			break;
		}
	}
	for (int j = idx + 1; j < n; j++) {
		int nr = v[j].r, nc = v[j].c;
		if (r > nr) {
			if (hight <= nr) {
				hight = nr;
				rh = true;
				idx = j;
			}
			right = nc;
			break;
		}
	}
	return (right - left) * (r - hight);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int maxr = 0, maxc = 0;
	for (int i = 0; i < n; i++) {
		int c, r;
		cin >> c >> r;
		v[i] = {false, c,r };
		maxr = max(maxr, r);
		maxc = max(maxc, c);
	}
	int cnt = 0;
	int left = 0, right = maxc, h = 0;

	for (int i = 0; i < n - 1; i++) {
		int r = v[i].r, c = v[i].c;
		int nr = v[i + 1].r, nc = v[i + 1].c;
		if (r < nr) {
			cnt += (right - left) * h;
		}
		else if (r > nr) {
			cnt += (right - left) * h;
		}
		else if (c < nc) {
			left = c;
			right = nc;
			h = r;
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		int idx = 0;
		cin >> a >> b >> c >> d;
		hole[i].l = { false, a,b }, hole[i].r = { false, c,d };
		for (int j = 0; j < n; j++) {
			if (v[j].c == a && v[j].r == b) {
				idx = j;
				break;
			}
		}
		hole[i].idx = idx;
	}
	//sort(hole, hole + k, [](DATA a, DATA b) {if (a.l.r != b.l.r) return a.l.r > b.l.r; else return a.l.c < b.l.c; });
	int hidx = 0;
	for (int i = 0; i < k; i++) {
		//�������� ��� ���鼭 ���� ���µ� ���� ���̺��� ũ�� left
		//�����ʵ� ��������, �׷��ٰ� ���� ���̺��� �۾����� �ű������ ����(nr-r)
		//�ö� ���� ������ ������ �״�� �ݺ��� ���� ���� ������ ������ �ٽ� �۾� �ݺ�
		//�ö󰡱��� �� �ּ� ���̸�ŭ �� �� r,c�� ���� �� �״�� �۾�
		//���� ���̰� ���� ������ ����
		//���� ������ ������ ������� �ѹ��� ���ֱ�
		bool flag = true;
		bool eq = false;
		int idx = hole[i].idx;
		while (flag) {
			if (v[idx].check) {
				break;
			}
			v[idx].check = true;
			for (int j = idx - 1; j >= 0; j--) {
				int nr = v[j].r, nc = v[j].c;
				if (v[idx].r > nr) {
					break;
				}
				else if (v[idx].r == nr)
					v[j].check = true;
			}
			for (int j = idx + 1; j < n; j++) {
				int nr = v[j].r, nc = v[j].c;
				if (v[idx].r > nr) {
					break;
				}
				else if (v[idx].r == nr)
					v[j].check = true;
			}
			//cout << idx << ' ' << cnt << '\n';
			cnt -= calArea(idx);
			if (idx == 0 || idx == n - 1) {
				flag = false;
				break;
			}
			for (int j = 0; j < k; j++) {
				if (hole[j].l.r == v[idx].r && hole[j].l.c == v[idx].c) {
					flag = false;
					break;
				}
				else if (hole[j].r.r == v[idx].r && hole[j].r.c == v[idx].c) {
					flag = false;
					break;
				}
			}

		}
	}

	cout << cnt << '\n';

	return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define all(v) v.begin(), v.end()
#define MAX 201
#define INF 1000000000
using namespace std;
typedef long long ll;

struct POINT {
	int r,c;
};

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int n, m, k, t;
int ans;

void rotate(queue<char> &q) {
	int fr = q.front();
	q.pop();
	q.push(fr);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;//4�� ��� 8<=n <=28
	//16���� �ð���� , ��й�ȣ K��°�� ū ���� 10�� ���� ���� ��
	// ũ�� ������ �� �� ���� ���� �ߺ����� ���� �ʵ��� ���� ������ k���� X

	for (int tc = 1; tc <= t; tc++) {
		queue<char> q;
		vector<int> arr;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			char num;
			cin >> num;
			q.push(num);
		}

		for (int i = 0; i < n / 4; i++) {
			rotate(q);
			queue<char> tmp = q;
			string s;
			for(int j=0;j<n;j++) {
				char fr= tmp.front();
				tmp.pop();
				s+= fr;
				if ( (j+1) % (n/4) == 0) {
					arr.push_back(strtol(s.c_str(),0,16));
					s = "";
				}
			}
		}
		sort(all(arr), greater<int>());
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] > arr[i + 1])
				k--;			
			if (k == 0) {
				ans = arr[i];
				break;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}

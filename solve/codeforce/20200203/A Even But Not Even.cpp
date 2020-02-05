#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
typedef long long ll;
using namespace std;

//sum이 2로 나눌수 있고 자체 넘버는 2로 안 나눠진다. ebne이다.
//앞에 0이 올 수 없고 숫자를 삭제할 수 도 있다. 순서는 변경 금지
//0~n-1의 수를 삭제가능
int n, m, t;

bool flag = false;
int sum(string num) {
	int s = 0;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == 0)
			break;
		s += num[i] - '0';
	}
	return s;
}

bool check(int num, int numend) {
	if (num % 2 == 0 && numend % 2 == 1)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		flag = false;
		string num;
		cin >> n;
		cin >> num;
		int totalsum;
		int circle = n;
		while (circle--) {
			totalsum = sum(num);
			if (check(totalsum, num[circle] - '0')) {
				for (int i = 0; i < n; i++) {
					if (num[i] == 0)
						break;
					cout << num[i];
				}
				cout << '\n';
				flag = true;
				break;
			}
			else {
				bool flag2 = false;
				for (int i = circle; i >= 0; i--) {
					int tmp = (totalsum - (num[i] - '0'));
					if (tmp % 2 == 0) {
						if (i == 0 && num[1] == '0')
							continue;
						for (int j = i; j < n; j++) {
							num[j] = num[j + 1];
						}
						totalsum -= tmp;
						flag2 = true;
						break;
					}
				}
				if (!flag2) {
					if ((num[circle] - '0') % 2 == 0) {
						totalsum -= num[circle] - '0';
						num[circle] = 0;

					}
					else {
						totalsum -= num[circle-1] - '0';
						num[circle-1] = num[circle];
						num[circle] = 0;
					}
				}
			}
		}
		if (!flag)
			cout << -1 << '\n';
	}
	return 0;
}

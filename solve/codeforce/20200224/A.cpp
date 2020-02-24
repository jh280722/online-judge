#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 51
#define INF 2147000000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int ans = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		//b -> a ���� Ȧ���� ������ a+x ���� ¦���� ������ a-y
		if (a == b) {
			cout << 0 << '\n';
			continue;
		}
		if (a > b) {
			if ((a - b) % 2 == 0) {
				cout << 1 << '\n';
				continue;
			}
			else {
				cout << 2 << '\n';
				continue;
			}
		}
		else {
			if ((b - a) % 2 == 1) {
				cout << 1 << '\n';
				continue;
			}
			else {
				cout << 2 << '\n';
				continue;
			}
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#define all(v) v.begin(), v.end()
#define MAX 100001
#define INF 2147483647
#define PIE 3.14159265359
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int cnt = 0;
	int digit = 0;
	int tmp = n;
	while (tmp) {
		digit++;
		tmp /= 10;
	}
	for (int i = 1; i < digit; i++) {
		cnt += 9 * i * pow(10,i-1);
	}
	int d=n /(int)pow(10, digit - 1);
	cnt += (digit) *pow(10,digit-1)* (d-1);
	n %= (int)pow(10, digit-1);
	cnt += digit * (n + 1);
	/*
	1자리 9개 2자리 90개 3자리 21
		9 180 63
		252*/
	cout << cnt;

	return 0;
}
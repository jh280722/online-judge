#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 100001
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = -2 * n + 2; i < 2 * n - 1; i++)
	{
		for (int j = -2 * n + 2; j < 2 * n - 1; j++)
			putchar(max(abs(i), abs(j)) % 2 ? ' ' : '*');
		putchar('\n');
	}
	return 0;
}
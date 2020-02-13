#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
int map[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int maxcnt = 0;
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			if (i == 0 && j == 0)
			{
				maxcnt = 1;
				map[i - r1][j - c1] = 1;
				continue;
			}

			//행과 열중에 큰쪽으로 n행n열기준.
			int stdi;
			int absi = abs(i);
			int absj = abs(j);
			if (absi >= absj)
				stdi = absi;
			else
				stdi = absj;

			int memo = stdi;
			//n행n열 숫자 산출. n행n열은 n번째 홀수의 제곱
			stdi--;
			stdi = stdi * 2 + 1;
			stdi = stdi * stdi;

			int result = 0;
			if (j == memo && i != memo) //n행n열의 오른쪽
				result = stdi + (memo - i);
			else if (i == (memo * -1))
				result = stdi + (memo * 2) + (memo - j); //위
			else if (j == (memo * -1))
				result = stdi + ((memo * 2) * 2) + (memo + i); // 왼
			else if (i == memo)
				result = stdi + ((memo * 2) * 3) + (memo + j); // 아래

			map[i - r1][j - c1] = result;

			//자릿수 저장 및 최대자릿수 산출
			int numcnt = 0;
			while (result != 0)
			{
				numcnt++;
				result = result / 10;
			}
			if (numcnt > maxcnt)
				maxcnt = numcnt;
		}
	}
	for (int i = 0; i <= r2-r1; i++)
	{
		for (int j = 0; j <= c2-c1; j++)
		{
			cout << setw(maxcnt) << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
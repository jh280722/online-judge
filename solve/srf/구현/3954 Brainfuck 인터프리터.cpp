#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define MAX 4097
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
int d;
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

int me[100001];
int loop[MAX];
int stack[MAX];
char com[MAX];
char s[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;//메모리 크기 명령어 크기 문자열 크기
		cin >> com >> s;
		int op = 0, cidx = 0, idx = 0, sidx = 0;
		int loopR = 0;
		int top = -1;

		for (int i = 0; i < m; i++) {
			if (com[i] == '[') {
				stack[++top] = i;
			}
			else if (com[i] == ']') {
				stack[++top] = i;
				loop[stack[top]] = stack[top - 1];
				loop[stack[top - 1]] = i;
				top -= 2;
			}
		}

		bool flag = false;
		while (op < 50000000) {
			if (cidx == m) {
				flag = true;
				cout << "Terminates" << '\n';
				break;
			}
			switch (com[cidx]) {
			case '-':
				me[idx] = (me[idx] - 1) % 256;
				cidx++;
				break;
			case '+':
				me[idx] = (me[idx] + 1) % 256;
				cidx++;
				break;
			case '<':
				idx = (idx + n - 1) % n;
				cidx++;
				break;
			case '>':
				idx = (idx + 1) % n;
				cidx++;
				break;
			case '[':
				if (me[idx] == 0) {
					cidx = loop[cidx];
				}
				else cidx++;
				break;
			case ']':
				if (me[idx] != 0) {
					cidx = loop[cidx];
				}
				else cidx++;
				break;
			case '.':
				cidx++;
				break;
			case ',':
				if (sidx == k)
					me[idx] = 255;
				else
					me[idx] = s[sidx++];
				cidx++;
				break;
			}
			op++;
			if (loopR < cidx)
				loopR = cidx;
		}
		if (!flag) {
			cout << "Loops " << loop[loopR] << ' ' << loopR << '\n';
		}
		memset(me, 0, sizeof(int) * n);
		memset(loop, 0, sizeof(char) * m);
	}
	return 0;
}
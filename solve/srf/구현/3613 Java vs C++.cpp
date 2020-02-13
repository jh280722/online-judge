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
char map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	string ans = "";
	cin >> s;
	bool error = false;
	bool c = false, ja = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {//대문자가 나오면 자바
			ja = true;
			if (!i || c) {
				ans = "Error!";
				break;
			}
			ans += '_';
			ans += s[i] + 32;
		}
		else if (s[i] == '_') {
			c = true;
			if (!i || ja || i == s.size() - 1 || s[i + 1] == '_') {
				ans = "Error!";
				break;
			}
			if (s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
				ans = "Error!";
				break;
			}
			if (ans.size() == 0)
				ans += s[i + 1];
			else
				ans += s[i + 1] - 32;
			i++;
		}
		else { //소문자
			ans += s[i];
		}
	}

	if (error) {
		cout << "Error!" << '\n';
	}
	else
		cout << ans << '\n';
	return 0;
}
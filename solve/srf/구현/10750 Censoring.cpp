#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

string a, t;

char s1[1000001];
int idx;

bool checkL() {
	int n = a.size();
	if (idx < n)
		return false;
	int m = idx-1;
	for (int i = n-1; i >=0; i--) {
		if (a[i] != s1[m--]) {
			return false;
		}
	}
	for (int i = 0; i < n; i++) 
		idx--;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t >> a;
	int i = 0;
	int k = t.length() - 1;
	while (i <= k) {
		while (i <= k) {
			s1[idx++]=t[i++];
			if (checkL()) 
				break;
		}
	}
	for (int i = 0; i < idx; i++) {
		cout << s1[i];
	}
	return 0;
}

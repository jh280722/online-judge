#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define MAX 10
using namespace std;

int n, m;
int ans;

string map[7];

string number[10][7] = {
	{"000000",
	 "001100",
	 "010010",
	 "010010",
	 "010010",
	 "001100",
	 "000000"},
	{"000000",
	 "000100",
	 "001100",
	 "000100",
	 "000100",
	 "000100",
	 "000000"},
	{"000000",
	 "011110",
	 "000010",
	 "011110",
	 "010000",
	 "011110",
	 "000000"},
	{"000000",
	 "011100",
	 "000010",
	 "000100",
	 "000010",
	 "011100",
	 "000000"},
	{"000000",
	 "000100",
	 "001100",
	 "010100",
	 "111110",
	 "000100",
	 "000000"},
	{"000000",
	 "011110",
	 "010000",
	 "011100",
	 "000010",
	 "010010",
	 "001100"},
	{"000000",
	 "010000",
	 "010000",
	 "011110",
	 "010010",
	 "011110",
	 "000000"},
	{"000000",
	 "011110",
	 "000010",
	 "000100",
	 "000100",
	 "000100",
	 "000000"},
	{"000000",
	 "011110",
	 "010010",
	 "011110",
	 "010010",
	 "011110",
	 "000000"},
	{"011110",
	 "010010",
	 "010010",
	 "011110",
	 "000010",
	 "000010",
	 "000010"},
};


struct DATA {
	int r, c;
};
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

bool next_permutation(vector<int>& a) {
	int n = a.size() - 1;
	int i = n;
	int j = n;
	while (i > 0 && a[i - 1] >= a[i])
		i--;
	if (i <= 0) return false;
	while (a[j] <= a[i - 1]) j--;
	swap(a[i - 1], a[j]);
	j = n;
	while (j > i) {
		swap(a[i], a[j]);
		i++; j--;
	}
	return true;
}

int chk(int c) {
	if (map[5][c + 2] == '1' && map[5][c + 1] == '0') {
		return 0;
	}
	else if (map[3][c + 1] == '0' && map[2][c + 2] == '1') {
		return 1;
	}
	else if (map[3][c + 1] == '1' && map[2][c + 1] == '0' && map[3][c + 4] == '1') {
		return 2;
	}
	else if (map[2][c + 4] == '1' && map[3][c + 4] == '0' && map[4][c + 4] == '1') {
		return 3;
	}
	else if (map[3][c + 2] == '0' && map[4][c + 2] == '1') {
		return 4;
	}
	else if (map[6][c + 2] == '1') {
		return 5;
	}
	else if (map[3][c + 1] == '1' && map[1][c + 4] == '0') {
		return 6;
	}
	else if (map[4][c + 3] == '1' && map[4][c + 4] == '0') {
		return 7;
	}
	else if (map[3][c + 4] == '1' && map[1][c + 4] == '1' && map[0][c + 1] == '0') {
		return 8;
	}
	else if (map[0][c + 1] == '1') {
		return 9;
	}
	return -1;
}
vector<int> np;
bool stn() {
	for (int j = 0; j < n; j++) {
		np.push_back(chk(j * 6));
	}
	return next_permutation(np);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 7; i++) {
		cin >> map[i];
	}
	n = map[0].size() / 6;
	if (!stn())
		cout << "The End";
	else {
		for (int j = 0; j < 7; j++) {
			for (int i = 0; i < n; i++) {
				cout << number[np[i]][j];
			}
			cout << '\n';
		}
	}
	return 0;
}

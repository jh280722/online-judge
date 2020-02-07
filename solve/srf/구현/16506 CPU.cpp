#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 1000000000
using namespace std;
typedef long long ll;

int n, m, k, t;
int ans;

string change(string s) {
	string bit = "";
	char bit4='0';
	if (s.back() == 'C') {
		bit4 = '1';
		s.pop_back();
	}
	if (s == "ADD") {
		bit = "0000";
	}
	else if (s == "SUB") {
		bit = "0001";
	}
	else if (s == "MOV") {
		bit = "0010";
	}
	else if (s == "AND") {
		bit = "0011";
	}
	else if (s == "OR") {
		bit = "0100";
	}
	else if (s == "NOT") {
		bit = "0101";
	}
	else if (s == "MULT") {
		bit = "0110";
	}
	else if (s == "LSFTL") {
		bit = "0111";
	}
	else if (s == "LSFTR") {
		bit = "1000";
	}
	else if (s == "ASFTR") {
		bit = "1001";
	}
	else if (s == "RL") {
		bit = "1010";
	}
	else if (s == "RR") {
		bit = "1011";
	}
	bit += bit4;
	return bit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//opcode rD rA rB || opcode rD rA #C
	cin >> t;
	while (t--) {
		string ans = "";
		string opcode;
		int rD, rA, v;
		cin >> opcode;
		cin >> rD >> rA >> v;
		ans = change(opcode);
		char bit4 = ans.back();
		ans += '0';
		for (int i = 0; i < 3; i++) {
			ans += ((rD >> (2 - i)) & 1) + '0';
		}
		for (int i = 0; i < 3; i++) {
			ans += ( (rA >> (2 - i)) & 1) + '0';
		}
		if (bit4 == '1') {
			//v==C
			for (int i = 0; i < 4; i++) {
				ans += ((v >> (3 - i)) & 1) + '0';
			}
		}
		else {
			//v==rB
			for (int i = 0; i < 3; i++) {
				ans += ((v >> (2 - i)) & 1) + '0';
			}
			ans += '0';
		}
		cout << ans << '\n';
	}
	return 0;
}

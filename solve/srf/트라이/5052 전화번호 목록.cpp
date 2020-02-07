#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define all(v) v.begin(), v.end()
#define INF 1000000000
using namespace std;
typedef long long ll;

int idx;
struct Node {
	bool finished;
	int num[10];
	void init() {
		finished = false;
		for (register int i = 0; i < 10; i++)
			num[i] = 0;
	}
}nodes[60000];

Node* newNode() {
	nodes[idx].init();
	return &nodes[idx++];
}

int n, m, k, t;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		bool flag = false;
		idx = 0;
		Node* head = newNode();
		cin >> n;
		for (register int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (flag)
				continue;
			Node* tmp = head;
			register int size = s.size();
			for (register int j = 0; j < size; j++) {
				if (!tmp->num[s[j] - '0']) {
					newNode();
					tmp->num[s[j] - '0'] = idx - 1;
				}	
				tmp = &nodes[tmp->num[s[j] - '0']];
				if (tmp->finished) {
					flag = true;
					break;
				}
			}
			if (tmp->finished) {
				flag = true;
			}
			for (register int j = 0; j < 10; j++)
				if (tmp->num[j])
					flag = true;
			tmp->finished = true;
		}
		if (flag)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
	return 0;
}

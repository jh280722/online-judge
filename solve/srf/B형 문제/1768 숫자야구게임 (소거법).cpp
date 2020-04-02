//#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000009
#define MOD2 1000000021
#define INF 1e9
#define N 4
//using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
//typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;
//typedef vector<int> vi;
//typedef vector<ll> vll;
//typedef vector<pii> vpii;
//typedef vector<pll> vpll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); };
int n, m, k, t;
int dr[] = { 0,0,1,-1, -1,1,1,-1 };
int dc[] = { -1,1,0,0, 1,1,-1,-1 };

int idx;

struct Node {
	int num[4];
	bool exist;
	Node* nxt;
}nodes[300001];

Node* newNode() {
	nodes[idx].exist = 1;
	return &nodes[idx++];
}

struct List {
	Node* head;
	Node dummy;

	void init() {
		head = &dummy;
		head->nxt = 0;
	}
	void insert(int num[]) {
		Node* node = newNode();
		for (register int i = 0; i < 4; i++)
			node->num[i] = num[i];
		node->nxt = head->nxt;
		head->nxt = node;
	}
}list;

typedef struct {
	int strike;
	int ball;
} Result;

// API

extern Result query(int guess[]);
bool ch[11];
int num[4];
void dfs(int cnt) {
	if (cnt == 4) {
		int t[4];
		for (register int i = 0; i < cnt; i++) {
			t[i] = num[i];
		}
		list.insert(t);
		return;
	}
	for (register int i = 0; i < 10; i++) {
		if (ch[i]) continue;
		ch[i] = 1;
		num[cnt] = i;
		dfs(cnt + 1);
		ch[i] = 0;
	}

}
void doUserImplementation(int guess[]) {
	// Implement a user's implementation function
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.
	list.init();
	dfs(0);
	register Result r, r2;
	register Node* cur = list.head->nxt;
	register Node* tmp;
	register int digits_c[10];
	while (cur) {
		if (!cur->exist) {
			cur = cur->nxt;
			continue;
		}
		for (register int i = 0; i < 4; i++)
			guess[i] = cur->num[i];
		r = query(guess);
		if (r.strike == 4)
			break;
		tmp = cur->nxt;
		while (tmp) {
			if (!tmp->exist) {
				tmp = tmp->nxt;
				continue;
			}
			r2.strike = 0, r2.ball = 0;
			for (int count = 0; count < 10; ++count) digits_c[count] = 0;
			for (int idx = 0; idx < N; ++idx) {
				digits_c[tmp->num[idx]]++;
			}
			for (int idx = 0; idx < N; ++idx)
				if (guess[idx] == tmp->num[idx])
					r2.strike++;
				else if (digits_c[guess[idx]] > 0)
					r2.ball++;
			if (r.strike != r2.strike || r.ball != r2.ball) {
				tmp->exist = 0;
			}
			tmp = tmp->nxt;
		}
		cur = cur->nxt;
	}


}
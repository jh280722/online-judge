//#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 10009
#define MOD2 1000000021
#define INF 1000000000
#define N 21
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
int dr[] = { 1,0,-1,0, -1,1,1,-1 };
int dc[] = { 0,1,0,-1, 1,1,-1,-1 };

int strlen(char* src) {
	register int lng = 0;
	while (*src++) lng++;
	return lng;
}
bool strcmp(char* src1, char* src2) {
	while (*src1) {
		if (*src1++ != *src2++) return false;
	}
	if (*src2)
		return false;
	return true;
}
void strcpy(char* dst, char* src) {
	while (*dst++ = *src++);
}

int Hash(char* src) {
	register int lng = strlen(src);
	register ll k = 0;
	fu(i, 0, lng) {
		k = (k * 2 + src[i]) % MOD;
	}
	return k % MOD;
}

int idx;

struct Node {
	int cnt;
	char str[11];
	Node* nxt;
}nodes[5000001];

Node* newNode() {
	return &nodes[idx++];
}

struct List {
	Node* head;
	Node dummy;

	void init() {
		head = &dummy;
		head->nxt = 0;
	}
	void insert(char* str) {
		Node* node = newNode();
		strcpy(node->str, str);
		node->cnt = 1;
		node->nxt = head->nxt;
		head->nxt = node;
	}
}list[11][MOD];

void init(void) {
	idx = 0;
	fu(i, 0, 11) {
		fu(j, 0, MOD) {
			list[i][j].init();
		}
	}
}

void insert(int buffer_size, char* buf) {
	register int n = buffer_size;
	register int k = 0;
	char str[11];
	fu(i, 0, n) {
		k = (k * 29 + buf[i] - 'a' + 1) % MOD;
		str[i] = buf[i];
		str[i + 1] = 0;
		Node* tmp = list[i][k].head;
		bool flg = false;
		while (tmp) {
			if (strcmp(tmp->str, str)) {
				tmp->cnt++;
				flg = true;
				break;
			}
			tmp = tmp->nxt;
		}
		if(!flg)
			list[i][k].insert(str);
	}
}

int query(int buffer_size, char* buf) {
	register int n = buffer_size;
	register int k = 0;
	register int cnt = 0;
	fu(i, 0, n) {
		k = (k * 29 + buf[i] - 'a' + 1) % MOD;
	}
	Node* tmp = list[n-1][k].head;
	while (tmp) {
		if (strcmp(tmp->str,buf)) {
			cnt = tmp->cnt;
			break;
		}
		tmp = tmp->nxt;
	}
	return cnt;
}
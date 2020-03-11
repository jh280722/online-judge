#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
 
template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}
 
template <typename T>
ostream& operator <<(ostream &out, const vector<T>& v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

int n;
bool Viz[1003][1003];
char Answer[1003][1003];
pair<int, int> M[1003][1003];
deque<pair<pair<int, int>, pair<int, int> > > Q;
pair<int, int> D[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char getAns(int x1, int y1, int x2, int y2)
{
	if (x1 + 1 == x2)
		return 'D';
	if (x1 - 1 == x2)
		return 'U';
	if (y1 + 1 == y2)
		return 'R';
	if (y1 - 1 == y2)
		return 'L';
	assert(false);
}

void DFS(int x, int y)
{
	Viz[x][y] = true;
	for (auto d : D)
	{
		int nxtx = x + d.first;
		int nxty = y + d.second;
		
		if (Viz[nxtx][nxty]) continue;
		
		Answer[nxtx][nxty] = getAns(nxtx, nxty, x, y);
		DFS(nxtx, nxty);
	}
}

pair<int, int> getNgh(int x, int y)
{
	for (auto d : D)
	{
		int nxtx = x + d.first;
		int nxty = y + d.second;
		if (!Viz[nxtx][nxty])
			return {nxtx, nxty};
	}
	return {-1, -1};
}

void fail()
{
	cout<<"INVALID\n";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin>>n;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin>>M[i][j].first>>M[i][j].second;
			if (M[i][j].first == i && M[i][j].second == j)
			{
				Answer[i][j] = 'X';
				Viz[i][j] = true;
				Q.push_back({{i, j}, {i, j}});
			}
		}
	}

	for (int i=0; i<=n+1; i++)
	{
		Viz[0][i] = true;
		Viz[n+1][i] = true;
		Viz[i][0] = true;
		Viz[i][n+1] = true;
	}

	while(!Q.empty())
	{
		pair<int, int> now = Q.front().first;
		pair<int, int> src = Q.front().second;
		Q.pop_front();

		for (auto d : D)
		{
			int nxtx = now.first + d.first;
			int nxty = now.second + d.second;
			if (Viz[nxtx][nxty]) continue;

			if (M[nxtx][nxty] == src)
			{
				Answer[nxtx][nxty] = getAns(nxtx, nxty, now.first, now.second);
				Viz[nxtx][nxty] = true;
				Q.push_back({{nxtx, nxty}, src});
			}
		}
	}

	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (!Viz[i][j] && !(M[i][j].first == -1 && M[i][j].second == -1))
				fail();
		}
	}

	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (!Viz[i][j])
			{
				pair<int, int> ngh = getNgh(i, j);
				if (ngh == make_pair(-1, -1))
					fail();

				Answer[i][j] = getAns(i, j, ngh.first, ngh.second);
				DFS(i, j);
			}
		}
	}

	cout<<"VALID\n";
	for (int i = 1; i <=n; i++, cout<<'\n')
	{
		for (int j=1; j<=n; j++)
		{
			cout<<Answer[i][j];
		}
	}

	return 0;
}
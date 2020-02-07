#include <cstdio>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int n, m, year;
int A[10][10];
int G[10][10];
vector <pii> v[10][10];
int x, y, z;
int my[] = { -1,-1,-1,0,0,1,1,1 };
int mx[] = { -1,0,1,-1,1,-1,0,1 };

void spring()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int dead_tree = 0;
			for (int k = v[i][j].size() - 1; k >= 0; k--)
			{
				int age = v[i][j][k].first;
				int cnt = v[i][j][k].second;
				int mul = age * cnt;
				if (G[i][j] >= mul)
				{
					G[i][j] -= mul;
					v[i][j][k].first++;
				}
				else
				{
					int alive_cnt = G[i][j] / age;
					int dead_cnt = cnt - alive_cnt;
					dead_tree += dead_cnt * (age / 2);

					if (alive_cnt == 0)
					{
						v[i][j].erase(v[i][j].begin() + k);
						continue;
					}
					G[i][j] -= alive_cnt * age;

					v[i][j][k].second = alive_cnt;
					v[i][j][k].first++;
				}
			}
			G[i][j] += dead_tree + A[i][j];
		}
	}
}

void autumn()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto k : v[i][j])
			{
				if (k.first % 5 == 0)
				{
					int cnt = k.second;
					for (int t = 0; t < 8; t++)
					{
						int ny = i + my[t];
						int nx = j + mx[t];
						if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
						if (v[ny][nx].size() == 0 || v[ny][nx].back().first != 1)
							v[ny][nx].push_back({ 1,cnt });
						else
							v[ny][nx].back().second += cnt;
					}
				}
			}
		}
	}
}

int cnt_tree()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto k : v[i][j])
				ret += k.second;
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d %d", &n, &m, &year);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
			G[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		v[--x][--y].push_back({ z, 1 });
	}

	for (int i = 0; i < year; i++)
	{
		spring();
		autumn();
	}

	int ans = cnt_tree();
	printf("%d", ans);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N;
int Max;
void move(int map[20][20], int cnt);

void up(int map[20][20], int cnt)
{
	int tmp[20][20] = { 0, };
	//memcpy(tmp, map, sizeof(tmp));
	bool flag = true;
	for (int j = 0; j < N; j++)
	{
		int index = 0;
		for (int i = 0; i < N; i++) {
			if (map[i][j] == 0)
				continue;

			if (flag&&index > 0 && tmp[index - 1][j] == map[i][j])
			{
				tmp[index - 1][j] *= 2;
				flag = false;
			}
			else
			{
				tmp[index][j] = map[i][j];
				index++;
				flag = true;
			}

		}
	}

	move(tmp, cnt + 1);
}

void down(int map[20][20], int cnt)
{
	int tmp[20][20] = { 0, };
	bool flag = true;
	//memcpy(tmp, map, sizeof(tmp));
	for (int j = 0; j < N; j++)
	{
		int index = N-1;
		for (int i = N-1; i >=0; i--) {
			if (map[i][j] == 0)
				continue;
			if (flag&&index < N - 1 && tmp[index + 1][j] == map[i][j])
			{
				tmp[index + 1][j] *= 2;
				flag = false;
			}
			else
			{
				tmp[index][j] = map[i][j];
				index--;
				flag = true;
			}
		}
	}

	move(tmp, cnt + 1);
}

void left(int map[20][20], int cnt)
{
	int tmp[20][20] = { 0, };
	bool flag = true;
	//memcpy(tmp, map, sizeof(tmp));

	for (int i = 0; i < N; i++)
	{
		int index = 0;
		 for (int j = 0; j < N; j++){
			if (map[i][j] == 0)
				continue;
			if (flag&&index > 0 && tmp[i][index - 1] == map[i][j])
			{
				tmp[i][index - 1] *= 2;
				flag = false;
			}
			else
			{
				tmp[i][index] = map[i][j];
				index++;
				flag = true;
			}
		}
	}

	move(tmp, cnt + 1);
}

void right(int map[20][20], int cnt)
{
	int tmp[20][20] = { 0, };
	bool flag = true;

	//memcpy(tmp, map, sizeof(tmp));
	for (int i = 0; i < N; i++)
	{
		int index = N-1;
		for (int j = N-1; j >=0; j--) {
			if (map[i][j] == 0)
				continue;

			if (flag&&index < N - 1 && tmp[i][index + 1] == map[i][j])
			{
				tmp[i][index + 1] *= 2;
				flag = false;
			}
			else
			{
				tmp[i][index] = map[i][j];
				index--;
				flag = true;
			}
		}
	}

	move(tmp, cnt + 1);
}


void move(int map[20][20],int cnt)
{
	if (cnt >= 5)
	{
		//
		for(int i=0;i<N;i++)
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 0)
					continue;
				Max = max(Max, map[i][j]);
			}
		return;
	}
	
	int tmp[20][20];
	memcpy(tmp, map, sizeof(tmp));




	up(tmp, cnt);
	down(tmp, cnt);
	left(tmp, cnt);
	right(tmp, cnt);
}


int main()
{
	int map[20][20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	move(map, 0);

	printf("%d\n", Max);
	return 0;
}
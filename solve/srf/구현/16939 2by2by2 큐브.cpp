#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 1000000000
typedef long long ll;
using namespace std;

int n, m, t;
int cube[6][4]; // 0 위 1 정면 2 아래 3 왼쪽 4 오른쪽 5 뒷면
//오른쪽 아래를 중심으로 위로 1번 아래로 1번 옆으로 오른쪽 1번 왼쪽 1번 
bool suc = false;
enum dir {
	UP = 0, DOWN, RIGHT, LEFT, CLOCK,UNCLOCK
};
bool check_color(int tmp[6][4]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (tmp[i][0] != tmp[i][j])
				return false;
		}
	}
	return true;
}

void rotoate(int dir) {
	int tmp[6][4];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = cube[i][j];
		}
	}
	int tmp0[2];
	switch (dir) {
	case UP:
		// 0 위 1 정면 2 아래 3 왼쪽 4 오른쪽 5 뒷면
		//01 03 -> 52 50, 52 50 -> 21 23, 21 23 -> 11 13, 11 13 -> 01 03
		tmp0[0] = tmp[0][1];
		tmp0[1] = tmp[0][3];
		for (int i = 0; i < 4; i++) {
			if (i == 0 || i == 1) {
				tmp[i][1] = tmp[i + 1][1];
				tmp[i][3] = tmp[i + 1][3];
			}
			else if (i == 2) {
				tmp[2][1] = tmp[5][2];
				tmp[2][3] = tmp[5][0];
			}
			else if (i == 3) {
				tmp[5][2] = tmp0[0];
				tmp[5][0] = tmp0[1];
			}
		}
		break;
	case DOWN:
		//01 03 -> 11 13, 11 13 -> 21 23, 21 23 -> 50 52, 50 52 -> 03 01
		tmp0[0] = tmp[0][1];
		tmp0[1] = tmp[0][3];
		for (int i = 4; i > 0; i--) {
			if (i == 4) {
				tmp[0][1] = tmp[5][2];
				tmp[0][3] = tmp[5][0];
			}
			else if (i == 3) {
				tmp[5][0] = tmp[2][1];
				tmp[5][2] = tmp[2][3];
			}			
			else if (i == 2) {
				tmp[2][1] = tmp[1][1];
				tmp[2][3] = tmp[1][3];
			}
			else {
				tmp[1][1] = tmp0[0];
				tmp[1][3] = tmp0[1];
			}
		}
		break;
	case RIGHT:
		//12 13 -> 42 43, 42 43 -> 52 53, 52 53 -> 32 33, 32 33 -> 12 03
		tmp0[0] = tmp[1][2];
		tmp0[1] = tmp[1][3];
		for (int i = 4; i > 0; i--) {
			if (i == 4) {
				tmp[1][2] = tmp[3][2];
				tmp[1][3] = tmp[3][3];
			}
			else if (i == 3) {
				tmp[3][2] = tmp[5][2];
				tmp[3][3] = tmp[5][3];
			}
			else if (i == 2) {
				tmp[5][2] = tmp[4][2];
				tmp[5][3] = tmp[4][3];
			}
			else {
				tmp[4][2] = tmp0[0];
				tmp[4][3] = tmp0[1];
			}
		}
		break;
	case LEFT:
		//12 13 -> 32 33, 32 33 -> 52 53, 52 53 -> 42 43, 42 43 -> 12 13
		tmp0[0] = tmp[1][2];
		tmp0[1] = tmp[1][3];
		for (int i = 4; i > 0; i--) {
			if (i == 4) {
				tmp[1][2] = tmp[4][2];
				tmp[1][3] = tmp[4][3];
			}
			else if (i == 3) {
				tmp[4][2] = tmp[5][2];
				tmp[4][3] = tmp[5][3];
			}
			else if (i == 2) {
				tmp[5][2] = tmp[3][2];
				tmp[5][3] = tmp[3][3];
			}
			else {
				tmp[3][2] = tmp0[0];
				tmp[3][3] = tmp0[1];
			}
		}
		break;
	case CLOCK:
		//02 03 -> 40 42, 40 42 -> 21 20, 21 20 -> 33 31, 33 31 -> 12 13
		tmp0[0] = tmp[0][2];
		tmp0[1] = tmp[0][3];
		for (int i = 4; i > 0; i--) {
			if (i == 4) {
				tmp[0][2] = tmp[3][3];
				tmp[0][3] = tmp[3][1];
			}
			else if (i == 3) {
				tmp[3][1] = tmp[2][0];
				tmp[3][3] = tmp[2][1];
			}
			else if (i == 2) {
				tmp[2][0] = tmp[4][2];
				tmp[2][1] = tmp[4][0];
			}
			else {
				tmp[4][0] = tmp0[0];
				tmp[4][2] = tmp0[1];
			}
		}
		break;
	case UNCLOCK:
		//02 03 -> 40 42, 40 42 -> 21 20, 21 20 -> 33 31, 33 31 -> 12 13
		tmp0[0] = tmp[0][2];
		tmp0[1] = tmp[0][3];
		for (int i = 4; i > 0; i--) {
			if (i == 4) {
				tmp[0][2] = tmp[4][0];
				tmp[0][3] = tmp[4][2];
			}
			else if (i == 3) {
				tmp[4][0] = tmp[2][1];
				tmp[4][2] = tmp[2][0];
			}
			else if (i == 2) {
				tmp[2][0] = tmp[3][1];
				tmp[2][1] = tmp[3][3];
			}
			else {
				tmp[3][3] = tmp0[0];
				tmp[3][1] = tmp0[1];
			}
		}
		break;
	}
	if (check_color(tmp))
		suc = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> cube[i][j];
		}
	}

	for (int i = 0; i < 6; i++) {
		rotoate(i);
	}

	if (suc)
		cout << 1;
	else
		cout << 0;
	return 0;
}


// #include <stdio.h>

// int top[8]={5,6,17,18,21,22,13,14};
// int lft[8]={1,3,5,7,9,11,22,24};
// int sde[8]={3,4,17,19,10,9,16,14};

// int cls[25];

// int rot(int *line, int step)
// {
// 	int ca[25],i,j,ni;
// 	for(i = 0 ; i < 25 ; i++) ca[i] = cls[i];

// 	for(i = 0 ; i < 8; i++)
// 	{
// 		ni = i+step;
// 		if( ni < 0 )ni+=8;
// 		else if(ni >=8)ni-=8;
// 		ca[line[ni]]=cls[line[i]];
// 	}

//     for(i=1;i<24;i+=4)
// 	{
// 		for(j=i+1;j<=i+3;j++)if(ca[i]!=ca[j])return 0;
// 	}
// 	return 1;
// }
// int sol()
// {
// 	if(rot(top,2)) return 1;
// 	if(rot(top,-2)) return 1;
// 	if(rot(lft,2)) return 1;
// 	if(rot(lft,-2)) return 1;
// 	if(rot(sde,2)) return 1;
// 	if(rot(sde,-2)) return 1;

// 	return 0;
// }
// int main()
// {
//     int i=0,ret;
//     for(i=1;i<25;i++)
//     {
// 		scanf("%d",&cls[i]);
//     }

// 	ret = sol();
//     printf("%d\n",ret);
//     return 0;
// }
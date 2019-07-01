#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch1[101];
bool ch2[101][101];
int a[301][301];
ll cnt = 0;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
struct point {
        int x, y;
        point(int x, int y) {
                this->x = x;
                this->y = y;
        }
        point() {
        }
};
int t;
int n, m;


int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int* p = (int*)malloc(4);
        srand(*p);//현재시간을 이용해 매순간 다른 난수
        cnt = rand() % 10;//0,1,2
        if(cnt%2==1)
                cout<<"Korea";
        else
                cout<<"Yonsei";
        return 0;
}

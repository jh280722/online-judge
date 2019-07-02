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

int gcd(int a, int b) {
        int tmp;
        while(b>0) {
                tmp=a;
                a=b;
                b=tmp%b;
        }
        return a;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a,b,c,d;
        int g;
        cin>>a>>b>>c>>d;
        a=a*d+c*b;
        b*=d;
        g=gcd(a,b);
        a/=g;
        b/=g;
        cout<<a<<' '<<b;
        return 0;
}

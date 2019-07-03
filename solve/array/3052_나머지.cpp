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
#include <set>
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
        int a;
        set<int> s;
        for(int i=0; i<10; i++) {
                cin>>a;
                a%=42;
                s.insert(a);
        }
        cout<<s.size();
        return 0;
}

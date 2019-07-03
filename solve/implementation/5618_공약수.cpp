#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch1[101];
bool ch2[101][101];
int a1[101];
int a2[301][301];
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
int n, m, k;

int fgcd(int a, int b) {
        while (b != 0) {
                int r = a % b;
                a = b;
                b = r;
        }
        return a;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int g,gcd;
        cin>>n;
        for(int i=0; i<n; i++) {
                cin>>g;
                if (i == 0)
                        gcd = g;
                else
                        gcd = fgcd(gcd, g);
        }
        int arr[100000] = { 0 };
        for (int i = 1; i <= sqrt(gcd); i++)
        {
                if (gcd%i == 0)
                {
                        if (i*i == gcd)
                                arr[cnt++] = i;
                        else
                        {
                                arr[cnt++] = i;
                                arr[cnt++] = gcd / i;
                        }
                }
        }
        sort(arr, arr + cnt);
        for (int i = 0; i < cnt; i++)
                cout << arr[i] << endl;
        return 0;
}

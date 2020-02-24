#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
//#define scanf scanf_s
 
const int MAX = 109;
const int MOD = 998244353;
const int INF = 1000000001;
 
int M, A;
int moves[2][109];
pair<int, int> pos[2];
pair<int, int> npos[5] = { { 0,0 },{ -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
 
struct Bat
{
    int y, x, c, p;
    bool operator<(const Bat& b) const
    {
        return p > b.p;
    }
}bats[8];
 
void init()
{
    scanf("%d %d", &M, &A);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &moves[i][j]);
 
    for (int i = 0; i < A; ++i)
        scanf("%d %d %d %d", &bats[i].x, &bats[i].y, &bats[i].c, &bats[i].p);
 
    pos[0] = { 1,1 };
    pos[1] = { 10,10 };
}
 
int dist(pair<int, int>& pos, int bat_idx)
{
    return abs(pos.first - bats[bat_idx].y) + abs(pos.second - bats[bat_idx].x);
}
 
int getScore(int d = 0, int a = 0, int b = 0)
{
    for(; a < A; ++ a)
        if (dist(pos[0], a) <= bats[a].c)
            break;
    for (; b < A; ++b)
        if (dist(pos[1], b) <= bats[b].c)
            break;
 
    int x = a < A ? bats[a].p : 0;
    int y = b < A ? bats[b].p : 0;
 
    if (d == 0)
    {
        if (a != b)
            return x + y;
        else
            return x + getScore(d + 1, a + 1, b + 1);
    }
    else
        return max(x, y);
}
 
void solve()
{
    sort(bats, bats + A);
 
    int ret = getScore();
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            pos[j].first += npos[moves[j][i]].first;
            pos[j].second += npos[moves[j][i]].second;
        }
        ret += getScore();
    }
    printf("%d\n", ret);
}
 
int main(int argc, char** argv)
{
    int t = 1;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        init();
        printf("#%d ", i + 1);
        solve();
    }
    return 0;
}
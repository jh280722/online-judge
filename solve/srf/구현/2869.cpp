#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int a,b,v;
    cin>>a>>b>>v;
    int i=(v - b - 1)/(a-b) + 1;

    cout<<i;
    return 0;
}
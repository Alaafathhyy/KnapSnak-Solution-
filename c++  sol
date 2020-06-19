#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int const N=1e3*3;
int n;
int dp[N][N];
int val[N],cap[N],s;
int go(int i, int curcap) {
    if(curcap>s) return -1e9;
   if(i==n) return 0;

    int &ret=dp[i][curcap];
    if(~ret)
        return ret;
    return ret=max(go(i+1,curcap+cap[i])+val[i],go(i+1,curcap));

}

int main() {
    cin>>s>>n;
    memset(dp, -1, sizeof(dp));
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cap[i]>>val[i];
    }
    cout << go(0, 0);
}

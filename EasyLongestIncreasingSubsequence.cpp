/*
ELIS - Easy Longest Increasing Subsequence
*/
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int n;
int dp[20][20];

int go(int i, int prev) {
    if (i == n+1)
        return 0;
    int &ret = dp[i][prev];
    if (~ret)
        return ret;
   ret= go(i + 1, prev);
    if (vec[i] > vec[prev])
     ret= max(go(i + 1, i) + 1, ret);
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    vec.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    cout << go(1, 0);
}

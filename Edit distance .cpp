//EDIST - Edit distance
#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
int const N = 2e3 + 5;
int n1, n2;
int dp[N][N];
string s1, s2;

int go(int i, int j) {
    if (i == n1 || j == n2)
        return n1-i+n2-j;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    ret=1e9;
    if (s1[i] != s2[j]) {

        ret=min(ret,min(min(go(i + 1, j) + 1, go(i, j + 1) + 1), go(i + 1, j + 1) + 1));
    }
     else ret=min(ret,go(i+1,j+1));
    return ret;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        memset(dp,-1, sizeof(dp));
        cin >> s1 >> s2;
        n1 = s1.size();
        n2 = s2.size();
        cout << go(0, 0)<<endl;
    }

}

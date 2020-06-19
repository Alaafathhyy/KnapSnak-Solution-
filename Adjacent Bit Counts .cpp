// Adjacent Bit Counts SPOJ - GNYR09F
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
int const N = 1e3;

ll dp[105][200][3];
int n, k;


ll go(int i, int sum, int prev) {

    if (i == n) {
        if (sum == k)
            return 1;
        return 0;
    }
    ll &ret = dp[i][sum][prev];
    if (~ret)
        return ret;
    return ret = go(i + 1, sum+(0* prev), 0) + go(i + 1, sum + (1 * prev), 1);
}

int main() {

    int cases;
    cin >> cases;
    while (cases--) {
      //  memset(dp, -1, sizeof(dp));
        int num;
        cin >> num >> n >> k;
        ll ans = 0;
        cout << num << " ";
      //  ans += go(1, 0, 0);
        memset(dp, -1, sizeof(dp));
        ans += go(0, 0, 0);
        cout << ans << endl;
    }


}

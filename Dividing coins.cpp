//E - Dividing coins UVA - 562 
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
int const N = 50000;
int arr[105];
int n;

ll dp[105][N];
ll go(int i, ll sum1) {

    if (i == n) {
        return abs(sum1);
    }
    ll &ret=dp[i][sum1];
    if(~ret)
        return ret;

    return ret =min(go(i+1,sum1+arr[i]),go(i+1,sum1-arr[i]));
}

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
    memset(dp,-1, sizeof(dp));
        cin >> n;
        ll sum1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum1 += arr[i];
        }
        cout << go(0, 0) << endl;
    }
}

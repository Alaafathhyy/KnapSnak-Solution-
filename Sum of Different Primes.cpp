
//UVA-1213 Sum of Different Primes 
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long
#include <bits/stdc++.h>

using namespace std;
int const N = 2 * 1e3;
vector<ll> primes;
bool arr[N];

void valid() {
    memset(arr, 1, sizeof(arr));
    for (ll i = 2; i <N; i++) {
        if (arr[i]) {
            for (ll j = i * i; j < N; j += i) {
                arr[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int n, k;
int dp[400][N][15];

ll go(ll i, ll cursum, ll cnt) {
    if (i == primes.size()) {
        if (cnt == k && cursum == n) return 1;
        return 0;
    }
    int &ret = dp[i][cursum][cnt];
    if (~ret)
        return ret;
    ll ans = 0;
    if (primes[i] + cursum <= n && cnt + 1 <= k) ans += go(i + 1, cursum + primes[i], cnt + 1);
    return ret = ans += go(i + 1, cursum, cnt);
}


int main() {
    valid();
   // input;
    //cout<<primes.size();
    while (1) {
        cin >> n >> k;
        if (k == 0 && n == 0)
            return  0;
        memset(dp, -1, sizeof(dp));

        cout << go(0, 0, 0) << endl;
    }
}

// [UVA-10616]
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
int const N = 100;
int arr[205], m, d;
int n;
ll dp[205][15][205];

ll alaa(int i, ll cnt, ll mod) {

    if (mod == 0 && cnt == m)
        return 1;
    if(cnt == m && mod != 0)
        return 0;
    if (i == n)return 0;
    ll &ret = dp[i][cnt][mod];
    if (~ret)
        return ret;
    return ret = alaa(i + 1, cnt + 1, (arr[i] % d + mod) % d) + alaa(i + 1, cnt, mod);

}


int main() {
    int q;
    int cnt = 0;
    while (true) {
        memset(arr, 0, sizeof(arr));
        cin >> n >> q;
        cnt++;
        if (n == 0 && q == 0)
            return 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << "SET " << cnt << ":" << endl;
        for (int j = 1; j <= q; ++j) {
            memset(dp, -1, sizeof(dp));
            cin >> d >> m;
            cout << "QUERY " << j << ": " << alaa(0, 0, 0) << endl;

        }
    }


}

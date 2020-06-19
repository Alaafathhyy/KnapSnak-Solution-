//Trouble of 13-Dots UVA - 10819
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
int const N = 100;

int pur, n;
int pri[100], fav[100];

int dp[102][100005][2];

int go(int i, int cursum, bool flag) {
    int ans = 0;
    if (cursum == pur)
        return 0;
    if (i == n)
        return 0;
    int &ret = dp[i][cursum][flag];
    if (~ret)
        return ret;

    if(cursum+pri[i]>2000&&flag==false)
    {
        if(cursum+pri[i]-200<=pur)
     ans=  go(i+1,cursum+(pri[i]-200),true)+fav[i];
    }
    else if(cursum+pri[i]<=pur) ans=  go(i+1,cursum+pri[i],flag)+fav[i];
    ans=max(ans,go(i+1,cursum,flag));
    return ret = ans;

}

int main() {
    while (cin >> pur >> n) {
        memset(pri, 0, sizeof(pri));
        memset(fav, 0, sizeof(fav));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> pri[i] >> fav[i];
if(pur>2000)
    pur+=200;
        cout << go(0, 0,pur>2000) << endl;

    }

}

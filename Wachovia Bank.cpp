// Wachovia Bank SPOJ
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
int const N = 100;
int siz,n;
int BagsWight[50+5];
int BagsValue[50+5];
int dp[1005][55];
int go(int curwig,int i)
{
   int ans=0;
    if(i==n)
        return 0;
    int &ret= dp[curwig][i];
    if(~ret)
        return ret;
    if(curwig+BagsWight[i]<=siz)
        ans=go(curwig+BagsWight[i],i+1)+BagsValue[i];
    ans=max(go(curwig,i+1),ans);
    ret=ans;
    return ret;

}
int main() {
    int cases;
    cin>>cases;
    while (cases--)
    {
        memset(BagsValue,0, sizeof(BagsValue));
        memset(BagsWight,0, sizeof(BagsWight));
        memset(dp,-1, sizeof(dp));
        cin>>siz>>n;
        for(int i=0;i<n;i++)
            cin>>BagsWight[i]>>BagsValue[i];
        cout<<"Hey stupid robber, you can get "<<go(0,0)<<"."<<endl;
    }


}

// Scuba diver SPOJ - SCUBADIV 
#define MOD 1000000007
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll long long

#include <bits/stdc++.h>

using namespace std;
int const N = 1000;
int nit,oxg;
ll arro[N],arrn[N],arrw[N];
int n;
ll dp[N][100][100];
ll go(int i,ll curo,ll curn)
{
    ll ans=1e9;
   if(!curo&&!curn)return 0;
   if(i==n)return 1e9;
   ll &ret=dp[i][curo][curn];
   if(~ret)
       return ret;
   ans=go(i+1,max(curo-arro[i],0*1ll),max(curn-arrn[i],0*1ll))+arrw[i];
    ret=min(ans,go(i+1,curo,curn));
    return ret;
}

int main() {
int cases;
cin>>cases;
while(cases--)
{
    cin>>oxg>>nit;
    cin>>n;
    memset(dp,-1, sizeof(dp));
    for(int i=0;i<n;i++)cin>>arro[i]>>arrn[i]>>arrw[i];
    cout<<go(0,oxg,nit)<<endl;

}
}

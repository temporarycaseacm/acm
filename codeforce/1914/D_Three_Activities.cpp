#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector a(3,vector(n,0));
    forn(i,0,3){
        forn(j,0,n){
            cin>>a[i][j];
        }
    }
    vector dp(8,0LL);
    forn(i,0,n){
        vector<ll> ndp(8);
        ndp.assign(all(dp));
        forn(j,0,8){
            if((j&1)==0){
                ndp[j|1] = max(ndp[j|1],dp[j] + a[0][i]);
            } 
           
        }
        forn(j,0,8){
            if(((j>>1)&1) == 0) ndp[j|2] = max(ndp[j|2],dp[j] + a[1][i]);
        }
        forn(j,0,8){
            if(((j>>2)&1) == 0) ndp[j|4] = max(ndp[j|4],dp[j] + a[2][i]);
        }
        dp = ndp;
    }
    cout<<dp[7]<<"\n";
    
    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}
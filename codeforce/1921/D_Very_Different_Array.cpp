#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    forn(i,0,n) cin>>a[i];
    forn(i,0,m) cin>>b[i];
    sort(all(a));sort(all(b));
    vector pre_sum1(n+1,0LL),pre_sum2(m+1,0LL);
    forn(i,1,n+1){
        pre_sum1[i] = pre_sum1[i-1] + a[i-1];
    }
    forn(i,1,m+1) pre_sum2[i] = pre_sum2[i-1] + b[i-1];
    ll ans = pre_sum1[n] - pre_sum2[n];
    forn(i,0,n){
        if(a[i] < b[m-1-i]){
            ll t = pre_sum2[m] - pre_sum2[m-i-1] - pre_sum1[i+1] + pre_sum1[n] - pre_sum1[i+1] - pre_sum2[n - i - 1];
            ans = max(ans,t);
        }
        
    }

    cout<<ans<<"\n";

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
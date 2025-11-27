#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector a(n,0LL);
    forn(i,0,n) cin>>a[i];
    sort(all(a));
    // w1 > w2 > w3  => w1 - w3
    // w1 < w2 > w3 => 2*w2 - (w1 + w3)
    // w1 > w2 < w3 => (w1 + w3) - 2*w2
    ll t1 = a[n-1] - a[0],t2 = 0LL,t3 = 0LL;
    forn(i,0,n-2){
        t2 = max(2*a[i+2] - a[0] - a[i+1],t2);
        t3 = max(a[n-1] + a[i+1] - 2 * a[i],t3);
    }
    ll ans = max(t1,t2);
    ans = max(ans,t3);
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
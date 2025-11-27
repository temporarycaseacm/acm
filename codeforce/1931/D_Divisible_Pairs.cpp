#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,x,y;cin>>n>>x>>y;
    vector a(n,0);
    forn(i,0,n) cin>>a[i];
    ll ans = 0LL;
    map<int,map<int,int>> cnt;
    forn(i,0,n){
        int t1 = a[i]%x;
        int t2 = a[i]%y;
        ans += cnt[(x-t1)%x][t2];
        cnt[t1][t2] += 1;
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
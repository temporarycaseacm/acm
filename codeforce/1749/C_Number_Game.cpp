#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n; cin>>n;
    vector a(n,0);
    forn(i,0,n) cin>>a[i];
    int ans = 0;
    for(int k=1;k<=n;k++){
        int k2 = n - k + 1;
        multiset<int> orl(a.begin(), a.end());
        forn(i,0,k){
            auto it = orl.upper_bound(k - i);
            if(it == orl.begin()) break;
            orl.erase(--it);
            if(!orl.empty()){
                int t = *orl.begin();
                orl.erase(orl.begin());
                orl.insert(t + k - i);
            }
        }
        if(orl.size() == n - k) ans = k;
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